#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main() {
	SearchTree T;
	T = BuildTree( NULL );
	Inorderprint( T );
	printf("\n*** *** sorted! *** ***\n");
	T = HandleTree( T );
	Inorderprint( T );
	printf("\n*** *** sorted! *** ***\n");
	return 0;
}