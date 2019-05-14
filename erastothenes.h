int parse_args(char* argv[]);
bool* generate_check_list(int max_prime);
int* execute_erastothenes(int max_prime);
void print_primes(int* prime_list);
void uncheck_multiples(bool* check_list);
int* convert_checks_to_primes(bool* check_list);
int get_size_of_bool_array(bool* b_array);
int get_size_of_int_array(int* int_array);

int parse_args(char* argv[]){
	int max_prime = atoi(argv[1]);
	return max_prime;
}

int* execute_erastothenes(int max_prime){
	bool* check_list = generate_check_list(max_prime);
	uncheck_multiples(check_list);
	int* prime_list = convert_checks_to_primes(check_list);
	return prime_list;
}

bool* generate_check_list(int max_prime){
	bool* check_list = (bool*)malloc(sizeof(bool) * max_prime);
	return check_list;
}

void uncheck_multiples(bool* check_list){
	for(int multiple=2; multiple<N/2; multiple++){
		int index = 2*multiple;
		while(index < N){
			if(check_list[index] == false){
				check_list[index] = true;
			}
			index = index + multiple;
		}
	}
}

int* convert_checks_to_primes(bool* check_list){
	int* primes = malloc(sizeof(int) * N);
	int num_of_primes = 0;
	for(int ii=0; ii<N/2; ii++){
		if(!check_list[ii]){
			*primes = ii;
			num_of_primes++;
			primes + 1;
		}
	}
	return primes - num_of_primes;
}

void print_primes(int* prime_list){
  for(int ii=0; ii<N; ii++){
		printf("Size: %d, Number: %d, IsPrime : %d\n", N, ii, prime_list[ii]);
	}
}
