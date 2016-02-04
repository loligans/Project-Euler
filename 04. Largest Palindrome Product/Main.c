#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FALSE 0
#define TRUE !FALSE
#define bool int

int findPalindrome(int);
int checkForPalindrome(int);

int main(int argc, char* argv[])
{
	printf("Locating Largest Palindrome in two 3-digit numbers\n");
	printf("Using the bruteforce method\n");
	int largestPalindrome = findPalindrome(3);
	printf("The largest palindrome in 3 digits is %d\n", largestPalindrome);
	return 0;
}

int findPalindrome(int digits)
{
	//Create and append '9' to the end of a string
	char* largestDigitStr = malloc(sizeof(char) * digits);
	for(int i = 0;i<digits;++i)
		largestDigitStr[i] = '9';

	//Convert the string to an int
	int originalMultiplicand = strtol(largestDigitStr, (char**)NULL, 10);
	int multiplicand = originalMultiplicand;
	int multiplier = multiplicand;
	largestDigitStr = NULL;
	printf("Largest %d-Digit value is: %d\n", digits, multiplicand);

	//Multiply the values and check if it is a palindrome
	int largestPalindrome = 0;
	for(int a = 0;multiplicand > a;--multiplicand)
	{
		for(int b = 0;multiplier > b;multiplier-=1)
		{
			int possiblePalindrome = multiplicand * multiplier;
			bool isPalindrome = checkForPalindrome(possiblePalindrome) ? TRUE : FALSE;
			//printf("Multiplicand = %d : Multiplier = %d : Result = %d\n", multiplicand, multiplier, possiblePalindrome);
			if(isPalindrome)
				largestPalindrome = possiblePalindrome > largestPalindrome ? possiblePalindrome : largestPalindrome;
		}
		multiplier = originalMultiplicand;
	}
	return largestPalindrome;
}

int checkForPalindrome(int possiblePalindrome)
{
	//Convert the integer to a string
	char* strPalin = malloc(sizeof(char) * 255);
	sprintf(strPalin, "%d", possiblePalindrome);
	//printf("The sizeof the string is %lu\n", strlen(strPalin));

	//Get the length of the palindrome
	int palindromeLength = strlen(strPalin);
	int halfPalinLength = palindromeLength/2;

	//Create 2 strings at the half mark
	char* aSection = malloc(sizeof(char) * 255);
	char* bSection = malloc(sizeof(char) * 255);
	memcpy(aSection, strPalin, sizeof(char) * halfPalinLength);
	memcpy(bSection, strPalin+halfPalinLength, sizeof(char) * halfPalinLength);
	//printf("The value of both: %s\n", strPalin);
	//printf("The value of a is: %s\n", aSection);
	//printf("The value of b is: %s\n", bSection);

	//Check if the values are palindromic
	int a=0;
	int b=halfPalinLength-1;
	for(; a < halfPalinLength; ++a)
	{
		//printf("a = %d : b = %d\n", aSection[a], bSection[b-a]);
		if (aSection[a] != bSection[b-a])
			return FALSE;
	}
	return TRUE;
}
