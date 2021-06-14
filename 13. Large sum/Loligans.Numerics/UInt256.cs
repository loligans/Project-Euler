

using System;
using System.Globalization;
using System.Net.Mail;
using System.Numerics;
using System.Runtime.CompilerServices;
using System.Xml.Serialization;

namespace Loligans.Numerics
{
    public struct UInt256
    {
        private ulong s0;
        private ulong s1;
        private ulong s2;
        private ulong s3;

        public ulong S0 { get { return s0; } }
        public ulong S1 { get { return s1; } }
        public ulong S2 { get { return s2; } }
        public ulong S3 { get { return s3; } }

        public static bool TryParse(string value, out UInt256 result)
        {
            return TryParse(value, NumberStyles.Integer, NumberFormatInfo.CurrentInfo, out result);
        }

        public static bool TryParse(string value, NumberStyles style, IFormatProvider format, out UInt256 result)
        {
            if (!BigInteger.TryParse(value, style, format, out var parsedValue))
            {
                UInt256.Create(out result, 0, 0, 0, 0);
                return false;
            }

            UInt256.Create(out result, parsedValue);
            return true;
        }

        public static void Create(out UInt256 result, ulong s0, ulong s1, ulong s2, ulong s3)
        {
            result.s0 = s0;
            result.s1 = s1;
            result.s2 = s2;
            result.s3 = s3;
        }

        public static void Create(out UInt256 result, BigInteger a)
        {
            var sign = a.Sign;
            if (sign == -1) { a = -a; }

            result.s0 = (ulong)(a & ulong.MaxValue);
            result.s1 = (ulong)(a >> 64 & ulong.MaxValue);
            result.s2 = (ulong)(a >> 128 & ulong.MaxValue);
            result.s3 = (ulong)(a >> 192);

            if (sign == -1) { Negate(ref result); }
        }

        public static explicit operator UInt256(int a)
        {
            Create(out var result, (ulong)a, 0, 0, 0);
            return result;
        }

        public static explicit operator UInt256(BigInteger a)
        {
            Create(out var result, a);
            return result;
        }

        public static explicit operator BigInteger(UInt256 a)
        {
            BigInteger result = default;
            if (a.s3 != 0)
            {
                result = (BigInteger)a.s3 << 192;
            }
            if (a.s2 != 0)
            {
                result |= (BigInteger)a.s2 << 128;
            }
            if (a.s1 != 0)
            {
                result |= (BigInteger)a.s1 << 64;
            }
            return result | (BigInteger)a.s0;
        }

        public static UInt256 operator <<(UInt256 a, int b)
        {
            LeftShift(out var result, ref a, b);
            return result;
        }

        public static UInt256 operator +(UInt256 a, UInt256 b)
        {
            Add(out var result, ref a, ref b);
            return result;
        }

        public static UInt256 operator -(UInt256 a, ulong b)
        {
            Subtract(out var c, ref a, b);
            return c;
        }

        public static UInt256 operator +(UInt256 a, ulong b)
        {
            Add(out var c, ref a, b);
            return c;
        }

        public static void Negate(out UInt256 c, ref UInt256 a)
        {
            c.s0 = 0 - a.s0;
            c.s1 = 0 - a.s1;
            c.s2 = 0 - a.s2;
            c.s3 = 0 - a.s3;
            if (a.s0 > 0) { c.s1--; }
            if (a.s1 > 0) { c.s2--; }
            if (a.s2 > 0) { c.s3--; }
        }

        public static void Negate(ref UInt256 result)
        {
            var s0 = result.s0;
            var s1 = result.s1;
            var s2 = result.s2;
            result.s0 = 0 - s0;
            result.s1 = 0 - s1;
            result.s2 = 0 - s2;
            result.s3 = 0 - result.s3;
            if (s0 > 0)
            {
                result.s1--;
                result.s2--;
                result.s3--;
            }
            else if (s1 > 0)
            {
                result.s2--;
                result.s3--;
            }
            else if (s2 > 0)
            {
                result.s3--;
            }
        }

        private static ulong LeftShift192(out UInt256 result, ref UInt256 a, int d)
        {
            if (d == 0)
            {
                result = a;
                return 0;
            }
            var dneg = 192 - d;
            result.s3 = a.s3 << d | a.s2 >> dneg;
            result.s2 = a.s2 << d | a.s1 >> dneg;
            result.s1 = a.s1 << d | a.s0 >> dneg;
            result.s0 = a.s0 << d;
            return a.s3 >> dneg;
        }

        private static void LeftShift(out UInt256 result, ref UInt256 a, int b)
        {
            if (b < 192)
            {
                LeftShift192(out result, ref a, b);
            }
            else if (b == 192)
            {
                result.s0 = 0;
                result.s1 = 0;
                result.s2 = 0;
                result.s3 = a.s2;
            }
            else
            {
                result.s0 = 0;
                result.s1 = 0;
                result.s2 = 0;
                result.s3 = a.s0 << (b - 192);
            }
        }

        public static void Add(out UInt256 result, ref UInt256 a, ref UInt256 b)
        {
            result = new();
            var sum = a.s0 + b.s0;
            if (sum < a.s0 && sum < b.s0) { result.s1++; }
            result.s0 = sum;

            sum = a.s1 + b.s1 + result.s1;
            if (sum < a.s1 && sum < b.s1) { result.s2++; }
            result.s1 = sum;

            sum = a.s2 + b.s2 + result.s2;
            if (sum < a.s2 && sum < b.s2) { result.s3++; }
            result.s2 = sum;

            sum = a.s3 + b.s3 + result.s3;
            if (sum < a.s3 && sum < b.s3) { throw new OverflowException(); }
            result.s3 = sum;
        }

        public static void Add(out UInt256 result, ref UInt256 a, ulong b)
        {
            result.s0 = a.s0 + b;
            result.s1 = a.s1;
            result.s2 = a.s2;
            result.s3 = a.s3;
            if (result.s0 < a.s0)
                result.s1++;
            if (result.s1 < a.s1)
                result.s2++;
            if (result.s2 < a.s2)
                result.s3++;
        }

        public static void Subtract(out UInt256 result, ref UInt256 a, ulong b)
        {
            result.s0 = a.s0 - b;
            result.s1 = a.s1;
            result.s2 = a.s2;
            result.s3 = a.s3;
            if (result.s0 > a.s0)
                result.s1--;
            if (result.s1 > a.s1)
                result.s2--;
            if (result.s2 > a.s2)
                result.s3--;
        }

        public override string ToString()
        {
            return ((BigInteger)this).ToString();
        }
    }
}