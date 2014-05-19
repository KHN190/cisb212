       #include "test.h"
       #include <stdlib.h>
       #include <stdio.h>
       
       #define MinTableSize (10)

        struct node
        {
            ElementType Element;
            p_list    Next;
        };

        typedef p_list key;

        /* List *TheList will be an array of lists, allocated later */
        /* The lists use headers (for simplicity), */
        /* though this wastes space */
        struct HashTbl
        {
            int TableSize;
            key* keys;
        };

        /* Return next prime; assume N >= 10 */
        static int
        NextPrime( int N )
        {
            int i;

            if( N % 2 == 0 )
                N++;
            for( ; ; N += 2 )
            {
                for( i = 3; i * i <= N; i += 2 )
                    if( N % i == 0 )
                        goto ContOuter;  /* Sorry about this! */
                return N;
              ContOuter: ;
            }
        }

        /* Hash function for ints */
        Index
        Hash( ElementType Key, int TableSize )
        {
            return Key % TableSize;
        }

/* START: fig5_8.txt */
        HashTable
        InitializeTable( int TableSize )
        {
            HashTable H;
            int i;

/* 1*/      if( TableSize < MinTableSize )
            {
/* 2*/          printf( "Table size too small" );
/* 3*/          return NULL;
            }

            /* Allocate table */
/* 4*/      H = malloc( sizeof( struct HashTbl ) );
/* 5*/      if( H == NULL )
/* 6*/          printf( "Out of space!!!" );

/* 7*/      H->TableSize = NextPrime( TableSize );

            /* Allocate array of lists */
/* 8*/      H->keys = malloc( sizeof( p_list ) * H->TableSize );
/* 9*/      if( H->keys == NULL )
/*10*/          printf( "Out of space!!!" );

            /* Allocate list headers */
/*11*/      for( i = 0; i < H->TableSize; i++ )
            {
/*12*/          H->keys[ i ] = malloc( sizeof( struct node ) );
/*13*/          if( H->keys[ i ] == NULL )
/*14*/              printf( "Out of space!!!" );
                else
/*15*/              H->keys[ i ]->Next = NULL;
            }

/*16*/      return H;
        }
/* END */

/* START: fig5_9.txt */
        p_list
        Find( ElementType Key, HashTable H )
        {
            p_list P;
            key L;

/* 1*/      L = H->keys[ Hash( Key, H->TableSize ) ];
/* 2*/      P = L->Next;
/* 3*/      while( P != NULL && P->Element != Key )
                                /* Probably need strcmp!! */
/* 4*/          P = P->Next;
/* 5*/      return P;
        }
/* END */

/* START: fig5_10.txt */
        void
        Insert( ElementType Key, HashTable H )
        {
            p_list Pos, NewCell;
            key L;

/* 1*/      Pos = Find( Key, H );
/* 2*/      if( Pos == NULL )   /* Key is not found */
            {
/* 3*/          NewCell = malloc( sizeof( struct node ) );
/* 4*/          if( NewCell == NULL )
/* 5*/              printf( "Out of space!!!" );
                else
                {
/* 6*/              L = H->keys[ Hash( Key, H->TableSize ) ];
/* 7*/              NewCell->Next = L->Next;
/* 8*/              NewCell->Element = Key;  /* Probably need strcpy! */
/* 9*/              L->Next = NewCell;
                }
            }
        }
/* END */

        ElementType
        Retrieve( p_list P )
        {
            return P->Element;
        }

        void
        DestroyTable( HashTable H )
        {
            int i;

            for( i = 0; i < H->TableSize; i++ )
            {
                p_list P = H->keys[ i ];
                p_list Tmp;

                while( P != NULL )
                {
                    Tmp = P->Next;
                    free( P );
                    P = Tmp;
                }
            }

            free( H->keys );
            free( H );
        }

        void readfile(HashTable H) {
            char c = '\b';
            int x;
            FILE *fp;
            if (fp = fopen("data100.txt", "r")) {
                while (c != EOF) {
                    fscanf( fp, "%d", &x );
                    Insert(x, H); c = fgetc( fp );
                }
               fclose(fp);
            } else {
                printf("cannot find file \"data100.txt\".\n");
                exit(0);
            }
        }

        void check(ElementType Key, HashTable H) {
            p_list p = Find(Key,H);
            if (p) printf("%-10d found!\n", Key );
            else printf("%-10d not found!\n", Key);
        }

        void traverse(HashTable H) {
            int size = H->TableSize;
            int probe;

            p_list p;
            while (1,size>=0,size--) {
                probe = 0;
                p = H->keys[size]->Next;
                while (p) {
                    printf("%-6d", p->Element);
                    probe++;
                    p = p->Next;
                }
                if (!probe) printf("none ");
                printf("probes: %d\n", probe);
            }
        }