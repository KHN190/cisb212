#include <stdio.h>
#include "quad.h"

int main() {
	HashTable H = InitializeTable(200);
	readfile(H);
	check(5758,H);
	printf("delete this element.\n");
	Delete(5758,H);
	check(5758,H);
	DestroyTable(H);
	return 0;
}