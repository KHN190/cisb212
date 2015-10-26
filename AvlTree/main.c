// 4. Implement AVL tree insertion operation and code double rotations directly. 
// 5. Insert the numbers in the example p114-119 in the same order as in the textbook, and print out in preorder. 
// 6. Insert the numbers in data 10000 into an AVL tree and calculate the height of the tree.

#include "avltree.h"
#include <stdio.h>
#include <stdlib.h>

main( )
{
    AvlTree T;
    int i, cur;

    // insert numbers in the textbook order
    T = MakeEmpty( NULL );
    T = Insert( 3, T );
    T = Insert( 2, T );
    T = Insert( 1, T );
    T = Insert( 4, T );
    T = Insert( 5, T );
    T = Insert( 6, T );
    T = Insert( 7, T );
    T = Insert( 16, T );
    T = Insert( 15, T );
    T = Insert( 14, T );
    T = Insert( 13, T );
    T = Insert( 12, T );
    T = Insert( 11, T );
    T = Insert( 10, T );
    T = Insert( 8, T );
    T = Insert( 9, T );

    printf( "Height is %d\n", Height( T ) );
    printf( "Min is %d, Max is %d\n", Retrieve( FindMin( T ) ),
               Retrieve( FindMax( T ) ) );

    // print in preorder
    PrintTree( T );
    printf("\n");

    // insert numbers in data10000
    T = MakeEmpty( T );

    FILE * fp = fopen("data10000", "rb+");
    if (!fp) 
    {
        puts("ERROR: Failed to open file.");
        exit(-1);
    }
    for ( i = 0; i < 10000; ++i )
    {
        fscanf(fp, "%d", &cur);
        T = Insert(cur, T);
    }

    printf( "\nHeight is %d\n", Height( T ) );
    printf( "Min is %d, Max is %d\n", Retrieve( FindMin( T ) ),
               Retrieve( FindMax( T ) ) );

    return 0;
}
