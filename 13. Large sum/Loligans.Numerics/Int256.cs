using System.Numerics;
using System;
using System.Globalization;

namespace Loligans.Numerics
{
    public struct Int256
    {
        private static readonly Int256 _maxValue = (Int256)(((UInt256)1 << 255) - 1);
        private static readonly Int256 _minValue = (Int256)((UInt256) 1 << 255);
        public static Int256 MaxValue { get { return _maxValue; } }
        public static Int256 MinValue { get { return _minValue; } }

        private UInt256 v;
        public ulong S0 { get { return v.S0; } }
        public ulong S1 { get { return v.S1; } }
        public ulong S2 { get { return v.S2; } }
        public ulong S3 { get { return v.S3; } }
        public bool IsNegative { get { return v.S3 > long.MaxValue; } }

        public static bool TryParse(string value, out Int256 result)
        {
            return TryParse(value, NumberStyles.Integer, NumberFormatInfo.CurrentInfo, out result);
        }

        public static bool TryParse(string value, NumberStyles style, IFormatProvider format, out Int256 result)
        {
            if (!BigInteger.TryParse(value, style, format, out var parsedValue))
            {
                UInt256.Create(out result.v, 0, 0, 0, 0);
                return false;
            }

            UInt256.Create(out result.v, parsedValue);
            return true;
        }

        public static explicit operator Int256(UInt256 a)
        {
            Int256 c = new();
            c.v = a;
            return c;
        }

        public static explicit operator UInt256(Int256 a)
        {
            return a.v;
        }

        public static Int256 operator -(Int256 a, long b)
        {
            Int256 c;
            if (b < 0)
                UInt256.Add(out c.v, ref a.v, (ulong)-b);
            else
                UInt256.Subtract(out c.v, ref a.v, (ulong)b);
            return c;
        }

        public static Int256 operator +(Int256 a, long b)
        {
            Int256 c;
            if (b < 0)
                UInt256.Subtract(out c.v, ref a.v, (ulong)-b);
            else
                UInt256.Add(out c.v, ref a.v, (ulong)b);
            return c;
        }

        public static Int256 operator +(Int256 a, Int256 b)
        {
            Int256 c;
            UInt256.Add(out c.v, ref a.v, ref b.v);
            return c;
        }

        public static explicit operator BigInteger(Int256 a)
        {
            if (a.IsNegative)
            {
                UInt256.Negate(out var c, ref a.v);
                return -(BigInteger)c;
            }
            return (BigInteger)a.v;
        }

        public override string ToString()
        {
            return ((BigInteger)this).ToString();
        }
    }
}
