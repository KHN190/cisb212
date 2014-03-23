#include <stdio.h>
#include <string.h>
#include "list.h"

void main() {
	p_list link_A = NULL, link_B = NULL;
	char op; 

	printf( "enter the first number:\n" );
	link_A = read( link_A ); // link_A points to the last node.
	if ( link_A == NULL ) {
		printf( "error: empty digit.\n" );
		return; // error report.
	}

	printf( "enter the operator:\n" );
	while (fgetc(stdin) == '\n') fgetc(stdin);
	op = fgetc(stdin);

	// recognize operand.
	switch ( op - '0' ) {
		case ('+' - '0'): // link_B points to link_A last node and operate from the lowest.
			printf( "enter the second number:\n" );
			link_B = read( link_B ); add( link_A, link_B );
			break;
		case ('*' - '0'): // link_B ponits to link_A last node and operate from the lowest.
			printf( "enter the second number:\n" );
			link_B = read( link_B ); multi( link_A, link_B );
			break;
		default:
			printf( "error: illegal operand.\nprogram terminated.\n\n" );
	} print( link_A ); // show operation result.

	return;
}
