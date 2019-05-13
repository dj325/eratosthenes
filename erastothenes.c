#include <stdio.h>
#include <stdlib.h>

#define MAX_PRIME 2147483648

int parse_args(char* argv[]);
bool* generate_check_list(int max_prime);
int* execute_erastothenes(bool* check_list);
void print_primes(prime_list);

int main(int argc, char* argv[]){
	int max_prime = parse_args(argv);
	int* prime_list = execute_erastothenes(max_prime);
	print_primes(prime_list);

	return 0;
}

int parse_args(char* argv[]){
	int max_prime = atoi(argv[1]);
	return max_prime
}

int* execute_erastothenes(int max_prime){
	bool* check_list = generate_check_list(max_prime);
	check_list = uncheck_multiples(check_list);
	int* prime_list = convert_checks_to_primes(check_list);
	return prime_list;
}

bool* generate_check_list(int max_prime){
	bool check_list[max_prime];
	return check_list;
}

bool* uncheck_multiples(bool* check_list){
	int N = get_size_of(check_list);
	for(int ii=0; ii<N/2; ii++){
		if(check_list[ii] == True){
			continue;
		}
		index = 2*ii;
		while(index < N){
			if(check_list[index]==True){
				check_list[index] = False;
			}
			else{
				continue;
			}
			index = index + ii
		}
	}
	return check_list;
}

int* convert_checks_to_primes(bool* check_list){
	int N = get_size_of(check_list);
	int primes[N];
	int num_of_primes = 0;
	for(int ii=0; ii<N/2; ii++){
		if(check_list[ii]){
			*primes = ii + 2;
			num_of_primes++;
			primes + 1;
		}
	}

	return primes - num_of_primes;
	
void print_primes(int* prime_list){
	for(ii=0;ii<prime_list_end;ii++){
		printf("%d : %d\n", ii, prime_list[ii]);
	}
}

int get_size_of_array(char* array){
	int N = sizeof(array)/sizeof(array[0]);
	return N;
}


