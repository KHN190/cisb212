// 1. Insert odd position elements of data10000 into one leftlist heap, and insert even position elements of data10000 into another leftlist heap. 
// 2. Print out the right paths of these two leftistheaps. 
// 3. Merge the above two leftist heaps. Print out the right path of the merged leftistheap. Print out the height of the merged leftistheap. 
// 4. Implement AVL tree insertion operation and code double rotations directly (do not copy two single rotations from the textbook). 
// 5. Insert the numbers in the example p114-119 in the same order as in the textbook, and print out the preorder. textbook, and print out the preorder. 
// 6. Insert the numbers in data 10000 into an AVL tree and calculate the height of the tree.

#include "leftheap.h"
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10000
#define DATA10000 "data10000"

main( )
{
    // open file
    FILE * fp = fopen(DATA10000, "rb+");
    if (!fp) 
    {
        puts("ERROR: Failed to open file.");
        exit(-1);
    }
    // create leftist heap
    PriorityQueue H1 = Initialize( );
    PriorityQueue H2 = Initialize( );
    // insert data
    int i, j;
    for( i = 1; i <= MaxSize; i++ )
    {
        fscanf(fp, "%d", &j);
        if ( i % 2 == 1 )
            Insert( j, H1 );
        else
            Insert( j, H2 );
    }
    // print right child
    PrintRightPath( H1 );
    PrintRightPath( H2 );

    // merge the leftist heaps
    PriorityQueue H = Merge(H1, H2);    
    PrintRightPath( H );
    printf("Height of the merged leftist heap: %d\n", Height( H ));

    // old leftist trees should not be used anymore
    H1 = NULL;
    H2 = NULL;

    // destroy and free space
    Destroy( H );

    return 0;
}
