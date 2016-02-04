#include <stdio.h>

long findSumOfSquare_efficient(int);
long findSquareOfSum_efficient(int);

int main(int argc, char* argv[])
{
	printf("Size of an int: %lubytes\nSize of a long: %lubytes\n", sizeof(int), sizeof(long));
	long squareOfSum = findSquareOfSum_efficient(100);
	long sumOfSquare = findSumOfSquare_efficient(100);
	printf("The Difference of the sumOfSquare - squareOfSum = %lu\n", squareOfSum - sumOfSquare);
	return 1;
}

//1^2 + 2^2 + 3^2 + 4^2 + 5^2 + 6^2...
long findSumOfSquare_efficient(int maxValue)
{
	//Convert maxValue to double so that we get a whole number in the end
	double bigValue = maxValue;
	//The formula which is (n^3/3) + (n^2/2) + (n/6)
	long int totalSum = (bigValue * bigValue * bigValue / 3) + (bigValue * bigValue / 2) + (bigValue / 6);
	printf("Sum of Squares (1^2 + 2^2 + 3^2) = %lu\n", totalSum);
	return totalSum;
}
//(1 + 2 + 3 + 4 + 5 + 6)^2
long findSquareOfSum_efficient(int maxValue)
{
	//Get the largest value
	long largestIndex = maxValue + 1;
	long totalSum;
	//Check if it is odd to add the middle index
	if(maxValue % 2 == 0)
		totalSum = largestIndex * (maxValue / 2);
	else
		totalSum = largestIndex * ((maxValue + 1) / 2);
	//Square it
	totalSum *= totalSum;
	printf("Square of Sums (1 + 2 + 3 + 4)^2 = %lu\n", totalSum);
	return totalSum;
}
