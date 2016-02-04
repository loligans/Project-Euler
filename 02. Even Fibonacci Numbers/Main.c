#include <stdio.h>
#define ERROR -1
#define DEBUG 0
#define INFO 1

long computeFibonacciEven(long);
long computeFibonacciEvenFast(long)

int main(int argc, char*argv[])
{
	long result = computeFibonacciEven(4000000);
	printf("The Largest sum without going over the max is: %lu\n", result);
	return 0;
}

//This way computes every fibonacci until max is met
long computeFibonacciEven(long max)
{
	//Inititialize the data
	long currentFibonacciValue = 1;
	long nextFibonacciValue = 2;
	long sumOfEvens = 2;
	long computedValue = 0;
	while(1){
		computedValue = currentFibonacciValue + nextFibonacciValue;
		printf("CurrentFib=%lu : NextFib=%lu : EvenSum=%lu : ComputedValue=%lu\n", 
			currentFibonacciValue, nextFibonacciValue, sumOfEvens, computedValue);
		if (computedValue > max)//You are over the max
			return sumOfEvens;
		else if(computedValue % 2 == 0)//It is an even number
		{
			sumOfEvens += computedValue;
		}
		currentFibonacciValue = nextFibonacciValue;
		nextFibonacciValue = computedValue;
	}
}

long computeFibonacciEvenFast(long max)
{
	
}