#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define SUM_TO_FIND 1000

long findPythagTriplets();
long factorValue(unsigned long, unsigned long**, unsigned long**);

int main(int argc, char*argv[])
{
	printf("Locating Pythagorean Triplets\n");
	unsigned long product = findPythagTriplets();
	return product;
}

/**
* Use Dicksons Formula to find Pythagorean Triplets
* Dicksons formula is explained more in depth here 
* https://en.wikipedia.org/wiki/Formulas_for_generating_Pythagorean_triples
**/
long findPythagTriplets()
{
	clock_t start, end;
	double exe_time1;
	//Dicksons Formula variables
	unsigned long r = 2;//r
	unsigned long* sFactors; //s
	unsigned long* tFactors; //t
	unsigned long totalFactors;
	unsigned long a; //r + s
	unsigned long b; //r + t
	unsigned long c; //r + s + t
	unsigned long sum; //a + b + c
	unsigned long product; //a * b * c
	do{
		//Benchmark the algorithm
		start = clock();
		//Get all possible factors of (r * r / 2) 
		totalFactors = factorValue( r * r / 2, &sFactors, &tFactors);
		printf("Generating all possible Pythagorean Triplets\n");
		//Use the factors returned from factorValue to generate all pythagTriplets
		for(int factors = 0; factors < totalFactors; ++factors)
		{
			//Use Dicksons Formula to get a, b, and c
			a = r + sFactors[factors];
			b = r + tFactors[factors];
			c = r + sFactors[factors] + tFactors[factors];
			sum = a + b + c;
			product = a * b * c;
			printf("a=%lu : b=%lu : c=%lu : sum:%lu : a*b*c=%lu\n", a, b, c, sum, product);
			//We found the Triplet that adds to 1000
			if(sum == SUM_TO_FIND)
			{
				//Stop the benchmark
				end = clock();
				exe_time1 = (double)(end - start) / CLOCKS_PER_SEC;
				printf("It took %f to find the Pythagorean Triplet that adds to 1000\n", exe_time1);
				return product;
			}
		}
		//Check the next value in Dicksons Formula (r must be an even integer)
		r+=2;
		//the sum of a + b + c cannot be possible when r is greater than 1000
	}while(r < SUM_TO_FIND);
	return 0;
}


long factorValue(unsigned long valueToFactor, unsigned long** sFactors, unsigned long** tFactors)
{
	//Store all factors in this temp array which is intentionally too large (we trim it later)
	unsigned long* sTemp = malloc(sizeof(long) * (unsigned long)sqrt(valueToFactor));
	unsigned long* tTemp = malloc(sizeof(long) * (unsigned long)sqrt(valueToFactor));
	unsigned long nextValue = 1;
	unsigned long factorsFound = 0;
	//Locate all the factors in the parameter valueToFactor
	while(nextValue < (long)sqrt(valueToFactor)+1)
	{
		//We found a factor
		if(valueToFactor % nextValue == 0)
		{
			sTemp[factorsFound] = nextValue;
			tTemp[factorsFound] = valueToFactor / nextValue;
			factorsFound++;
		}
		nextValue++;
	}
	printf("Found %ld-Factors Allocating %ld-longs for the following factors\n", factorsFound, factorsFound);
	unsigned long* sTrimmedFactors = malloc(sizeof(long) * factorsFound);
	unsigned long* tTrimmedFactors = malloc(sizeof(long) * factorsFound);
	for(long a = 0; a < factorsFound; ++a)
	{
		sTrimmedFactors[a] = sTemp[a];
		tTrimmedFactors[a] = tTemp[a];
		printf("s=%lu : t=%lu\n", sTrimmedFactors[a], tTrimmedFactors[a]);
	}
	//Pass the factors we found to the pointer parameters we passed in
	*sFactors = sTrimmedFactors;
	*tFactors = tTrimmedFactors;
	//Release the tempFactors array
	free(sTemp);
	free(tTemp);
	return factorsFound;
}