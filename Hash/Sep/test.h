/* Interface for separate chaining hash table */
typedef int ElementType;

/* START: fig5_2.txt */
        typedef unsigned int Index;
/* END */

/* START: fig5_7.txt */
        #ifndef _HashSep_H

        struct node;
        typedef struct node *p_list;
        struct HashTbl;
        typedef struct HashTbl *HashTable;

        HashTable InitializeTable( int TableSize );
        void DestroyTable( HashTable H );
        p_list Find( ElementType Key, HashTable H );
        void Insert( ElementType Key, HashTable H );
        ElementType Retrieve( p_list P );
        /* Routines such as Delete are MakeEmpty are omitted */
        void check(ElementType Key, HashTable H);
        void traverse(HashTable H);

        #endif  /* _HashSep_H */
/* END */