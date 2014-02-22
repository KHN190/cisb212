/*  Sample input and output

12345678900987654321123456789009876543211234567890 + 56789009876543211234567890098765432112345678901234
69134688777530865555691346887775308655556913469124 

56789009876543211234567890098765432112345678901234 * 5
283945049382716056172839450493827160561728394506170

a. Write functions for + and *.
b. Write a main function which calculates the result from the input, using functions implemented in a. */

#include <stdio.h>
#include <string.h>
//#include "functions.c"

/* translate string to int. */
void strtoint( char str[], int integer[] ) {
	int i;
	for ( i = 0; i < strlen(str); i++ ) integer[i] = str[i] - '0';
}

void print( int res[51] ) {
	int i;
	if (res[51] != 0) {
		for ( i = 50; i >= 0; i-- ) printf( "%d", res[i] );
	} else {
		for ( i = 49; i >= 0; i-- ) printf( "%d", res[i] );
	}
	printf( "\n" );
}

void plus( int int1[] ) {
	int i, temp, carry;
	int int2[50], res[51];

	/* get int2 from stdinput. */
	char str[50];
	scanf( "%50s", str ); strtoint( str, int2 );

	/* calculate. */
	carry = 0;
	for ( i = 0; i <= 49; i++ ) {

		temp = int1[i] + int2[i] + carry;
		res[i] = temp % 10; carry = temp / 10;

		if ( i == 49 )
			res[50] = carry;
	}

	/* result print. */
	print( res );
}

void multi( int int1[] ) {
	int x;
	int i, temp, carry; //for operating process.
	int res[51] = {0};

	/* get x from stdinput. */
	char c;
	scanf( "%c", c ); x = c - '0';

	/* calculate. */
	carry = 0;
	for ( i = 0; i <= 49; i++ ) {

		temp = int1[i] * x + carry;
		res[i] = temp % 10; carry = temp / 10;

		if ( i == 49 )
			res[50] = carry;
	}

	/* result print. */
	print( res );
}

void main( ) {
	int integer[50];
	char op = '0', str[50];

	/* get inputs from stdinput. */
	/* the integer and operator. */
	printf( "enter 50 digits string for input:\n");
	scanf( "%50s", str ); strtoint( str, integer );

	printf( "enter the operator:\n" );
	scanf( "%c", op );

	switch ( op - '0' ) {
		case ('+' - '0'):
			plus( integer );
			break;
		case ('*' - '0'):
			multi( integer );
			break;
		break;
	}
}
