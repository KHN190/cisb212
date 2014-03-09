#include <stdio.h>
#include <string.h>

//this should be included in function file.
struct list {
	int x = 0, carry = 0;
	p_list next = NULL, prev = NULL;
};
typedef struct list* p_list;

//convert a char in str to int.
int str_to_int( char c ) {
	int x = c - '0';
	if ( 0 <= x && x <= 9 ) return c - '0';
	else return -1;
}

//create a node.
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

//insert a node.
void insert( p_list this ) {
	p_list p = this;

	//insert and pointer rolls back.
	new( this );
	this->next = p->next; this->prev = p;
	p->next = this; this = p;
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
void read( p_list this) {
	char str;
	int i;
	//no header necessary.

	//no limitation of digit length.
	fgets( str, ,stdin );
	//while str[i] != EOF.
	for ( i = 0; i < strlen(str); i++ ) {
		int x = str_to_int( str[i] );

		//recognize a digit.
		if ( x >= 0 && x <= 9) {
			new( this );
			this->x = x;
		} else
		return "error: not a digit!\nprogram terminated.\n";
	}
	fflush( stdin ); //clear stdin buffer.
}

//main function.
void main() {
	p_list this = NULL;
	read( this );

	return 0;
}
