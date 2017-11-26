#include <stdlib.h>
#include <stdio.h>
#include <math.h>

unsigned int GetFactors(unsigned long number);

int main() {
    unsigned long triangleNumber = 0;
    unsigned long nextNumber = 1;
    unsigned int factors = 0;

    do {
        // Get next triangle number
        triangleNumber += nextNumber;
        nextNumber++;

        // Get factors
        factors = GetFactors(triangleNumber);
    } while (factors < 500);

    printf("First triangle number with over 500 factors is %lu", triangleNumber);
    return triangleNumber;
}

unsigned int GetFactors(unsigned long number) {
    unsigned int factors = 0;
    unsigned int max = sqrt(number);
    // Optimization for odd numbers
    short int offset = (number % 2 == 0 ? 1 : 2);

    for (int factor = 1; factor < max; factor += offset) {
        if (number % factor == 0) {
            factors += 2;
        }
    }
    return factors;
}

// Get a triangle number

// Find the factors of the triangle number

// Determine if it has over 500 factors