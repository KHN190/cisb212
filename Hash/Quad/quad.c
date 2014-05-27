        /* hashquad.c modified to support "lazy deletion" */
       
        #include "quad.h"
        #include <stdlib.h>
        #include <stdio.h>
        
        #define MinTableSize (10)

        enum KindOfEntry { Legitimate, Empty, Deleted };

        struct HashEntry
        {
            ElementType      Element;
            enum KindOfEntry Info;
        };

        typedef struct HashEntry Cell;

        /* Cell *TheCells will be an array of */
        /* HashEntry cells, allocated later */
        struct HashTbl
        {
            int TableSize;
            Cell *TheCells;
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

/* START: fig5_15.txt */
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

            /* Allocate array of Cells */
/* 8*/      H->TheCells = malloc( sizeof( Cell ) * H->TableSize );
/* 9*/      if( H->TheCells == NULL )
/*10*/          printf( "Out of space!!!" );

/*11*/      for( i = 0; i < H->TableSize; i++ )
/*12*/          H->TheCells[ i ].Info = Empty;

/*13*/      return H;
        }
/* END */

/* START: fig5_16.txt */
        Position
        Find( ElementType Key, HashTable H )
        {
            Position CurrentPos;
            int CollisionNum;

/* 1*/      CollisionNum = 0;
/* 2*/      CurrentPos = Hash( Key, H->TableSize );
/* 3*/      while( H->TheCells[ CurrentPos ].Info != Empty &&
                   ! ( H->TheCells[ CurrentPos ].Element == Key &&
                       H->TheCells[ CurrentPos ].Info==Legitimate) )
                            /* Probably need strcmp!! */
            {
/* 4*/          CurrentPos += 2 * ++CollisionNum - 1;
/* 5*/          if( CurrentPos >= H->TableSize )
/* 6*/              CurrentPos -= H->TableSize;
            }
            if (H->TheCells[ CurrentPos ].Info == Deleted)
                return 0;
            else
/* 7*/          return CurrentPos;
        }
/* END */

        Position
        FindPosition( ElementType Key, HashTable H )
        {
            Position CurrentPos;
            int CollisionNum;

/* 1*/      CollisionNum = 0;
/* 2*/      CurrentPos = Hash( Key, H->TableSize );
/* 3*/      while( H->TheCells[ CurrentPos ].Element != Key &&
                   H->TheCells[ CurrentPos ].Info==Legitimate ) 
                            /* Probably need strcmp!! */
            {
/* 4*/          CurrentPos += 2 * ++CollisionNum - 1;
/* 5*/          if( CurrentPos >= H->TableSize )
/* 6*/              CurrentPos -= H->TableSize;
                        /* better use CurrentPos = CurrentPos % H->TableSize */
            }
            if (H->TheCells[ CurrentPos ].Info == Deleted)
                return 0;
            else
/* 7*/          return CurrentPos;
        }
/* END */

/* START: fig5_17.txt */
        void
        Insert( ElementType Key, HashTable H )
        {
            Position Pos;

            Pos = FindPosition( Key, H );
            if( H->TheCells[ Pos ].Info != Legitimate )
            {
                /* OK to insert here */
                H->TheCells[ Pos ].Info = Legitimate;
                H->TheCells[ Pos ].Element = Key;
                         /* Probably need strcpy! */
            }
        }
/* END */

/* START: fig5_22.txt */
        HashTable
        Rehash( HashTable H )
        {
            int i, OldSize;
            Cell *OldCells;

/* 1*/      OldCells = H->TheCells;
/* 2*/      OldSize  = H->TableSize;

            /* Get a new, empty table */
/* 3*/      H = InitializeTable( 2 * OldSize );

            /* Scan through old table, reinserting into new */
/* 4*/      for( i = 0; i < OldSize; i++ )
/* 5*/          if( OldCells[ i ].Info == Legitimate )
/* 6*/              Insert( OldCells[ i ].Element, H );

/* 7*/      free( OldCells );

/* 8*/      return H;
        }
/* END */


        ElementType
        Retrieve( Position P, HashTable H )
        {
            return H->TheCells[ P ].Element;
        }

        void
        DestroyTable( HashTable H )
        {
            free( H->TheCells );
            free( H );
        }

        void readfile( HashTable H ) {
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

        void Delete( ElementType Key, HashTable H ) {

            Position Pos;
            Pos  = FindPosition( Key, H );
            H->TheCells[ Pos ].Info = Deleted;
        }

        void check(ElementType Key, HashTable H) {
            Position Pos = FindPosition(Key,H);
            if (Pos) printf("%-6d found!\n",Key);
            else printf("%-6d not found!\n",Key);
        }