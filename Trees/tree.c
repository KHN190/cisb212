        #include "tree.h"
        #include <stdlib.h>
        #include <stdio.h>

        struct TreeNode
        {
            int Element;
            SearchTree  Left;
            SearchTree  Right;
        };

/* START: fig4_17.txt */
        SearchTree
        MakeEmpty( SearchTree T )
        {
            if( T != NULL )
            {
                MakeEmpty( T->Left );
                MakeEmpty( T->Right );
                free( T );
            }
            return NULL;
        }
/* END */

/* START: fig4_18.txt */
        Position
        Find( int X, SearchTree T )
        {
            if( T == NULL )
                return NULL;
            if( X < T->Element )
                return Find( X, T->Left );
            else
            if( X > T->Element )
                return Find( X, T->Right );
            else
                return T;
        }
/* END */

/* START: fig4_19.txt */
        Position
        FindMin( SearchTree T )
        {
            if( T == NULL )
                return NULL;
            else
            if( T->Left == NULL )
                return T;
            else
                return FindMin( T->Left );
        }
/* END */

/* START: fig4_20.txt */
        Position
        FindMax( SearchTree T )
        {
            if( T != NULL )
                while( T->Right != NULL )
                    T = T->Right;

            return T;
        }
/* END */

/* START: fig4_22.txt */
        SearchTree
        Insert( int X, SearchTree T )
        {
/* 1*/      if( T == NULL )
            {
                /* Create and return a one-node tree */
/* 2*/          T = malloc( sizeof( struct TreeNode ) );
/* 3*/          if( T == NULL )
/* 4*/              printf( "Out of space!!!" );
                else
                {
/* 5*/              T->Element = X;
/* 6*/              T->Left = T->Right = NULL;
                }
            }
            else
/* 7*/      if( X < T->Element )
/* 8*/          T->Left = Insert( X, T->Left );
            else
/* 9*/      if( X > T->Element )
/*10*/          T->Right = Insert( X, T->Right );
            /* Else X is in the tree already; we'll do nothing */

/*11*/      return T;  /* Do not forget this line!! */
        }
/* END */

        // FindMin, Find and Insert without recursion

        Position FindMin2( SearchTree T ) {

            while (T) {
                if (T->Left == NULL)
                    return T;
                else
                    T = T->Left;
            } return T;
        }

        Position Find2( int X, SearchTree T ) {

            if( T == NULL )
                return NULL;
            while (T) {
                if ( X < T->Element )
                    T =  T->Left;
                else if ( X > T->Element )
                    T = T->Right;
                else
                    return T;
            } return T;
        }

        SearchTree Insert2( int X, SearchTree T ) {

            Position Root = T;
            Position new;

            if( T == NULL ) {

                T = malloc( sizeof( struct TreeNode ) );
                if( T == NULL )
                    printf( "Out of space!!!" );
                else {

                    T->Element = X;
                    T->Left = T->Right = NULL;
                    return T;
                }
            }
            else {

                new  = malloc( sizeof( struct TreeNode ) );
                new->Element = X;
                new->Left = new->Right = NULL;

                while (1) {
                    if ( X < T->Element ) {

                        if (T->Left)
                            T =  T->Left;
                        else {
                            T->Left = new;
                            break;
                        }
                    } else if ( X > T->Element ) {

                        if (T->Right)
                            T =  T->Right;
                        else {
                            T->Right = new;
                            break;
                        }
                    } else
                        break;
                }
            } return Root;
        }

/* START: fig4_25.txt */
        SearchTree
        Delete( int X, SearchTree T )
        {
            Position TmpCell;

            if( T == NULL )
                printf( "Delete element not found" );
            else
            if( X < T->Element )  /* Go left */
                T->Left = Delete( X, T->Left );
            else
            if( X > T->Element )  /* Go right */
                T->Right = Delete( X, T->Right );
            else  /* Found element to be deleted */
            if( T->Left && T->Right )  /* Two children */
            {
                /* Replace with smallest in right subtree */
                //TmpCell = FindMin( T->Right );
                TmpCell = FindMin2( T->Right );
                T->Element = TmpCell->Element;
                T->Right = Delete( T->Element, T->Right );
            }
            else  /* One or zero children */
            {
                TmpCell = T;
                if( T->Left == NULL ) /* Also handles 0 children */
                    T = T->Right;
                else if( T->Right == NULL )
                    T = T->Left;
                free( TmpCell );
            }

            return T;
        }
/* END */

        int
        Retrieve( Position P )
        {
            return P->Element;
        }

/* added by xqw */

        void Inorderprint (SearchTree T) 
        {
           if (T!=NULL)
             { Inorderprint(T->Left);
               printf("%d ",T->Element);
               Inorderprint(T->Right);
             }
        }

        SearchTree BuildTree(SearchTree T) {
            char c = '\b';
            int x;
            FILE *fp;
            if (fp = fopen("data100.txt", "r")) {
                while (c != EOF) {
                    fscanf( fp, "%d", &x );
                    // T = Insert(x, T); c = fgetc( fp );
                    T = Insert2(x, T); c = fgetc( fp );
                }
               fclose(fp);
            } else {
                printf("Cannot find file \"data100.txt\".\n");
                exit(0);
            } return T;
        }

        SearchTree HandleTree(SearchTree T) {
            char c = '\b';
            int x, index;
            FILE *fp;
            if (fp = fopen("data100.txt", "r")) {
                index = -1;
                while (c != EOF) {
                    fscanf( fp, "%d", &x );
                    index++;
                    if ((index != 0) && (index % 5 == 0))
                        T = Delete(x, T);
                    c = fgetc( fp );
                }
               fclose(fp);
            } else {
                printf("Cannot find file \"data100.txt\".\n");
                exit(0);
            } return T;
        }