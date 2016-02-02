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
long factorValue(long, long**, long**);

int main(int argc, char*argv[])
{
	clock_t start, end;
	double exe_time1;
	double exe_time2;
	

	printf("Locating Pythagorean Triplets\n");
	findPythagTriplet();

	return 1;
}

long findPythagTriplet()
{
	long* sFactors;
	long* tFactors;
	unsigned long r = 6;//c
	unsigned long totalFactors = factorValue(r*r / 2, &sFactors, &tFactors);
	unsigned long a = sFactors[0];
	unsigned long b = tFactors[0];
	printf("a=%lu : b=%lu\n", a, b);

	return -1;
}


long factorValue(long valueToFactor, long** sFactors, long** tFactors)
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
	printf("Found %ld Allocating %ld-longs\n", factorsFound, factorsFound + 1);
	long* sTrimmedFactors = malloc(sizeof(long) * (factorsFound + 1));
	long* tTrimmedFactors = malloc(sizeof(long) * (factorsFound + 1));
	for(long a = 0; a < factorsFound; ++a)
	{
		sTrimmedFactors[a] = sTemp[a];
		tTrimmedFactors[a] = tTemp[a];
		printf("s=%lu : t=%lu\n", sTrimmedFactors[a], tTrimmedFactors[a]);
	}
	*sFactors = sTrimmedFactors;
	*tFactors = tTrimmedFactors;
	free(sTemp);
	free(tTemp);
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
