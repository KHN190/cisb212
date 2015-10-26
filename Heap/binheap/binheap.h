
        typedef int ElementType;

/* START: fig6_4.txt */
        #ifndef _BinHeap_H

        struct HeapStruct;
        typedef struct HeapStruct *PriorityQueue;

        // create a heap
        PriorityQueue Initialize( int MaxElements );
        // create a 4-heap
        PriorityQueue Initialize4Heap( int MaxElements );
        // destroy a heap
        void Destroy( PriorityQueue H );
        // empty a heap
        void MakeEmpty( PriorityQueue H );
        // insert an element
        void Insert( ElementType X, PriorityQueue H ); // binary heap only
        // append an element
        void Append( ElementType X, PriorityQueue H );
        // delete the minimal element
        ElementType DeleteMin( PriorityQueue H );
        // find the minimal element
        ElementType FindMin( PriorityQueue H );
        // calculate height
        int Height( PriorityQueue H );
        // build a heap from a random array
        void BuildHeap( PriorityQueue H );
        // print a heap in order
        void PrintHeap( PriorityQueue H );
        // print smaller elements
        void PrintSmaller( ElementType X, PriorityQueue H ); // binary heap only
        // is the heap empty?
        int IsEmpty( PriorityQueue H );
        // is the heap full?
        int IsFull( PriorityQueue H );

        #endif

/* END */

