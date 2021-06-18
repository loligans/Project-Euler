using System;
using System.Collections.Generic;

namespace Loligans.CollatzSequence
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Computing...");
            new CollatzSequence().FindLargestSequence(1000000);
        }
    }

    public class CollatzSequence
    {
        private long TotalCacheHits { get; set; }
        private long TotalComputes { get; set; }

        public int FindLargestSequence(int limit)
        {
            var chains = new Dictionary<long, int>();
            var largestChainN = 0;
            var largestChain = 0;

            for (var i = 1; i < limit; i++)
            {
                var exists = chains.TryGetValue(i, out var computedCount);
                if (exists)
                {
                    TotalCacheHits += computedCount;
                    if (largestChain < computedCount)
                    {
                        largestChainN = i;
                        largestChain = computedCount;
                    }
                    continue;
                }

                var count = Compute(i, 0, chains);
                if (largestChain < count)
                {
                    largestChainN = i;
                    largestChain = count;
                }
            }

            Console.WriteLine($"The largest chain is: {largestChainN} at {largestChain}");
            Console.WriteLine($"Total Computes: {TotalComputes}");
            Console.WriteLine($"Total Computes Saved: {TotalCacheHits}");
            return largestChainN;
        }

        int Compute(long n, int count, Dictionary<long, int> chains)
        {
            if (n == 1) { return count; }
            if (chains.TryGetValue(n, out var computedCount))
            {
                TotalCacheHits += computedCount;
                return computedCount + count;
            }

            int nCount;
            if ((n & 1) == 1) {
                TotalComputes++;
                var next = 3 * n + 1;
                nCount = Compute(next, count + 1, chains);
                chains.Add(n, nCount - count);
            }
            else {
                TotalComputes++;
                var next = n / 2;
                nCount = Compute(next, count + 1, chains);
                chains.Add(n, nCount - count);
            }

            return nCount;
        }
    }
}
