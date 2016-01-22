#include <stdio.h>
#define FALSE 0
#define TRUE !FALSE

int findPalindrome(int);
int checkForPalindrome(int);

int main(int argc, char* argv[])
{
	printf("Locating Largest Palindrome in two 3-digit numbers");
	int largestProduct = findPalindrome(2);
	return 0;
}

int findPalindrome(int digits)
{
	int largestProduct = -1;
	int multiplicand = 1;
	int multiplier = 1;
	int index_A = 0;
	int index_B = 0;
	for(index_A < 100;++index_A;)
	{
		for(index_B < 100;++index_B;)
		{

		}
	}	
	return -1;
}

int checkForPalindrome(int palindrome)
{
	return -1;
}