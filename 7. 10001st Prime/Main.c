#include <stdio.h>

int main(int argc, char* argv[])
{
	printf("Locating the 10,001st prime number\n");
	return 1;
}

long findNthPrime(int primeToFind)
{
	int currentPrimeIndex = 0;
	long* primesFound = malloc(sizeof(long) * primeToFind);
	long nextPrimeToCheck = 2;
	while(currentPrimeIndex < primeToFind)
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
}