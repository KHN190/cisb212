// linked list functions are included in this function file.

#include <stdio.h>
#include <string.h>

struct list {
	int x = 0, carry = 0;
	p_list next = NULL, prev = NULL;
};
typedef struct list* p_list;

// create a node.
void new( p_list this ) {
	// use this, this->next, this->prev to modify the number in list node.
	next = ( p_list )malloc( sizeof( struct list ) );
	next->prev = this; this = next;
}

// delete a list node.
void del( p_list this ) {
	p_list p = this; this = p->prev;

	// in case it's the header of list.
	if ( this ) this->next = p->next;
	else printf( "the last element distinct on earth!\n" );

	free( p );
}

// insert a node.
void insert( p_list this ) {
	p_list p = this;

	// insert and pointer rolls back.
	new( this );
	this->next = p->next; this->prev = p;
	p->next = this; this = p;
}

// maybe need either a function of find_next and find_prev.
// and the print function.

void print( p_list p) {
	// print from the header.
	while ( p->next ) {
		printf( "%d", p.x );
		p = p->next;
	} printf( "%d\n", p.x );
} // now it points to the last node.
