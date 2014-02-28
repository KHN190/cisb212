/*  Sample input and output

12345678900987654321123456789009876543211234567890 + 56789009876543211234567890098765432112345678901234
69134688777530865555691346887775308655556913469124 

56789009876543211234567890098765432112345678901234 * 5
283945049382716056172839450493827160561728394506170

a. Write functions for + and *.
b. Write a main function which calculates the result from the input, using functions implemented in a. */

#include <stdio.h>
#include <string.h>
#include "functions.c"

void main( ) {
	int integer[50], i;
	char op = '0', str[51];

	/* get inputs from stdinput. */
	/* the integer and the operator. */
	printf( "enter 50 digits string for input:\n");
	fgets( str, 51, stdin ); strtoint( str, integer );
	fflush( stdin ); // clear sdtion buffer.

	printf( "enter the operator:\n" );
	op = getch(); printf("%c\n", op);

	/* cases for operating. */
	switch ( op - '0' ) {
		case ('+' - '0'):
			plus( integer );
			break;
		case ('*' - '0'):
			multi( integer );
			break;
		default:
			printf( "error: an illegal operator. process terminated.\n\n" );
		break;
	}
	return;
}