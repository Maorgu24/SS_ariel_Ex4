#include "graph.h"

// Creates a new node
node* New(int data, node *next, pedge edges) ;

// Creates a new Edge
edge* New1(int weight, edge *next, struct GRAPH_NODE_ **head1,int nodeId,pnode point);

// insert in Last the head Edge
void Insertlastp(struct GRAPH_NODE_ **head,struct edge_ **head_edge) ;

// insert in Last the new Edge
void InsertL(int weight, struct GRAPH_NODE_ **headNode,int nodeId, struct edge_ **head) ;

// remove Edge
void RemoveEdge(pedge head_edge) ;

// get Edge
pedge GetEdge(int id, struct GRAPH_NODE_ **head);

// get weight between src and dest
int GetWeight(struct GRAPH_NODE_ **head1,int src,int dest);