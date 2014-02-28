#include <string.h>
#include <stdio.h>

/* translate string to int. */
void strtoint( char* str, int* integer ) {
	int i;
	for ( i = 0; i < strlen(str); i++ ) integer[i] = str[i] - '0';
}

void print( int res[51] ) {
	int i;
	printf( "result is:\n" );
	if (res[50] != 0) {
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
	printf( "enter the other integer:\n");
	fgets( str, 51, stdin ); strtoint( str, int2 );

	/* calculate. */
	carry = 0;
	for ( i = 0; i <= 49; i++ ) {
		temp = int1[i] + int2[i] + carry; carry = temp / 10;
		res[i] = temp % 10; res[i+1] = carry;
	}

	/* result print. */
	print( res );
}

void multi( int int1[] ) {
	int x;
	int i, temp, carry; //for operating process.
	int res[51];

	/* get x from stdinput. */
	char c = '0';
	printf( "enter a digit:\n" );
	c = getch(); x = c - '0';
	printf( "%d\n", x );

	/* calculate. */
	carry = 0;
	for ( i = 0; i <= 49; i++ ) {
		temp = int1[i] * x + carry; carry = temp / 10;
		res[i] = temp % 10; res[i+1] = carry;
	}

	/* result print. */
	print( res );
}