#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "prim.h"

#define PATH "data.txt"
#define GRAPH_SIZE 7
#define INF 1024

Graph MakeGraph( int Size )
{
	Graph G;
	G = malloc( sizeof (struct GraphStruct) );

	if ( !G )
	{
		puts("Out of space!!!");
		exit(-1);
	}

	G->GraphSize = Size;
	G->Distance = SetDistance( Size );

	G->Vertices = malloc( sizeof (VertexNodePtr) * Size);
	
	if ( !G->Vertices )
	{
		puts("Out of space!!!");
		exit(-1);
	}
	
	int i;
	for ( i = 0; i < Size; ++i )
	{
		G->Vertices[ i ] = malloc( sizeof( struct VertexNode ) );
		G->Vertices[ i ]->Visited = 0;
		G->Vertices[ i ]->Vertex = i;
	}

	return G;
}

void DestroyGraph( Graph G)
{
	int i;
	for ( i = 0; i < G->GraphSize; ++i )
	{
		free( G->Vertices[ i ] );
		free( G->Distance[ i ] );
	}
	free( G->Vertices );
	free( G->Distance );
	free( G );
}

int **SetDistance( int Size )
{
	FILE *fp;
	fp = fopen(PATH, "r+");

	if (!fp)
	{
		puts("cannot open file");
		exit(-1);
	}

	int i, d, j;
	int **adj;

	adj = malloc(sizeof(int *)*Size);
	for ( i = 0; i < Size; ++i )
		adj[ i ] = malloc(sizeof(int)*Size);

	// initialization
	for ( i = 0; i < Size; ++i )
		for ( j = 0; j < Size; ++j )
			adj[ i ][ j ] = -1;

	// set arcs
	while ( !feof(fp) )
	{
		fscanf(fp, "%d %d %d", &i, &d, &j);
		adj[i-1][j-1] = d;
		adj[j-1][i-1] = d;
	}

	for (i=0; i<Size; ++i)
	{
		for (j=0; j<Size; ++j)
			printf("%3d ", adj[ i ][ j ]);
		puts("");
	}

	return adj;
}

int *FindMinArc( Graph G )
{
	int i, j, m, a, b;
	int *arc = malloc( sizeof( int ) * 2 );
	m = INF;

	// for all visited nodes
	for ( i = 0; i < G->GraphSize; ++i )
	{
		if ( G->Vertices[ i ]->Visited )
		{
			// traverse all unvisited adjacent nodes
			for ( j = 0 ; j < G->GraphSize; ++j )
			{
				if ( !G->Vertices[ j ]->Visited )
				{
					// find the minima
					if ( m > G->Distance[ i ][ j ] &&
						G->Distance[ i ][ j ] != -1 )
					{
						m = G->Distance[ i ][ j ];
						a = i; b = j;
					}
				}
			}
		}
	}
	// no node is visited
	if ( m == INF )
	{
		for ( i = 0; i < G->GraphSize; ++i )
		{
			for ( j = 0 ; j < G->GraphSize; ++j )
			{
				if ( m > G->Distance[ i ][ j ] && 
					G->Distance[ i ][ j ] != -1 )
				{
					m = G->Distance[ i ][ j ];
					a = i; b = j;
				}
			}
		}
	}
	// printf(">> min arc is %d\n", m);

	G->Vertices[ a ]->Visited = 1;
	G->Vertices[ b ]->Visited = 1;
	// restore the arc
	arc[0] = a; arc[1] = b;
	return arc;
}

void MinSpanTree( Graph G )
{
	int cnt;
	// find all arcs (V - 1)
	for ( cnt = 0; cnt < G->GraphSize - 1; ++ cnt )
	{
		int *arc = FindMinArc( G );
		printf("arc %d to %d:  distance is %d\n", 
			arc[0]+1, arc[1]+1, G->Distance[ arc[0] ][ arc[1] ]);
	}
}

int main()
{
	puts("\n--- Adjacent Matrix ---");
	Graph G = MakeGraph( GRAPH_SIZE );
	
	puts("\n--- Minimal Spanning Tree ---");
	MinSpanTree( G );
	return 0;
}