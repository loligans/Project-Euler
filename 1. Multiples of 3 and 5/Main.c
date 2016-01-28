#include <stdio.h>
#define FALSE 0
#define TRUE !FALSE
#define bool int
#define MULTIPLE_TO_FIND 1000
int findMultipleSum_efficient(int, int);
int findMultipleDupes_efficient(int, int, int, int);

int main(int argc, char*argv)
{
	printf("Searching for sum of multiples of 3 and 5 below %d\n", MULTIPLE_TO_FIND);

	int sum3 = findMultipleSum_efficient(3, MULTIPLE_TO_FIND);
	int sum5 = findMultipleDupes_efficient(3, 5, MULTIPLE_TO_FIND, findMultipleSum_efficient(5, MULTIPLE_TO_FIND));
	int totalSum = sum3 + sum5;

	printf("Sum of 3 = %d\nSum of 5 = %d\nSum of both = %d\n", sum3, sum5, totalSum);
	return 1;
}

int findMultipleSum_efficient(int rootMultiple, int maxValue)
{
	//changes 1000/5 to 999/5 or 30/3 to 29/3 to keep the multiple BELOW the maxValue passed in
	int largestIndex;
	if(maxValue % rootMultiple == 0)
		largestIndex = (maxValue - 1) / rootMultiple;
	else
		largestIndex = maxValue / rootMultiple;

	int largestValue = largestIndex * rootMultiple;
	int smallestValue = rootMultiple;

	//Compute the totalSum by using math instead of bruteforcing
	int totalSum = 0;
	if(largestIndex % 2 != 0)//It is odd
	//If it is odd we have to add the middle modulus (aka the middle) value to the result
	{
		totalSum = largestValue + smallestValue;
		totalSum = totalSum * (largestIndex / 2);
		totalSum = ((largestIndex / 2) + 1) * rootMultiple + totalSum;
	}
	else
	//If it is even we do not have to add the middle value to the result 
	{
		totalSum = largestValue + smallestValue;
		totalSum = totalSum * (largestIndex / 2);
	}
	return totalSum;
}

int findMultipleDupes_efficient(int rootMultipleA, int rootMultipleB, int maxValue, int totalSumOfMultipleB)
{
	//This value is duplicated totalSumOfMultipleB / (rootMultipleA * rootMultipleB) times
	int dupedValue = rootMultipleA * rootMultipleB;
	int dupedSum = findMultipleSum_efficient(dupedValue, maxValue);
	printf("Duplicated Multiple to find = %d : Duplicated Total Sum = %d\n", dupedValue, dupedSum);
	return totalSumOfMultipleB - dupedSum;
}