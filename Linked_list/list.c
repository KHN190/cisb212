#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"

//	RECEIVE COMMANDS FROM STDIN
int revCom( p_list H ) {

	char c, t;
	
	printf("ENTER:\n>b >c >d >e\n");

	while ((t = getchar())) {
		if ( t != '\n' ) break;
	}	// ERADICATE LINES

	if ( t == '\n' )
		c = fgetc(stdin);
	else
		c = t;

	if (c == 'b') {
		//	DELETE EVEN POSITIONS ELEMENTS
		//	FIRST REALL NODE IS THE 0TH POSITION
		printf("\nDELETE EVEN POSITIONS.\n");
		double_del(H); print(H); return 1;
	}
	else if (c == 'c') {
		//	FIND IF 100 IN THE LIST
		printf("\nFIND INTEGER 100.\n");
		int i = find(H, 100);
		if (i) { printf("100 FOUND!\n"); return 1; }
		else { printf("NOT FOUND!\n"); return 1; }
	}
	else if (c == 'd') {
		//	PRINT ODD POSITIONS
		printf("\nPRINT ODD POSITIONS.\n");
		odd_print(H); return 1;
	}
	else if (c == 'e') {
		//	REVERSE THE LIST
		printf("\nREVERSE THE LIST.\n");
		reverse(H); print(H); return 1;
	}
	else {
		//	COMMAND NOT FOUND
		printf("\nCOMMAND NOT FOUND.\n");
		return 0;
	}
}

////////////////////////////////////////////////////
//												  //
//					FILE OPERATION				  //
//												  //
////////////////////////////////////////////////////

// FILE MODE
FILE * fp;

// READ FROM INPUT FILE AND GENERATE LIST
p_list read( p_list H) {

	fp = fopen("data100.txt", "r");
	if (!fp)
		printf("FILE IS NOT FOUND.\n");
	
	H = new(H);		// CREATE HEADER
	p_list L = H;	// START FROM GIVEN HEADER

	char c = '\b', b;
	int x = 0, t;

	while ( fscanf( fp, "%c", &b ) ) {
		if ( b != ('\t' || '\b' || '\n') ) break;
	}	// ERADICATE LINES AND BLANKS
	
	while ( c != EOF ) {
		fscanf( fp, "%d", &x );
		c = fgetc( fp );	// CHECK BLANKS AND EOF

		// CONFIRM VALIDATION AND NEW A NODE
		L = new( L );
		L->x = x;
	}
	return H;	// COMPELETE
}

////////////////////////////////////////////////////
//												  //
//					LIST OPERATION				  //
//												  //
////////////////////////////////////////////////////

// CREATE NEW NODE
p_list new( p_list l ) {

	p_list next = ( p_list )malloc( sizeof( struct node ) );

	if ( l ) l->next = next;
	
	// INIT
	next->x = 0;
	next->next = NULL;
	next->prev = l;

	return next;
}

void print( p_list H ) {

	p_list p = H->next;

	if (p == NULL) {
		printf("ERROR: NULL LINKED LIST!\n");
		return;
	}

	while ( p->next ) {
		printf( "%10d", p->x );
		p = p->next;
	} printf( "%10d\n", p->x );
}

// REVERSE A LIST
void reverse(p_list H) {
	p_list S = H->next;	// START
	p_list p = S;

	if (S == NULL) {
		printf("ERROR: NULL LINKED LIST!\n");
		return;
	} else {
		while (1) {
			if (S->next == NULL)
				break;	// NEW HEADER
			while (p->next)
				p = p->next;	// FIND THE LAST NODE

			p->prev->next = NULL;	// SWAP
			p->next = S; p->prev = H;
			H->next = p;
			S->prev = p; S = p;
		}
	} return;
}

// PRINT ODD POSITIONS
void odd_print(p_list H) {
	p_list p = H->next;

	if (p == NULL) {
		printf("ERROR: NULL LINKED LIST!\n");
		return;
	}
	if (p->next == NULL) {
		printf("ERROR: ONE NODE ONLY!\n");
		return;
	} p = p->next;

	while (1) {

		if (p->next == NULL || p == NULL)
			break;
		else if (p->next == NULL) {
			printf("%10d", p->x);
			p = p->next->next;
		} else {
			printf("%10d\n", p->x);
			p = NULL;
		}
	} return;
}

// DELETE EVEN POSITIONS
void double_del(p_list H) {
	p_list p = H->next;
	p_list t;

	if (p == NULL) {
		printf("ERROR: NULL LINKED LIST!\n");
		return;
	}

	while (1) {

		if (p->next == NULL || p == NULL)
			break;
		else {

			p->next->prev = p->prev;

			if (p->next->next) {
				p->prev->next = p->next;
				t = p->next->next;
				free(p); p = t;
			}
			else {
				p->prev->next = NULL;
				free(p); p = NULL;
			}
		}
	} return;
}

// FIND AN ELEMENT IN LINKED LIST
int find(p_list H, int i) {

	p_list S = H->next;

	while (S) {
		if (S->x == i)
			return 1;	// FOUND
		else
			S = S->next;
	} return 0;	// NOT FOUND
}
