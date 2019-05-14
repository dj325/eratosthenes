#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "erastothenes.h"

#define MAX_PRIME 2147483648

int main(int argc, char* argv[]){
	int max_prime = parse_args(argv);
	int* prime_list = execute_erastothenes(max_prime);
	print_primes(prime_list);

	return 0;
}
