#include <stdio.h>
#include <string.h>
#include "list.h"

// MAIN BODY OF PROGRAM
int main() {

	p_list H = NULL;
	int flag;

	H = read(H);	// CREATE THE LIST

	while (1) {
		flag  = revCom( H );
		if ( ! flag )
			break;	// BREAK IF COMMAND EXECUTED
	}	// RECEIVE COMMAND AND EXECUTE

	return 0;
}
