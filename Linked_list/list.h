#ifndef _list_h

typedef struct node* p_list;
struct node {
	int x, carry;
	p_list next, prev;
};

p_list new( p_list link_A );
void del( p_list link_A );
p_list insert( p_list link_A );
void print( p_list p);

p_list read( p_list link_A);
int str_to_int( char c );
void multi( p_list link_A, p_list link_B );
void add( p_list link_A, p_list link_B );

#endif