#include <stdio.h>
#include <stdlib.h>
#define bool int
#define FALSE 0
#define TRUE !FALSE

long int findDivisibility_brute(int);
long int findDivisibility_quick(int);
long findGreatestFactorsInList(long, int*);
bool checkDivisible(long int, int);

int main(int argc, char*argv[])
{
	printf("Search for Smallest Multiple for values 1-10 and 1-20 using brute force and factoring respectively\n");
	printf("Looking for Smallest Multiple using the brute force method %lu\n", findDivisibility_brute(10));
	printf("Looking for Smallest Multiple using the factoring method: %lu\n", findDivisibility_quick(20));
	return 1;
}

long int findDivisibility_brute(int value)
{
	long int divisibilityTest = 20;
	while(TRUE)
	{
		bool isDivisible = checkDivisible(divisibilityTest, value);
		if(isDivisible)
			return divisibilityTest;
		else
			divisibilityTest += 20;
	}
}
long int findDivisibility_quick(int largestValue)
{	
	//Create our list and initialize it to 0
	int greatestPrimeListSize = ++largestValue;
	int* greatestPrimeList = calloc(largestValue, sizeof(int));
	//Find the greated multiples in the list for 1 - largestValue
	for(int a = 2; a < largestValue; ++a)
	{
		findGreatestFactorsInList(a, greatestPrimeList);
	}
	long int result = 1;
	//Multiple the values in the list
	for(int a = 0; a < largestValue; ++a)
	{
		for(int b = 0; b < greatestPrimeList[a]; ++b)
		{
			result *= a;
		}
	}
	//Check our result
	if(checkDivisible(result, largestValue))
		return result;
	else
		return -1;
}
bool checkDivisible(long int smallestMultiple, int largestValue)
{	
	//Check if the smallestMultiple is divisible by 1 - largestValue
	for(int a=1; a <= largestValue; ++a)
	{
		if (smallestMultiple % a != 0)
			return FALSE;
	}
	return TRUE;
}

long findGreatestFactorsInList(long valueToFactor, int* list)
{
	//We always start at 2, because everything is factorable by 1
	int previousFactor = 2;
	//Largest factor we have found in the list 
	//(16 is divisible by 2*2*2*2 thus making it the largest factor for values 1-20)
	int largestTotalFactor = 0;
	int nextFactorToCheck = 2;
	do
	{
		if (valueToFactor % nextFactorToCheck == 0)
		{
			//We have found a another factor (ex. 2 * 2)
			if(previousFactor == nextFactorToCheck)
				largestTotalFactor++;
			//The valueToFactor of nextFactorToCheck has changed!
			else
			{
				//Update the old factor to the new one
				previousFactor = nextFactorToCheck;
				//Update the list to show we found a factor in it
				list[nextFactorToCheck] = 1;
				//Update largestTotalFactor because we found a new factor
				largestTotalFactor = 1;
			}
			//Check if the we found a value with a larger TotalFactor is found 
			if(list[previousFactor] < largestTotalFactor)
			{
				//Update the list to reflect the largest factor	
				list[previousFactor] = largestTotalFactor;
			}
			valueToFactor /= nextFactorToCheck;
			//Reset the factorToCheck to its default value
			nextFactorToCheck = 2;
		}//End If
		else
			nextFactorToCheck++;
	}while(valueToFactor != 1);//if valueToFactor == 1 then we have found all factors for that value
	return 0;
}