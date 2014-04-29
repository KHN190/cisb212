#include <stdio.h>
#include "queue.h"

int main( ) {

    Queue Q;
    int i;

    Q = CreateQueue();

    for( i = 0; i < 30; i++ )
        Enqueue( i, Q );

    if ( isFull(Q) )
      printf("Queue is full\n");
    else printf("Queue is not full\n");

    while( !isEmpty( Q ) )
    {
        Dequeue( Q );
        printf( "%d\n", Front( Q ) );
        Dequeue( Q );
    }

    if ( isEmpty(Q) )
      printf("Queue is empty\n");
    else printf("Queue is not empty\n");

    DisposeQueue( Q );

    return 0;
}
