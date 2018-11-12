#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <inttypes.h>

#include "simpleprime.h"
#include "aks.h"

static void
exit_usage(const char *const progname)
{
        puts("usage:");
        printf("\t%s <options>\n", progname);
        puts("\n"
                "\t-h\t\tshow this help\n"
                "\t-m <method>\tmethod [simple|AKS]\n"
                "\t-n <number>\tnumber\n");
        exit(1);
}

int
main (int argc, char* argv[])
{
        int opt;
        uint64_t n = 0;
        char *endptr = 0;
        bool (*function_p)(uint64_t) = 0;
        while ((opt = getopt(argc, argv, "hm:n:")) != -1) {
                switch(opt) {
                case 'h':
                        exit_usage(argv[0]);
                        exit(0);
                        break;
                case 'm':
                        if (strcmp("simple", optarg) == 0) {
                                function_p = compute_prime_simple;
                        } else
                        if (strcmp("AKS", optarg) == 0 ||
                            strcmp("aks", optarg) == 0) {
                                function_p = compute_prime_AKS;
                        }
                        break;
                case 'n':
                        n = strtoumax(optarg, NULL, 10);
                        break;
                default:
                        break;
                }
        }
        if (n < 2 || n > UINT64_MAX || !function_p)
                exit_usage(argv[0]);
        bool isPrime = function_p(n);
        printf("The number %"PRIu64" is %s\n",
                        n,
                        isPrime ? "prime" : "not prime");
}

