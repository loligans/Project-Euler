using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Loligans.Numerics.Tests
{
    [TestClass]
    public class UInt256Tests
    {
        [TestMethod]
        public void ShouldParseHugeUnsignedWholeNumbersCorrectly()
        {
            var minValue = "0";
            var parsed = UInt256.TryParse(minValue, out var minUInt256);
            Assert.IsTrue(parsed);
            Assert.AreEqual(minUInt256.ToString(), minValue);

            var someValueInBetweenMinMax = "7";
            parsed = UInt256.TryParse(someValueInBetweenMinMax, out var someUInt256);
            Assert.IsTrue(parsed);
            Assert.AreEqual(someValueInBetweenMinMax, someUInt256.ToString());

            var maxValue = "115792089237316195423570985008687907853269984665640564039457584007913129639935";
            parsed = UInt256.TryParse(maxValue, out var maxUInt256);
            Assert.IsTrue(parsed);
            Assert.AreEqual(maxValue, maxUInt256.ToString());
        }

        [TestMethod]
        public void ShouldAddHugeUnsignedWholeNumbersCorrectly()
        {
            var someValueInBetweenMinMax = "7";
            var parsed = UInt256.TryParse(someValueInBetweenMinMax, out var someUInt256);
            var expectedResult = "8";
            Assert.AreEqual(expectedResult, (someUInt256 + 1).ToString());

            var maxValue = "115792089237316195423570985008687907853269984665640564039457584007913129639935";
            parsed = UInt256.TryParse(maxValue, out var maxUInt256);
            Assert.ThrowsException<OverflowException>(() => { var overflow = maxUInt256 + 1UL; });
        }

        [TestMethod]
        public void ShouldSubtractHugeUnsignedWholeNumbersCorrectly()
        {
            var minValue = "0";
            var parsed = UInt256.TryParse(minValue, out var minUInt256);
            Assert.ThrowsException<OverflowException>(() => { var overflow = minUInt256 - 1UL; });

            var someValueInBetweenMinMax = "7";
            parsed = UInt256.TryParse(someValueInBetweenMinMax, out var someUInt256);
            var expectedResult = "6";
            Assert.AreEqual(expectedResult, (someUInt256 - 1).ToString());
        }
    }
}