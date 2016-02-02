#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define bool int
#define FALSE 0
#define TRUE !FALSE
#define COPRIME 1

bool testIfPythagTriplet(unsigned long m, unsigned long n);
long findPythagTriplets();
void discoverPythagTriplets();
long factorValue(unsigned long, unsigned long**, unsigned long**);

int main(int argc, char*argv[])
{
	clock_t start, end;
	double exe_time1;
	double exe_time2;
	

	printf("Locating Pythagorean Triplets\n");
	findPythagTriplets();

	return 1;
}

long findPythagTriplets()
{
	//a = r + s
	//b = r + t
	//c = r + s + t
	unsigned long r = 6;//r
	unsigned long* sFactors; //s
	unsigned long* tFactors; //t
	unsigned long totalFactors = factorValue(r*r / 2, &sFactors, &tFactors);
	unsigned long a = sFactors[0];
	unsigned long b = tFactors[0];
	printf("a=%lu : b=%lu\n", a, b);

	return -1;
}


long factorValue(unsigned long valueToFactor, unsigned long** sFactors, unsigned long** tFactors)
{
	//Store all factors in this temp array
	unsigned long* sTemp = malloc(sizeof(long) * (unsigned long)sqrt(valueToFactor));
	unsigned long* tTemp = malloc(sizeof(long) * (unsigned long)sqrt(valueToFactor));
	unsigned long nextValue = 1;
	unsigned long factorsFound = 0;
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
	printf("Found %ld-Factors Allocating %ld-longs\n", factorsFound, factorsFound + 1);
	unsigned long* sTrimmedFactors = malloc(sizeof(long) * (factorsFound + 1));//We add 1 because factors found is offset by 1
	unsigned long* tTrimmedFactors = malloc(sizeof(long) * (factorsFound + 1));//We add 1 because factors found is offset by 1
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
