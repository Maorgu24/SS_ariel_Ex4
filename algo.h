#include "nodes.h"

// Creates a new distance - for shortest_path
node_dis* NewDis(int data, int dis) ;

// insert in Last the new distance
void InsertDis2(int edge,int node_m, struct GRAPH_NODE_DISTANCE **head) ;

// Change the value of the distance
void ChangeDis(int src, struct GRAPH_NODE_DISTANCE **head, int data);

// get the value of the distance
int DisID(int id, struct GRAPH_NODE_DISTANCE **head);

// remove char from str
void RemoveChar(char *str, char charto) ;

// Get the shortest path between src and dest
int ShortestP(struct GRAPH_NODE_ **head1, int src, int dest,int size);

// remove distance
void DeleteDis( struct GRAPH_NODE_DISTANCE ** h,int id) ;

// size of path
int SizePath(struct GRAPH_NODE_DISTANCE **path);

// The function checks which route is the shortest (with the least weight).
 // According to the list given when the first value of the route is given.
void TpsShortest(struct GRAPH_NODE_ **head1,int* node_lst,struct GRAPH_NODE_DISTANCE **path, int size,int sizeH);

// The function checks length route is the shortest (with the least weight).
// Which passes through all the points
int TSP(struct GRAPH_NODE_ **head1, int* node_lst,int size,int sizeH);

// delete all distance
void DeleteDisA(struct GRAPH_NODE_DISTANCE **head);
