#ifndef _list_h

typedef struct STACK* sp;
struct STACK {
	int x;
	sp next;
};

sp push(int x, sp S);
sp pop(sp S);
void enumerate(sp S);

#endif