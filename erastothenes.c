#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "erastothenes.h"

int main(int argc, char* argv[]){
	int max_prime = parse_args(argc, argv);
	primes_t* primes = execute_erastothenes(max_prime);
	print_primes(primes);
	free(primes);

	return 0;
}
