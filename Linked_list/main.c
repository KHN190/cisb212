#include <stdio.h>
#include <string.h>

//this should be included in function file.
struct list {
	int x, carry = 0;
	p_list next, prev = NULL;
};
typedef struct list* p_list;

//convert a char in str to int.
int str_to_int( char c ) {
	int x = c - '0';
	if ( 0 <= x && x <= 9 ) return c - '0';
	else return -1;
}

//create a list node.
void new( p_list this ) {
	//use this, this->next, this->prev to modify the number in list node.
	next = ( p_list )malloc( sizeof( struct list ) );
	next->prev = this; this = next;
}

//delete a list node.
void del( p_list this ) {
	p_list p = this; this = p->prev;

	//in case it's the header of list.
	if ( this ) this->next = p->next;
	else printf( "the last element distinct on earth!\n" );

	free( p );
}

//maybe need either a function of find_next and find_prev.

//operation.
void add( p_list this, p_list that ) {
	int x = this->x, y = that->x;
	int op, carry = 0;

	//modify here to match different length.
	//
	op = x + y + this->next->carry;
	this->carry = op / 10;
	this->x	= op % 10;
}

void multi( p_list this, p_list that ) {
	int x = this->x, y = that->x;
	int op, carry = 0;

	//modify here to match different length.
	//
	op = x * y + this->next->carry;
	this->carry = op / 10;
	this->x = op % 10;
}

//read from stdin and convert.
void read( ) {
	char str;
	int i;
	p_list header;

	header = ( p_list )malloc( sizeof( struct list ) );
	p_list this = header; this->prev = NULL; this->next = NULL;

	fgets( str, ,stdin );
	for ( i = 0; i <= strlen(str); i++ ) {
		int x = str_to_int( str[i] );
		this->x = x;
	}
}


void main() {
	char str = read();
}