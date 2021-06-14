using System;
using System.Numerics;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Loligans.Numerics.Tests
{
    [TestClass]
    public class Int256Tests
    {
        [TestMethod]
        public void ShouldParseHugeWholeNumbersCorrectly()
        {
            var maxValue = "57896044618658097711785492504343953926634992332820282019728792003956564819967";
            var parsed = Int256.TryParse(maxValue.ToString(), out var maxInt256);
            Assert.IsTrue(parsed);
            Assert.AreEqual(maxValue, maxInt256.ToString());

            var minValue = "-57896044618658097711785492504343953926634992332820282019728792003956564819968";
            parsed = Int256.TryParse(minValue, out var minInt256);
            Assert.IsTrue(parsed);
            Assert.AreEqual(minValue, minInt256.ToString());
        }

        [TestMethod]
        public void ShouldAddHugeSignedWholeNumbersCorrectly()
        {
            var someValueInBetweenMinMax = "7";
            var parsed = Int256.TryParse(someValueInBetweenMinMax, out var seven);
            var expectedResult = "8";
            Assert.IsTrue(parsed);
            Assert.AreEqual(expectedResult, (seven + 1).ToString());
        }

        [TestMethod]
        public void ShouldSubtractHugeSignedWholeNumbersCorrectly()
        {
            var someValueInBetweenMinMax = "-12";
            var parsed = Int256.TryParse(someValueInBetweenMinMax, out var twelve);
            var expectedResult = "-16";
            Assert.IsTrue(parsed);
            Assert.AreEqual(expectedResult, (twelve - 4).ToString());
        }
    }
}
