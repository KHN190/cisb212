#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// PUSH AN ELEMENT INTO THE STACK
sp push(int x, sp S) {
	// S IS THE STACK TOP
	sp top = malloc(sizeof(struct STACK));

	// CHECK SPACE ALLOCATABLE
	if (top == NULL) {
		fputs("ERROR: no space available!\n", stderr);
		abort();
	} else {
	// ALLOCATE THE NODE AS TOP OF STACK
		top->x = x;
		top->next = S;
		S = top;
	} return S;
}
// POP AN ELEMENT OUT OF THE STACK
sp pop(sp S) {
	// RECEIVE THE ELEMENT AND THE TOP
	sp top = S;

	// IF STACK IS NOT EMPTY
	if (S) {
		// MOVE SP AND DEL
		S = S->next;
		free(top);
	} else {
	// STACK IS EMPTY
		fputs("ERROR: stack is empty!\n", stderr);
		abort();
	} return S;	// RETURN -1 IF ERROR OCCURS
}

int main() {
	char line[64];
	size_t size = 64;
	int t, x, i;
	sp S = NULL;

	// GETLINE FROM STDIN AND PUSH INTO STACK
	if (fgets(line, size, stdin) == NULL) {
		printf("ERROR WITH THE INPUT LINE!\n");
		abort();
    } else {
        // STORE THE CHARACTER IN THE LINE (AS INT)
    	t = 0;
    	while(line[t] != '\n') t++;

    	for (i = t-1; i >= 0; i--) {
    		x = line[i] - '0';
    		S = push(x, S);
    		printf("counting: %d, x is: %c\n", i, x+'0');
    	}
    }

    // CALCULATE THE POSTFIX
    enumerate(S);
    return 0;
}


void enumerate(sp S) {
// CALCULATE THE STACK AND REPORT ERROR IF ENCOUNTER
	int x, y, o, result;
	sp Temp = NULL;

	printf("\n");
	while (S) {
	// POP THE ELEMENT AND OPERATE
		x = S->x; S = pop(S);
		if (S == NULL && Temp == NULL) { result = x; break; }
		else {
			// WAIT FOR AN OPERATOR
			while (1) {
				if (x<=9 && x>=0) {
					if (S == NULL) {
						fputs("ERROR: operator missing.\n", stderr);
						abort();
					}
					printf("number: %d\n", x);
					Temp = push(x, Temp);
					x = S->x; S = pop(S);
				// IS AN OPERATOR
				} else {
					o = x;
					printf("o: %c\n", o+'0');
					y = Temp->x; Temp = pop(Temp);
					x = Temp->x; Temp = pop(Temp);
					// DO THE OPERATION
					switch (o) {
						case '+'-'0':
							x += y; y = 0; break;
						case '-'-'0':
							x -= y; y = 0; break;
						case '*'-'0':
							x *= y; y = 0; break;
						case '/'-'0':
							x /= y; y = 0; break;
						default:
							fputs("ERROR: incorrect spelling.\n", stderr);
							abort();
					} // PUSH THE INSTANT INTO STACK
					if (S) push(x, S);
					else if (Temp == NULL) { result = x; break; }
				}
			}
		}
	} // PRESENT THE RESULT
	printf("RESULT IS: %-5d\n", result);
	return;
}
