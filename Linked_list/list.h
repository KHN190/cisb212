#ifndef _list_h

typedef struct node* p_list;
struct node {
	int x;
	p_list next, prev;
};

p_list new( p_list l );
p_list read( p_list l);

void double_del(p_list H);
void odd_print(p_list H);
void reverse(p_list H);
void print(p_list H);
int find(p_list H, int i);
int revCom(p_list H);

#endif
