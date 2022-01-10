#include "edges.h"

// insert in Last the new node
void InsertLast(int data, struct GRAPH_NODE_ **head,struct edge_ **head_edge) ;

// remove node return true if delete else false
bool DeleteNode( struct GRAPH_NODE_ ** h,int id) ;

// remove node and everything connected to it
void DeleteNodeAll( struct GRAPH_NODE_ ** h,int id);