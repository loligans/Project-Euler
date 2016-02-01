#include <stdio.h>
#include <stdlib.h>
#define SIEVE_SIZE 250000
#define PRIME_INDEX 10001
#define NOT_PRIME 0

long findNthPrime(int, long*);
long*generateSieve();

int main(int argc, char* argv[])
{
	printf("Locating the 10,001st prime number\n");
	long* sieve = generateSieve();
	long nthPrime = findNthPrime(PRIME_INDEX, sieve);
	printf("The 10,001st prime number is %lu\n", nthPrime);
	return nthPrime;
}

long* generateSieve()
{
	printf("Generating Sieve of size %d\n", SIEVE_SIZE);
	long* sieve = malloc(sizeof(long) * SIEVE_SIZE);
	//To make things less complicated we start the sieve at 2 (The first prime)
	for(long a=2;a<=SIEVE_SIZE;++a)
		sieve[a] = a;
	return sieve;
}

//Using the Sieve of Eratosthenes method
long findNthPrime(int primeIndexToFind, long* sieve)
{
	//Allocate an array up to the size of the highest prime we want
	long* primesArray = malloc(sizeof(long) * PRIME_INDEX);
	long primesFound = 0;

	//Loop through the Sieve and find all non-primes 
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

		//Make sure we do not access invalid memory,
		//by storing another prime beyond the index we want
		if(primeIndexToFind == primesFound)
			break;
	}//End For
	//Arrays start at 0 so we subtract the offset to get out value
	return primesArray[PRIME_INDEX - 1];
}