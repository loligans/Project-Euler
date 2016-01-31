#include <stdio.h>
#include <stdlib.h>
#define SIEVE_SIZE 120
#define bool int
#define FALSE 0
#define TRUE !FALSE

long findNthPrime(int, long*);
long*generateSieve();

int main(int argc, char* argv[])
{
	printf("Locating the 10,001st prime number\n");
	long* sieve = generateSieve();
	findNthPrime(100001, sieve);
	printf("\n");
	return 1;
}

long* generateSieve()
{
	printf("Generating Sieve of size %d\n", SIEVE_SIZE);
	long* sieve = malloc(sizeof(long) * SIEVE_SIZE);
	for(int a=0;a<SIEVE_SIZE - 1;++a)
		sieve[a] = a+2;
	return sieve;
}

//Using the Sieve of Eratosthenes method
long findNthPrime(int primeIndexToFind, long* sieve)
{

	long primeFound = -1;
	for(int a=0;a<SIEVE_SIZE;++a)
	{
		if(sieve[a] == 0)
			continue;
	}


	return primeFound;




































	
	
	// long* primesFound = malloc(sizeof(long) * primeToFind);
	// while(currentPrimeIndex < primeToFind)
	// {
	// 	if (value % nextPrimeToCheck == 0)
	// 	{
	// 		//Check if we found a new Max Prime
	// 		largestPrimeFound = largestPrimeFound < nextPrimeToCheck ? nextPrimeToCheck : largestPrimeFound;
	// 		//Set the new value of the Prime we are checking
	// 		value /= nextPrimeToCheck;
	// 		totalCalculation *= nextPrimeToCheck;
	// 		//Check if we have found the largest prime
	// 		printf("MPP=%lg : nextPrimeToCheck=%lu : largestPrimeFound=%lu : totalCalculation=%lu\n",
	// 				MPP, 	  nextPrimeToCheck, 	 largestPrimeFound,		 totalCalculation);
			
	// 		if (value == 1)
	// 			return largestPrimeFound;
			
	// 		//Adds the next value into nextPrimeToCheck
	// 		nextPrimeToCheck = 2;
	// 	}//End If
	// 	else
	// 		nextPrimeToCheck += nextPrimeToCheck % 2 ? 2 : 1;
	// }//End While
}