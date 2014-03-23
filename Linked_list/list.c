// linked list functions are included in link_A function file.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"

// create a node.
p_list new( p_list link_A ) {
	// use link_A, link_A->next, link_A->prev to modify "link_A" in list node.
	p_list next = ( p_list )malloc( sizeof( struct node ) );
	next->prev = link_A;
	if ( link_A ) link_A->next = next;
	
	// initial.
	next->x = 0; next->carry = 0;
	next->next = NULL;

	return next;
}

// delete a list node.
void del( p_list link_A ) {
	p_list p = link_A; link_A = p->prev;

	// in case it's link_A header of list.
	if ( link_A ) link_A->next = p->next;
	else printf( "link_A last element distinct on earth!\n" );

	free( p );
}

// insert a node.
p_list insert( p_list link_A ) {
	p_list p = link_A;

	// insert and pointer rolls back.
	link_A = new( link_A );
	link_A->next = p->next; link_A->prev = p;
	p->next = link_A; link_A = p;

	return p;
}

// link print function.
void print( p_list p) {
	// print from the header.
	while ( p->prev ) p = p->prev;
	while ( p->x == 0 ) p = p->next;
	while ( p->next ) {
		printf( "%d", p->x );
		p = p->next;
	} printf( "%d\n", p->x );
} // now it points to link's last node.
