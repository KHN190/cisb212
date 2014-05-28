/* START: fig4_16.txt */
        #ifndef _Tree_H

        struct TreeNode;
        typedef struct TreeNode* Position;
        typedef struct TreeNode* SearchTree;

        SearchTree MakeEmpty( SearchTree T );
        Position Find( int X, SearchTree T );
        Position FindMin( SearchTree T );
        Position FindMax( SearchTree T );
        SearchTree Insert( int X, SearchTree T );
        SearchTree Delete( int X, SearchTree T );
        int Retrieve( Position P );

        SearchTree BuildTree(SearchTree T);
        SearchTree HandleTree(SearchTree T);
        Position FindMin2( SearchTree T );
        Position Find2( int X, SearchTree T );
        SearchTree Insert2( int X, SearchTree T );

        void Inorderprint( SearchTree T ); /* added by xqw */
        int Height( SearchTree T ); /* added by xqw */
        int Leaves( SearchTree T ); /* added by xqw */

        #endif  /* _Tree_H */

/* END */
