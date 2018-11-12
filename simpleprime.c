#include <inttypes.h>
#include <stdbool.h>
#include "simpleprime.h"

bool
compute_prime_simple(uint64_t number)
{
        if (number <= 2)
                return true;
        int i = 2;
        int j;
        while (i < number) {
                j = 0;
                while (j <= i) {
                        if ((i * j) == number)
                                return false;
                        ++j;
                }
                ++i;
        }
        return true;
}

