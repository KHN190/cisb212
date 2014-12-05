typedef int VertexType;

#ifndef _Prim_H

struct VertexNode;
typedef struct VertexNode *VertexNodePtr;

struct GraphStruct;
typedef struct GraphStruct *Graph;

struct VertexNode
{
	int Visited;
    VertexType Vertex;
};

struct GraphStruct
{
    int GraphSize;
    int **Distance;
    VertexNodePtr *Vertices;
};

Graph MakeGraph( int Size );
void DestroyGraph( Graph G );

int **SetDistance( int Size );
void MinSpanTree( Graph G );
int *FindMinArc( Graph G );

#endif /* _Prim_H */