#include <stdio.h>
#include <stdlib.h>

typedef struct STACK* sp;
struct STACK {
	int x;
	sp next;
};

// PUSH AN ELEMENT INTO THE STACK
void push(int x, sp S) {
	// S IS THE STACK TOP
	sp node = malloc(sizeof(STACK));

	// CHECK SPACE ALLOCATABLE
	if (node == NULL) {
		fputs("ERROR: no space available!\n", stderr);
		abort();
	} else {
	// ALLOCATE THE NODE AS TOP OF STACK
		node->x = x;
		node->next = S;
		S = node;
	}
}
// POP AN ELEMENT OUT OF THE STACK
int pop(sp S) {
	// RECEIVE THE ELEMENT AND THE TOP
	int x = -1;
	sp top = S;

	// IF STACK IS NOT EMPTY
	if (S) {
		// RECEIVE THE ELEMENT AND MOVE SP AND DEL
		x = S->x;
		S = S->next;
		free(top);
	} else {
	// STACK IS EMPTY
		fputs("ERROR: stack is empty!\n", stderr);
		abort();
	} return x;	// RETURN -1 IF ERROR OCCURS
}

int main() {
	char * line = NULL;
	size_t size;
	int t, x;
	sp S;

	// GETLINE FROM STDIN AND PUSH INTO STACK
	if (getline(&line, &size, stdin) == -1) {
		printf("ERROR WITH THE INPUT LINE!\n");
		abort();
    } else {
    	// CREATE STACK
    	S = malloc(sizeof(STACK));
        // STORE THE CHARACTER IN THE LINE (AS INT)
    	t = sizeof(line);
    	for (int i = 0; i < t; i++) {
    		x = line[i] - '0';
    		push(x, S);
    	}
    }
    // CALCULATE THE POSTFIX
    enumerate(S);
    return 0;
}

void enumerate(sp S) {
// CALCULATE THE STACK AND REPORT ERROR IF ENCOUNTER
	int x, y, op, result;
	while (S) {
	// POP THE ELEMENT AND OPERATE
		x = pop(S);
		if (S == NULL) { result = x; break; }
		else {
			y = pop(S);
			if (S == NULL) {
				fputs("ERROR: operator missed.\n", stderr);
				abort();
			} else
				op = pop(S);
		} // DO THE OPERATION
		switch (op) {
			case '+'-'0':
				x += y; y = 0; break;
			case '-'-'0':
				x -= y; y = 0; break;
			case '*'-'0':
				x *= y; y = 0; break;
			case '/'-'0':
				x -= y; y = 0; break;
			default:
				fputs("ERROR: incorrect spelling.\n", stderr);
				abort();
		} // PUSH THE INSTANT INTO STACK
		if (S) push(x, S);
		else { result = x; break; }
	} // PRESENT THE RESULT
	printf("RESULT IS: %-5d\n", result);
	return;
}
