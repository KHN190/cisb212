#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

#define GRAPH_DATA "graphdata.txt"

int main()
{
	/* Define the Graph */
	int Size;
	Size = GetSize( GRAPH_DATA );

	Graph G;
	G = MakeGraph( Size );

	/* Append Arcs */
	GetArcs(G, GRAPH_DATA);

	/* Print Graph */
	PrintGraph(G);

	/* Topological Sort */
	VertexType *Degree;
	Degree = InDegree(G);

	puts("\nDepth First Topological Sort");
	DfsTopSort(Degree, G);

	return 0;
}