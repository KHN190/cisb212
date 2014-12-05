#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Graph MakeGraph( int Size )
{
    Graph G;
    int i;

    G = malloc( sizeof( struct GraphStruct ) );
    if( G == NULL )
        puts( "Out of space!!!" );

    G->GraphSize = Size;

    G->Vertices = malloc( sizeof( struct HeaderNode ) * Size );
    if( G->Vertices == NULL )
        puts( "Out of space!!!" );

    for( i = 0; i < Size; i++ )
    {
        G->Vertices[ i ].Visited=0;
        G->Vertices[ i ].AdjList=NULL;
    }
    return G;
}

void PrintGraph( Graph G )
{
    int i;

    if ( G==NULL )
    {
        printf("The graph does not exist\n");
        return;
    }

    puts("");
    for( i = 0; i < G->GraphSize; i++ )
    {
        printf("vertex %d adjancent to  ", i);
        VertexNodePtr P = G->Vertices[ i ].AdjList;

        while( P != NULL )
        {
            printf("%d ", P->Vertex);
            P=P->Next;
        }
        puts("");
    }
}

void DestroyGraph( Graph G )
{
    int i;
    for( i = 0; i < G->GraphSize; i++ )
    {
        VertexNodePtr P = G->Vertices[ i ].AdjList;
        VertexNodePtr Tmp;

        while( P != NULL )
        {
            Tmp = P;
            P=P->Next;
            free( Tmp );
        }
    }

    free( G->Vertices );
    free( G );
}

void Append( Graph G, int i, int j )
{
    VertexNodePtr P = G->Vertices[ i ].AdjList;

    if ( P == NULL )
    {
        // append new vertex
        G->Vertices[ i ].AdjList = malloc( sizeof(struct VertexNode));
        G->Vertices[ i ].AdjList->Vertex = j;
        G->Vertices[ i ].AdjList->Next = NULL;
        return;
    }

    while ( P->Next != NULL )
    {
        // avoid duplication
        if (P->Next->Vertex == j)
            return;

        // move to bottom
        P = P->Next;
    }

    // append new vertex
    P->Next = malloc( sizeof(struct VertexNode) );
    P = P->Next;
    P->Vertex = j;
    P->Next = NULL;
    // return G;
}

int GetSize(char *filename)
{
    FILE *fp;
    int Size;

    fp = fopen(filename, "r+");
    if ( fp == NULL )
    {
        puts("file does not exist");
        exit(-1);
    }

    fscanf(fp, "%d", &Size);
    fclose(fp);
    return Size;
}

void GetArcs(Graph G, char *filename)
{
    int i, j;
    char line[1024];

    FILE *fp;
    fp = fopen(filename, "r+");
    if ( fp == NULL )
    {
        puts("file does not exist");
        exit(-1);
    }

    // skip first line
    fgets(line, 1024, fp);

    i = 0;
    while ( !feof(fp) )
    {
        char *num, *ptr;

        fgets(line, 1024, fp);
        // tokenize the line
        num = strtok(line, " ");

        while (num)
        {
            // cast from str to int
            j = strtol(num, &ptr, 10);
            // append arc from i to j
            Append(G, i, j);
            // end loop
            num = strtok(NULL, " ");
        }
        // change header node
        ++i;
    }
    fclose(fp);
}

VertexType *InDegree( Graph G )
{
    int Size, i;
    Size = G->GraphSize;

    VertexType *degree;

    for (i = 0; i < Size; ++i)
        degree[ i ] = 0;

    for (i = 0; i < Size; ++i)
    {
        VertexNodePtr P;
        P = G->Vertices[ i ].AdjList;
        
        while (P != NULL)
        {
            ++degree[ P->Vertex ];
            P = P->Next;
        }
    }
    return degree;
}

// print a path until max depth reached
void RecDfsTopSort( VertexType Degree[], Graph G, VertexType V )
{
    // maximum depth reached
    if (V == -1)
    {
        // printf("\n    max depth reached\n\n");
        puts("");
        DfsTopSort( Degree, G );
        return;
    }
    
    if ( !G->Vertices[ V ].Visited )
    {
        // set as visited
        G->Vertices[ V ].Visited = 1;
        // decrease in-degree
        VertexNodePtr P = G->Vertices[ V ].AdjList;
        while (P != NULL)
        {
            --Degree[ P->Vertex ];
            P = P->Next;
        }
        // print the node
        printf("%d ", V);
    }

    // visit the next
    VertexNodePtr P = G->Vertices[ V ].AdjList;
    RecDfsTopSort( Degree, G, P->Vertex );
}

void DfsTopSort( VertexType Degree[], Graph G)
{
    int i, j;
    for (i = 0; i < G->GraphSize; ++i)
    {
        // in-degree is zero and not visited
        if ( Degree[ i ] == 0 &&
            !G->Vertices[ i ].Visited )
        {
            // set as visited
            G->Vertices[ i ].Visited = 1;
            // decrease all adjacent nodes' degree
            VertexNodePtr P = G->Vertices[ i ].AdjList;
            while (P != NULL)
            {
                --Degree[ P->Vertex ];
                P = P->Next;
            }
            // print the node
            printf("%d ", i);

            // find next unvisited adj node
            P = G->Vertices[ i ].AdjList;
            
            int flag = 1;
            while ( 1 )
            {
                if ( P == NULL )
                {
                    // exhausted
                    flag = 0;
                    break;
                }
                if ( G->Vertices[ P->Vertex ].Visited )
                    P = P->Next;
                else break;
            }
            // found an unvisited adjacent node
            if ( flag )
                RecDfsTopSort( Degree, G, P->Vertex );
            else
                puts("");
            //     printf("\n    %d is exhausted\n", i);
        }
    }
    return;
}
