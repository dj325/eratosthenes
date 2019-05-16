#define DEFAULT_LIMIT 100
#define MAX_INT 2147483647

typedef struct bool_array {
	size_t size;
	bool arr[];
} bools_t;

typedef struct int_array {
	size_t size;
	int arr[];
} primes_t;

int parse_args(int argc, char*argv[]);
static bools_t* generate_check_list(size_t size);
static primes_t* generate_prime_list(size_t size);
static primes_t* execute_eratosthenes(int max_prime);
void print_primes(primes_t* prime_list);
void check_factorisable_indexes(bools_t* check_list);
static primes_t* get_primes_from_unchecked_indexes(bools_t* check_list);
void check_multiples_of_factor_in_list(int multiple, bools_t* list);

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
	if(argc == 2){
		max_prime = atoi(argv[1]);
		if(max_prime < 0){
			printf("Int overflow, using max int: %d\n", MAX_INT);
			max_prime = MAX_INT;
		}
	}
	return max_prime;
}

static primes_t* execute_eratosthenes(int max_prime){
	bools_t* check_list = generate_check_list(max_prime);
	check_factorisable_indexes(check_list);
	primes_t* primes = get_primes_from_unchecked_indexes(check_list);
	free(check_list);
	return primes;
}

static bools_t* generate_check_list(size_t size){
	bools_t *bool_array = malloc(sizeof(bools_t) + sizeof(bool)*size);
	bool_array->size = size;
	return bool_array;
}

void check_factorisable_indexes(bools_t* check_list){
	int limit = (int) sqrt(check_list->size) + 1;
	for(int factor=2; factor<=limit; factor++){
		check_multiples_of_factor_in_list(factor, check_list);
	}
}

void check_multiples_of_factor_in_list(int factor, bools_t* list){
  int multiple = 2*factor;
  while(multiple <= list->size){
    if(list->arr[multiple] == false){
      list->arr[multiple] = true;
    }
    multiple = multiple + factor;
  }
}

static primes_t* get_primes_from_unchecked_indexes(bools_t* check_list){
	int N = check_list->size;
	int num_of_primes = 0;
	primes_t* primes = generate_prime_list(N);
	for(int index=2; index<N+1; index++){
		if(!check_list->arr[index]){
			primes->arr[num_of_primes] = index;
			num_of_primes++;
		}
	}
	primes->size = num_of_primes;
	return primes;
}

static primes_t* generate_prime_list(size_t size){
	primes_t *prime_array = malloc(sizeof(primes_t) + sizeof(int)*size);
	prime_array->size = size;
	return prime_array;
}

void print_primes(primes_t* primes){
	int index;
	for(int ii=0; ii<primes->size; ii++){
		index = ii + 1;
		printf("%d: %d\n", index, primes->arr[ii]);
	}
}
