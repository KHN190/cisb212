// this file contains operation functions.
// used for main function between basic operations.

#include <stdio.h>
#include <string.h>
#include "list.h"

// operations.
void carry_out(p_list link_A, int op) {
	// when we have the overflow.
	if ( op >= 10 && link_A->prev == NULL ) {
		p_list p = new( NULL );
		p->next = link_A; link_A->prev = p;
	}
	link_A->x = op % 10; link_A->carry = 0;
	if (link_A->prev) {
		link_A->prev->carry = op / 10;
		link_A->prev->x += link_A->prev->carry;
	}
}

void add( p_list link_A, p_list link_B ) {
	int x, y, c, op;

	// consider link_A carry! new node.
	while ( link_A->prev && link_B->prev ) {
		x = link_A->x; y = link_B->x; c = link_A->carry;
		op = x + y + c; // operate.
		carry_out( link_A, op );

		link_A = link_A->prev; link_B = link_B->prev; // move pointers.
	} // now we have at least one header.

	if ( link_A->prev == NULL ) { // link_A points to header.
		while ( link_B->prev ) {
			op = link_B->x + link_A->x + link_A->carry;
			carry_out( link_A, op );
			// move pointers.
			link_A = link_A->prev; link_B = link_B->prev;
		}
		// link_B points to header too.
		op = link_B->x + link_A->x + link_A->carry;
		carry_out( link_A, op );
	} else { // link_A points to not a header.
		op = link_B->x + link_A->x + link_A->carry;
		carry_out( link_A, op );
		link_A = link_A->prev;
		// find header.
		while ( link_A->prev ) {
			op = link_A->x + link_A->carry;
			carry_out( link_A, op );
			link_A = link_A->prev;
		} // when header found.
		op = link_A->x + link_A->carry;
		carry_out( link_A, op );
	}
}

void multi( p_list link_A, p_list link_B ) {
	int x, y, c, op;

	// consider link_A carry! new node.
	while ( link_A->prev ) {
		x = link_A->x; y = link_B->x; c = link_A->carry;
		op = x * y + c; // operate.
		carry_out( link_A, op );

		link_A = link_A->prev; // move pointers.
	} // now we have at least one header.
	op = link_A->x * link_B->x + link_A->carry;
	carry_out( link_A, op );
}

// convert a char in str to int.
int str_to_int( char c ) {
	int x = c - '0';
	if ( 0 <= x && x <= 9 ) return x;
	else return -1;
}

// read from stdin and convert.
p_list read( p_list link_A) {
	char c, t;
	int x;
	// while c is a digit.
	// omit newline characters.
	while ( (t = getchar()) ) {
		if ( t != '\n' ) break;
	}
	while ( 1 ) {
		if ( t == '\n' ) c = fgetc(stdin);
		else c = t; t = '\n';
		x = str_to_int( c );

		// scan digits, report errors.
		if ( x >= 0 && x <= 9) {
			link_A = new( link_A );
			link_A->x = x;
		} else break;
	} return link_A; // "link_A" points to the last digit.
}
