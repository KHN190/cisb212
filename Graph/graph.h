/* Interface for graph using adjacency list */

typedef int VertexType;

#ifndef _Graph_H

struct VertexNode;
typedef struct VertexNode *VertexNodePtr;

struct VertexNode
{
    VertexType Vertex;
    VertexNodePtr Next;
};

struct HeaderNode;
typedef struct HeaderNode *HeaderNodePtr;

struct HeaderNode
{
    int Visited;
    VertexNodePtr AdjList;
};

struct GraphStruct;
typedef struct GraphStruct *Graph;

struct GraphStruct
{
    int GraphSize;
    struct HeaderNode *Vertices;
};

Graph MakeGraph( int Size );
void PrintGraph( Graph G );
void DestroyGraph( Graph G );

int GetSize(char *filename);
void GetArcs(Graph G, char *filename);
void Append( Graph G, int i, int j );

VertexType *InDegree( Graph G );

void DfsTopSort( VertexType Degree[], Graph G);
void RecDfsTopSort( VertexType Degree[], Graph G, VertexType V);

#endif  /* _Graph_H */