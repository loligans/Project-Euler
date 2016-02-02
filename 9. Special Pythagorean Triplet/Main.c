#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define bool int
#define FALSE 0
#define TRUE !FALSE
#define COPRIME 1

bool testIfPythagTriplet(unsigned long m, unsigned long n);
long findPythagTriplet();
void discoverPythagTriplets();
long factorValues(long, long*, long*);

int main(int argc, char*argv[])
{
	clock_t start, end;
	double exe_time1;
	double exe_time2;
	

	printf("Locating Pythagorean Triplets\n");
	findPythagTriplet();

	// start = clock();
	// long factorsFound = factorValues(1000, sFactors, tFactors);
	// end = clock();
	// exe_time1 = (double)(end - start) / CLOCKS_PER_SEC;
	// printf("Total factoring time is %f and we found %ld factors\n", exe_time1, factorsFound);



	return 1;
}



long factorValues(long valueToFactor, long* sFactors, long* tFactors)
{
	//Store all factors in this temp array
	long* sTemp = malloc(sizeof(long) * (long)sqrt(valueToFactor));
	long* tTemp = malloc(sizeof(long) * (long)sqrt(valueToFactor));
	long nextValue = 1;
	long factorsFound = 0;
	while(nextValue < (long)sqrt(valueToFactor)+1)
	{
		if(valueToFactor % nextValue == 0)
		{
			sTemp[factorsFound] = nextValue;
			tTemp[factorsFound] = valueToFactor / nextValue;
			factorsFound++;
		}
		nextValue++;
	}
	sFactors = malloc(sizeof(long) * (factorsFound + 1));
	tFactors = malloc(sizeof(long) * (factorsFound + 1));
	for(long a = 0; a < factorsFound; ++a)
	{
		sFactors[a] = sTemp[a];
		tFactors[a] = tTemp[a];
		printf("s=%lu : t=%lu\n", sFactors[a], tFactors[a]);
	}
	// free(sTemp);
	// free(tTemp);
	return factorsFound;
}



bool testIfPythagTriplet(unsigned long m, unsigned long n)
{
	if(m < n)
		return FALSE;
	bool isOdd = (m - n) % 2;
	//Multiply m * n until it is 0
	while (m * n)
	{
		if (m > n)
			m %= n;
		else
			n %= m;
	}
	//If the result is equal to 1, then it is coprime
	bool isCoprime = ((m > n) ? m : n) == COPRIME;
	//Test if m - n is odd
	return isOdd && isCoprime;
}

long findPythagTriplet()
{
	unsigned long* sFactors; //a
	unsigned long* tFactors; //b
	unsigned long r = 6;//c
	unsigned long totalFactors = factorValues((r*r) / 2, sFactors, tFactors);
	unsigned long a = sFactors[0];
	unsigned long b = tFactors[0];
	printf("a=%lu : b=%lu\n", a, b);
	// unsigned long a = r + (sFactors[0]);
	// unsigned long b = r + (tFactors[0]);
	//unsigned long c = r + (sFactors[0]);

	//printf("Triplet is %lu, %lu, %lu\n", a, b, c);
	// unsigned long a = (m * m) - (n * n);
	// unsigned long b = 2 * (m * n);
	// unsigned long c = (m * m) + (n * n);
	// unsigned long sum = a+b+c;
	// printf("a=%lu : b=%lu : c=%lu : Sum=%lu\n", a, b, c, sum);
	return -1;
}