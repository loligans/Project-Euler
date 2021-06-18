# Longest Collatz Sequence
"_The Collatz conjecture is a conjecture in mathematics that concerns sequences defined as follows: start with any positive integer n. Then each term is obtained from the previous term as follows: if the previous term is even, the next term is one half of the previous term. If the previous term is odd, the next term is 3 times the previous term plus 1. The conjecture is that no matter what value of n, the sequence will always reach 1._" - [Source](https://en.wikipedia.org/wiki/Collatz_conjecture)

![](https://wikimedia.org/api/rest_v1/media/math/render/svg/ec22031bdc2a1ab2e4effe47ae75a836e7dea459)

## Problem
What starting number, under one million, produces the longest chain?

**Spoiler Alert! Everything below here contains information about potential solutions to this problem.**

## Thoughts and Potential Solutions
When I first approached this problem I thought to myself well we could simply try every value from 1 -> 1,000,000. However, before coming to any sort of decision I started doing some digging to understand the Collatz Sequence. I found a number of interesting qualities about it.

So the first notable thing is that the Collatz Sequence has a tree like pattern. What I mean by that is as you increase n, you get a branch to the right if n is odd, a branch to the left if n is even, and a longer branch if n is even multiple times in a row.

![](https://i.stack.imgur.com/Vtmp1.jpg)

The other notable thing is that we can skip a step by dividing (3n + 1) / 2.

### Why does all this matter?
Well by understanding the problem we can more appropriately apply better solutions i.e. using an optimal data structure that minimizes the amount of work we have to do. If we structure the application correctly we can avoid wasted computation on chains that we have already computed.

## Okay Ethan, what should we do then?
So our primary goal is to find the largest chain with a starting number under 1 million. Our secondary goal is to find a way to do it without having to recalculate values we have already computed.

### Structuring the application 'correctly'
So we're going to be looping through values of n no matter what. We should try to cache our Collatz computations as we perform them. I felt like an optimal way to do that is by storing `n` in a `Dictionary` with the value set to the number of "operations" in a chain starting from that `n`.

Storing computation results in a `Dictionary` was absolutely helpful. _I'm going to refer to the `Dictionary` as a cache going forward since that's how I'm using it_. However, it was still wasteful because we only added values of `n` into the dictionary. So instead I chose to cache every operation performed on `n`. This showed me that the Collatz Sequence felt like a good candidate for recursion. So recursively down the rabbit hole I went computing `n` all the way till we hit either `1` or we hit the cache (saving us sweet sweet CPU cycles).

Here are some fun numbers:
- Total Computations: `2,168,610`
- Total Cache Hits: `129,265,662`
- Average Runtime: `291ms`

### Problems along the way
I ran into an issue around where n ≈ 113,000 and due to the large numbers the `int` was overflowing making it go negative. So the recursion got bad vibes and ended up stack overflowing. The obvious fix was to switch the data type to `long` instead (or `Int256` if we're feeling silly 😉).

## Summary, Reference, and Sources
This problem was a pleasent brain stretch. It wasn't terribly difficult and in fact I spent more time writing this README and learning about the Collatz Sequence than I did actually coding the solution.

So [this](https://www.youtube.com/watch?v=5mFpVDpKX70) Numberphile video was a great resource on understanding the fundemental nature of the problem. Of course the [Wikipedia](https://en.wikipedia.org/wiki/Collatz_conjecture) page was super helpful too!

Thank you for reading this! I hope you enjoyed it and maybe even learned something new! Let me know if you liked it, my email is Ethan.Lindemann@outlook.com!