        #include "binheap.h"
        #include "fatal.h"
        #include <stdlib.h>
        #include <stdio.h>

        #define MinPQSize (10)
        #define MinData (-32767)

        #define KRED  "\x1B[31m"
        #define KGRN  "\x1B[32m"
        #define KYEL  "\x1B[33m"
        #define KBLU  "\x1B[34m"
        #define KMAG  "\x1B[35m"
        #define KCYN  "\x1B[36m"
        #define RESET "\033[0m"

        struct HeapStruct
        {
            int Capacity;
            int Size;
            int Child;
            ElementType *Elements;
        };

/* START: fig6_0.txt */
        PriorityQueue
        Initialize( int MaxElements )
        {
            PriorityQueue H;

/* 1*/      if( MaxElements < MinPQSize )
/* 2*/          Error( KRED "Priority queue size is too small" RESET );
/* 3*/      H = malloc( sizeof( struct HeapStruct ) );
/* 4*/      if( H ==NULL )
/* 5*/          FatalError( KRED "Out of space!!!" RESET );

            /* Allocate the array plus one extra for sentinel */
/* 6*/      H->Elements = malloc( ( MaxElements + 1 )
                                    * sizeof( ElementType ) );
/* 7*/      if( H->Elements == NULL )
/* 8*/          FatalError( KRED "Out of space!!!" RESET );

/* 9*/      H->Capacity = MaxElements;
/*10*/      H->Size = 0;
/*11*/      H->Elements[ 0 ] = MinData;
            H->Child = 2;

/*12*/      return H;
        }
/* END */

        PriorityQueue
        Initialize4Heap( int MaxElements )
        {
            PriorityQueue H;

            if( MaxElements < MinPQSize )
                Error( KRED "Priority queue size is too small" RESET );
            H = malloc( sizeof( struct HeapStruct ) );
            if( H ==NULL )
                FatalError( KRED "Out of space!!!" RESET );

            /* Allocate the array plus one extra for sentinel */
            H->Elements = malloc( ( MaxElements + 1 )
                                    * sizeof( ElementType ) );
            if( H->Elements == NULL )
                FatalError( KRED "Out of space!!!" RESET );

            H->Capacity = MaxElements;
            H->Size = 0;
            H->Elements[ 0 ] = MinData;
            H->Child = 4;

            return H;
        }

        void
        MakeEmpty( PriorityQueue H )
       {
            H->Size = 0;
        }

/* START: fig6_8.txt */
        /* H->Element[ 0 ] is a sentinel */

        void
        Insert( ElementType X, PriorityQueue H )
        {
            int i;

            if( IsFull( H ) )
            {
                Error( KRED "Priority queue is full" RESET );
                return;
            }

            for( i = ++H->Size; H->Elements[ i / 2 ] > X; i /= 2 )
                H->Elements[ i ] = H->Elements[ i / 2 ];
            H->Elements[ i ] = X;
        }
/* END */

        void
        Append( ElementType X, PriorityQueue H )
        {
            int i;

            if ( IsFull(H) )
            {
                Error( KRED "Priority queue is full" RESET );
                return;
            }

            i = ++H->Size;
            H->Elements[ i ] = X;
        }

/* START: fig6_12.txt */
        // ElementType
        // DeleteMin( PriorityQueue H )
        // {
        //     int i, Child;
        //     ElementType MinElement, LastElement;

        //     if( IsEmpty( H ) )
        //     {
        //         Error( KRED "Priority queue is empty" RESET );
        //         return H->Elements[ 0 ];
        //     }
        //     MinElement = H->Elements[ 1 ];
        //     LastElement = H->Elements[ H->Size-- ];

        //     for( i = 1; i * 2 <= H->Size; i = Child )
        //     {
                /* Find smaller child */
        //         Child = i * 2;
        //         if( Child != H->Size && H->Elements[ Child + 1 ]
        //                               < H->Elements[ Child ] )
        //             Child++;

        //         /* Percolate one level */
        //         if( LastElement > H->Elements[ Child ] )
        //             H->Elements[ i ] = H->Elements[ Child ];
        //         else
        //             break;
        //     }
        //     H->Elements[ i ] = LastElement;
        //     return MinElement;
        // }
/* END */

        int 
        _FirstChild( int n, int i, int j )
        {
            // parent i, has first child at level j
            return 1 + (pw(n,j) - 1) / (n-1) \
            + n * (i - ( 1 + (pw(n,j-1) - 1) / (n-1) ));
        }

        ElementType
        DeleteMin( PriorityQueue H )
        {
            int i, j, Child, height;
            ElementType MinElement, LastElement;

            if( IsEmpty( H ) )
            {
                Error( KRED "Priority queue is empty" RESET );
                return H->Elements[ 0 ];
            }
            MinElement = H->Elements[ 1 ];
            LastElement = H->Elements[ H->Size-- ];

            for( i = 1, j = 0; Child <= H->Size, j < Height( H ); ++j, i = Child )
            {
                /* Find smaller child */
                int cnt, MinChild;

                Child = _FirstChild( H->Child, i, j+1 );
                MinChild = Child;

                /* If no child */
                if ( MinChild > H->Size )
                    break;

                /* Loop through children */
                for ( cnt = 0; cnt < H->Child; ++cnt )
                {
                    if ( Child > H->Size )
                        break;

                    if ( H->Elements[ Child ] < H->Elements[ MinChild ] )
                        MinChild = Child;

                    ++Child;
                }
                Child = MinChild;

                /* Percolate one level */
                if( LastElement > H->Elements[ Child ] )
                    H->Elements[ i ] = H->Elements[ Child ];
                else
                    break;
            }
            H->Elements[ i ] = LastElement;
            return MinElement;
        }
// 
// 
        void 
        _PercolateDown( PriorityQueue H, int i )
        {
            int tmp, cnt, j;
            int Child, MinChild;

            /* Find the level */
            for ( j = 0; pw(H->Child, j+1)-1 <= H->Size; ++j )
            {
                if ( pw(H->Child, j+1)-1 >= i )
                    break;
            }

            Child = _FirstChild( H->Child, i, j+1 );
            MinChild = Child;

            /* Loop through children */
            for ( cnt = 0; cnt < H->Child; ++cnt )
            {
                if ( Child > H->Size )
                    return;

                if ( H->Elements[ Child ] < H->Elements[ MinChild ] )
                    MinChild = Child;

                ++Child;
            }
            Child = MinChild;

            /* Percolate one level */
            if( H->Elements[ i ] > H->Elements[ Child ] )
            {
                tmp = H->Elements[ i ];
                H->Elements[ i ] = H->Elements[ Child ];
                H->Elements[ Child ] = tmp;
            }

            _PercolateDown( H, Child );
        }

        void
        BuildHeap( PriorityQueue H )
        {
            int i;
            for( i = H->Size; i > 0; i-- )
                _PercolateDown( H, i );
        }
//
//

        ElementType
        FindMin( PriorityQueue H )
        {
            if( !IsEmpty( H ) )
                return H->Elements[ 1 ];
            Error( KRED "Priority Queue is Empty" RESET );
            return H->Elements[ 0 ];
        }
        int
        IsEmpty( PriorityQueue H )
        {
            return H->Size == 0;
        }

        int
        IsFull( PriorityQueue H )
        {
            return H->Size == H->Capacity;
        }

        void
        Destroy( PriorityQueue H )
        {
            free( H->Elements );
            free( H );
        }

        int
        Height( PriorityQueue H )
        {
        	int i, j;
        	for ( i = 1, j = -1; i <=  H->Size; i *= H->Child )
        	{
        		++j;
        	}
        	return j;
        }

        void 
        PrintHeap( PriorityQueue H )
        {
            // basic information
            printf( KCYN "\n\tChild:\t%d\n", H->Child);
            printf("\tHeight:\t%d\n", Height( H )); 
            printf("\tSize:\t%d\n\n" RESET, H->Size);

        	int i, j;
            int first, last;

            first = 1;

        	for ( j = 0; j <= Height( H ); ++j )
        	{
        		// find last element
                last = first + pw( H->Child, j );

        		// print a level
                printf(KGRN "%d: " RESET, j);
        		for ( i = first; i < last && i <= H->Size; ++i )
	        		printf("%d ", H->Elements[ i ]);
				puts("");
                // find first element
                first = last;
        	}
        }

        // print elements smaller than X
        void 
        _PrintSmaller( ElementType X, PriorityQueue H, int i )
        {
            // boundary check
            if ( i > H->Size ) 
                return;
            // stop condition
            if ( H->Elements[ i ] >= X )
                return;
            // print current element
            printf("%d ", H->Elements[ i ]);

            _PrintSmaller( X, H, 2*i );
            _PrintSmaller( X, H, 2*i+1 );
        }
        void
        PrintSmaller( ElementType X, PriorityQueue H )
        {
            printf("\n\tPrint all elements smaller than: %d\n\n", X);

            _PrintSmaller( X, H, 1 );
            
            puts("");
        }

        // power calculation
        int
        pw( int x, int y )
        {
            // x powers y
            if ( y <= 0 )
                return 1;

            int i, tmp;
            for ( i = 1, tmp = x; i < y; ++i )
                tmp *= x;
            return tmp;
        }

        #if 0
/* START: fig6_14.txt */
        for( i = N / 2; i > 0; i-- )
            PercolateDown( i );
/* END */
        #endif

