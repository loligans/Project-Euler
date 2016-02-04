#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIEVE_SIZE 250000
#define PRIME_INDEX 10001
#define NOT_PRIME 0

long findNthPrime(int, long*);
long*generateSieve();

int main(int argc, char* argv[])
{
	clock_t begin, end;
	double time_spent;
	printf("Locating the 10,001st prime number\n");
	printf("Generating Sieve of size %d\n", SIEVE_SIZE);

	begin = clock();
	long* sieve = generateSieve();
	end = clock();
	double time_Spent_Generating = (double) (end - begin) / CLOCKS_PER_SEC;
	begin = clock();
	long nthPrime = findNthPrime(PRIME_INDEX, sieve);
	end = clock();
	double time_Spent_Locating = (double) (end - begin) / CLOCKS_PER_SEC;
	
	printf("It took %f seconds to generate the sieve\n", time_Spent_Generating);
	printf("It took %f seconds to locate the 10,001st prime\n", time_Spent_Locating);
	printf("The total CPU time is %f\n", time_Spent_Generating + time_Spent_Locating);
	printf("The 10,001st prime number is %lu\n", nthPrime);
	return nthPrime;
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