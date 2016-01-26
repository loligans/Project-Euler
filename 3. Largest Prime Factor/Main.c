#include <stdio.h>
#include <math.h>
#define FALSE 0
#define TRUE !FALSE
long findLargestPrime(long);

int main(int argc, char*argv[])
{
	double value = 600851475143;
	printf("Size of long double is: %lu\n", sizeof(long double));
	printf("Searching for Largest prime in %lg\n", value);
	long maxPrime = findLargestPrime(value);
	if(maxPrime == -1)
		printf("Error processing the prime\n");
	else
		printf("The largest prime calculated was %lu\n", maxPrime);
	return 0;
}

long findLargestPrime(long value)
{
	//Max Possible Prime
	double MPP = sqrtl(value);

	long largestPrimeFound = 1;
	long nextPrimeToCheck = 2;

	//when multiplied it should add up to the original value
	long totalCalculation = 1;
	printf("Largest Possible Prime is %lg\n", MPP);
	while(TRUE)
	{
		if (value % nextPrimeToCheck == 0)
		{
			//Check if we found a new Max Prime
			largestPrimeFound = largestPrimeFound < nextPrimeToCheck ? nextPrimeToCheck : largestPrimeFound;
			//Set the new value of the Prime we are checking
			value /= nextPrimeToCheck;
			totalCalculation *= nextPrimeToCheck;
			//Check if we have found the largest prime
			printf("MPP=%lg : nextPrimeToCheck=%lu : largestPrimeFound=%lu : totalCalculation=%lu\n",
					MPP, 	  nextPrimeToCheck, 	 largestPrimeFound,		 totalCalculation);
			
			if (value == 1)
				return largestPrimeFound;
			
			//Adds the next value into nextPrimeToCheck
			nextPrimeToCheck = 2;
		}//End If
		else
			nextPrimeToCheck += nextPrimeToCheck % 2 ? 2 : 1;
	}//End While
	return -1;
}