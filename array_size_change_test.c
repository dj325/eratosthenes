#include <stdio.h>
#include <stdlib.h>

int main(){
	int a[] = {1,2,3,4,5};
	int b[] = {6,7,8};
	b = a;
	printf("a: %ld | b: %ld\n", sizeof(a), sizeof(b));
}
