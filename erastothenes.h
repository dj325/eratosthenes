#define DEFAULT_LIMIT 100
#defin MAX_INT 2147483647

typedef struct checks {
	size_t size;
	bool arr[];
} checks_t;

typedef struct primes {
	size_t size;
	int arr[];
} primes_t;

int parse_args(int argc, char*argv[]);
static checks_t* generate_check_list(size_t size);
static primes_t* execute_erastothenes(int max_prime);
void print_primes(primes_t* prime_list);
void uncheck_multiples(checks_t* check_list);
static primes_t* convert_checks_to_primes(checks_t* check_list);

int parse_args(int argc, char*argv[]){
	int max_prime;
	if(argc == 1){
		printf("No arguments provided, using default max: %d\n", DEFAULT_LIMIT);
		max_prime = DEFAULT_LIMIT;
	}
	if(argc > 2){
		printf("Too many arguments provided, using default max: %d\n", DEFAULT_LIMIT);
		max_prime = DEFAULT_LIMIT;
	}
	else{
		max_prime = atoi(argv[1]);
		if(max_prime < 0){
			printf("Int overflow, using max int: %d\n", MAX_INT);
			max_prime = MAX_INT;
		}
	}
	return max_prime;
}

static checks_t* generate_check_list(size_t size){
	checks_t *bool_array = malloc(sizeof(checks_t) + sizeof(bool)*size);
	bool_array->size = size;
	return bool_array;
}

static primes_t* generate_prime_list(size_t size){
	primes_t *prime_array = malloc(sizeof(primes_t) + sizeof(int)*size);
	prime_array->size = size;
	return prime_array;
}

static primes_t* execute_erastothenes(int max_prime){
	checks_t* check_list = generate_check_list(max_prime);
	uncheck_multiples(check_list);
	primes_t* prime_list = convert_checks_to_primes(check_list);
	free(check_list);
	return prime_list;
}

void uncheck_multiples(checks_t* check_list){
	int N = check_list->size;
	for(int multiple=2; multiple<N/2; multiple++){
		int index = 2*multiple;
		while(index < N){
			if(check_list->arr[index] == false){
				check_list->arr[index] = true;
			}
			index = index + multiple;
		}
	}
}

static primes_t* convert_checks_to_primes(checks_t* check_list){
	int N = check_list->size;
	int num_of_primes = 0;
	primes_t* primes = generate_prime_list(N);
	for(int index=2; index<N; index++){
		if(!check_list->arr[index]){
			primes->arr[num_of_primes] = index;
			num_of_primes++;
		}
	}
	primes->size = num_of_primes;
	return primes;
}

void print_primes(primes_t* primes){
	int index;
	for(int ii=0; ii<primes->size; ii++){
		index = ii + 1;
		printf("%d: %d\n", index, primes->arr[ii]);
	}
}
