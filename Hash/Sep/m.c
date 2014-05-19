#include <stdio.h>
#include "test.h"

int main() {
	
	HashTable H = InitializeTable(50);
	readfile(H);
	p_list p = Find(100,H);
	if (p)
		printf("found!\n");
	else
		printf("not!\n");
	return 0;
}