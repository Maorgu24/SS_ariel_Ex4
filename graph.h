typedef struct GRAPH_NODE_ *pnode;
typedef int bool;
#define True 1
#define False 0

typedef struct edge_ {
    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;

typedef struct GRAPH_NODE_ {
    int node_num;
    pedge edges;
    struct GRAPH_NODE_ *next;
} node, *pnode;

typedef struct GRAPH_NODE_DISTANCE {
    int node_num;
    int distance;
    struct GRAPH_NODE_DISTANCE *next;
} node_dis, *pnode_dis;

// Get parameters from cmd to delete node
bool CMD_Delete(struct GRAPH_NODE_ **head1);

// Get parameters from cmd to get the shortest path between src and dest
bool CMD_Shortest(struct GRAPH_NODE_ **head1,int size);

// Get parameters from cmd to get the length route is the shortest (with the least weight).
// Which passes through all the points
bool CMD_Tsp(struct GRAPH_NODE_ **head1,int size);

void Dup( struct GRAPH_NODE_ ** h) ;

// conect all nodes and sides according to data structures
void AddConnect(struct GRAPH_NODE_ **head111);

// prints the graph
void PrintGraph( struct GRAPH_NODE_ ** h) ;

// Deletes the all graph
void DeleteA( struct GRAPH_NODE_ ** h) ;

//remove node
void RemoveNode(pnode head_edge) ;