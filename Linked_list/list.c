#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"

//	RECEIVE COMMANDS FROM STDIN
int revCom( p_list H ) {

	char c, t;
	
	print(H);

	printf("ENTER:\n>b: DELETE EVEN POSITIONS\n>c: FIND 100\n\
>d: PRINT ODD POSITIONS\n>e: REVERSE LIST\n");

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
		double_del(H); return 1;
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
		reverse(H); return 1;
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
	if (!fp) {
		printf("FILE IS NOT FOUND.\n\n");
		return NULL;
	}
	
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
		printf("ERROR: NULL LINKED LIST!\n\n");
		return;
	}

	printf("The table is:\n");

	while ( p->next ) {
		printf( "%6d", p->x );
		p = p->next;
	} printf( "%6d\n\n", p->x );
}

// REVERSE A LIST
void reverse(p_list H) {
	p_list S = H->next;	// START
	p_list p = S;

	if (S == NULL) {
		printf("ERROR: NULL LINKED LIST!\n\n");
		return;
	} else {
		while (1) {
			if (S->next == NULL)
				break;	// NEW HEADER
			while (p->next)
				p = p->next;	// FIND THE LAST NODE

			p->prev->next = NULL;
			p->prev = S->prev; S->prev->next = p;
			p->next = S; S->prev = p;
			p = S;
		}
	} return;
}

// PRINT ODD POSITIONS
void odd_print(p_list H) {

	p_list p = H->next;	// START FROM THE NODE 0

	if (p == NULL) {
		printf("ERROR: NULL LINKED LIST!\n\n");
		return;
	}
	if (p->next == NULL) {	// THE NODE 1
		printf("ERROR: ONE NODE ONLY!\n\n");
		return;
	} p = p->next;

	while (1) {

		if (p == NULL)
			break;
		else if (p->next == NULL) {	// EVEN (NEXT) POSITION IS NULL
			printf("%6d\n", p->x);	// END
			p = NULL;
		} else {
			printf("%6d", p->x);
			p = p->next->next;	// JUMP TO ODD POSITION
		} printf("\n");
	} return;
}

// DELETE EVEN POSITIONS
void double_del(p_list H) {
	p_list p = H->next;
	p_list t;

	if (p == NULL) {
		printf("ERROR: NULL LINKED LIST!\n\n");
		return;
	}

	while (1) {

		if (p == NULL)
			break;
		else if (p->next == NULL) {	// NEXT POSITION IS NULL
			p->prev->next = NULL;
			free(p); p = NULL;	// END
		} else {
			p->next->prev = p->prev;
			p->prev->next = p->next;
			t = p->next->next;	// JUMP
			free(p); p = t;
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
