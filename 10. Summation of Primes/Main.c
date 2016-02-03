#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIEVE_SIZE 2000000
#define NOT_PRIME 0

long findSumOfPrimes_limited(long*, long);
long*generateSieve();

int main(int argc, char*argv[])
{
	clock_t start, end;
	double computationTime;
	printf("Locating the sum of all primes below 2-million\n");
	printf("Generating Sieve\n");
	start = clock();
	long* sieve = generateSieve();
	printf("Locating nthPrime\n");
	long sumUpToNthPrime = findSumOfPrimes_limited(sieve, SIEVE_SIZE);
	end = clock();
	computationTime = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Sum up to the nth prime is %ld in %f\n", sumUpToNthPrime, computationTime);
	return 1;
}

long* generateSieve()
{
	long* sieve = malloc(sizeof(long) * SIEVE_SIZE);
	//To make things less complicated we start the sieve at 2 (The first prime)
	for(long a=2;a<=SIEVE_SIZE;++a)
		sieve[a] = a;
	return sieve;
}

//Using the Sieve of Eratosthenes method
long findSumOfPrimes_limited(long* sieve, long maxValue)
{
	//Allocate an array up to the size of the highest prime we want
	long* primesArray = malloc(sizeof(long) * (maxValue / 2));
	long primesFound = 0;

	//Loop through the Sieve and find all non-primes starting at  the first prime
	for(long a=2;a<SIEVE_SIZE;++a)
	{
		//Skip this index if its value is NOT_PRIME
		if(sieve[a] == NOT_PRIME)
			continue;
		else 
		//We have come up to the next non-zero value to test
		{
			//Remove all multiples frome the current value of a
			for(long b=a+a; b<SIEVE_SIZE;b+=a)
			{
				if(sieve[b] == NOT_PRIME)
					continue;
				else if(sieve[b] % b == 0)
					sieve[b] = NOT_PRIME;
			}//End For
			//Save the prime in our primes array
			primesArray[primesFound] = a;
			primesFound++;
		}//End Else
	}//End For
	//Add all the primes below maxValue
	unsigned long result = 0;
	for(long a = 0; a < primesFound; ++a)
		result += primesArray[a];
	return result;
}
