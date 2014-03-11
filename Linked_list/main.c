#include <stdio.h>
#include <string.h>

#include "list.c"
#include "function.c"

// main function.
void main() {
	p_list this = NULL, that = NULL;
	printf( "enter the first number:\n" );
	read( this ); // this points to the last node.

	printf( "enter the operator:\n" );
	op = getch(); printf("%c\n", op); fflush( stdin );

	// recognize operand.
	switch ( op - '0' ) {
		case ('+' - '0'): // that points to the last node and operate from the lowest.
			printf( "enter the second number:\n" );
			read( that ); add( this, that );
			break;
		case ('*' - '0'): // that ponits to the last node and operate from the lowest.
			printf( "enter the second number:\n" );
			read( that ); multi( this, that );
			break;
		default:
			printf( "error: illegal operand. program terminated.\n\n" );
	} print( this );

	return;
}
