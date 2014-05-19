#include <stdio.h>
#include "test.h"

int main() {
	
	p_list p;
	HashTable H = InitializeTable(50);
	readfile(H);
	
	check(100,H);
	check(1201,H);
	check(26966,H);

	traverse(H);

	DestroyTable(H);
	return 0;
}