#include <stdio.h>
#include <stdlib.h>

int p[10];

void scope_test(){
	p[2] = 100;
}

int main(){
	scope_test();
	return 0;
}

