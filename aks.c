#include <stdbool.h>
#include <stdint.h>

/**
 * AKS primality test
 * this algorithm is O(sqrt(n))
 * Its uses the fact that a prime has the form 6k-1 or 6k+1 and search for divisors
 * of this form
 */
bool
compute_prime_AKS(uint64_t number)
{
        if (number == 2 || number == 3)
                return true;
        if (number % 2 == 0 || number % 3 == 0)
                return false;
        int i = 5;
        int w = 2;
        while (i * i <= number) {
                if (number % i == 0)
                        return false;
                i += w;
                w = 6 - w;
        }
        return true;
}

