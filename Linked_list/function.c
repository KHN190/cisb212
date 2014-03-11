// this file contains the operation functions.
// which should be 

#include <stdio.h>
#include <string.h>
#include "list.c"

// operations.
void add( p_list this, p_list that ) {
	int x, y, c, op;

	// modify here to match different length.
	// consider the carry! new node.
	while ( this->prev && that->prev ) {
		x = this.x; y = that.x; c = this.carry;
		op = x + y + c;

		this.x = op % 10; // operation.
		this->prev.carry = op / 10;

		this = this->prev; that = that->prev; // move pointers.
	}

	// when at least one of them points to the header.
	x = this.x; y = that.x; c = this.carry;
	op = x + y + c;

	if ( this->prev ) {
		// A link is longer.
		while ( this->prev ) {
			this.x = op % 10; this = this->prev;
			this.carry = op / 10;
			op = this.x + this.carry;
		}
	} else {
		// B link is longer.
		while ( that->prev ) {
			// create new node and allocate.
			p_list p = new( NULL );
			p->next = this; this->prev = p;

			this.x = op % 10; this = this->prev;
			this.carry = op / 10;
			op = that.x + this.carry;
		}
	} // it will points to the headers.

	// when we have the last carry out.
	if ( op >= 10 ) {
		p_list p = new( NULL );
		p->next = this; this->prev = p; this = p;

		this.x = op % 10;
	}
}

void multi( p_list this, p_list that ) {
	int x, y, op, c;

	// when they are not headers.
	while ( this->prev && that->prev ) {
		x = this.x; y = that.x; c = this.carry;
		op = x * y + c;

		this.x = op % 10; // operation.
		this->prev.carry = op / 10;

		this = this->prev; that = that->prev; // move pointers.
	}

	// when at least one of them points to the header.
	x = this.x; y = that.x; c = this.carry;
	op = x * y + c;

	if ( this->prev ) {
		// A link is longer.
		while ( this->prev ) {
			this.x = op % 10; this = this->prev;
			this.carry = op / 10;
			op = this.x + this.carry;
		}
	} else {
		// B link is longer.
		while ( that->prev ) {
			// create new node and allocate.
			p_list p = new( NULL );
			p->next = this; this->prev = p;

			this.x = op % 10; this = this->prev;
			this.carry = op / 10;
			op = that.x + this.carry;
		}
	} // it will points to the headers.

	// when we have the last carry out.
	if ( op >= 10 ) {
		p_list p = new( NULL );
		p->next = this; this->prev = p; this = p;

		this.x = op % 10;
	}
}

// convert a char in str to int.
int str_to_int( char c ) {
	int x = c - '0';
	if ( 0 <= x && x <= 9 ) return c - '0';
	else return -1;
}

// read from stdin and convert.
void read( p_list this) {
	char str;
	int i;
	// no header necessary.

	// no limitation of digit length.
	fgets( str, 0x1111111, stdin );
	// while str[i] != EOF.
	for ( i = 0; i < strlen(str); i++ ) {
		int x = str_to_int( str[i] );

		// recognize a digit.
		if ( x >= 0 && x <= 9) {
			new( this );
			this.x = x;
		} else
		return "error: illegal digit. process terminated.\n\n";
	}
	fflush( stdin ); // clear stdin buffer toilet.
	// "this" points to the last digit.
}
