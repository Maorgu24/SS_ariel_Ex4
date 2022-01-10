#include "edges.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

node* New(int data, node *next, pedge edges){
    node *p = (node*) malloc (sizeof(node));
    memset(p, 0, sizeof(node));
    p->node_num = data;
    p->edges = edges;
    p->next = next;
    return p;
}

edge* New1(int weight, edge *next, struct GRAPH_NODE_ **head1,int nodeId,pnode point){
    edge *p = (edge*) malloc (sizeof(edge));
    memset(p, 0, sizeof(edge));
    p->weight = weight;
    p->endpoint = New(nodeId,NULL,NULL);
    p->next = next;
    return p;
}

void Insertlastp(struct GRAPH_NODE_ **head,struct edge_ **head_edge){
    struct GRAPH_NODE_ **p = head;
    while((*p)->next){
        p = &((*p)->next);
    }
    (*p)->edges = *head_edge;
}

void InsertL(int weight, struct GRAPH_NODE_ **headNode,int nodeId, struct edge_ **head){
    struct edge_ **p = head;
    while(*p){
        p = &((*p)->next);
    }
    *p = New1(weight,NULL,headNode,nodeId,NULL);
}

void RemoveEdge(pedge head_edge){
    edge *p = head_edge;
    edge **prev = &head_edge;
    while(p){
        *prev = p->next;
        F(p);
        p = *prev;
    }
}

pedge GetEdge(int id, struct GRAPH_NODE_ **head){
    struct GRAPH_NODE_ **p1 = head;
    while(*p1){
        if((*p1)->node_num == id){
            if((*p1)->edges->next == NULL){
                return NULL;
            }
            return (*p1)->edges;
        }
        p1 = &((*p1)->next); 
    }
    return NULL;
}

int GetWeight(struct GRAPH_NODE_ **head1,int src,int dest){
    struct GRAPH_NODE_ ** h1 = head1;
    while(*h1){
        if((*h1)->node_num == src){
            if((*h1)->edges == NULL){
                return -1;
            }
            else{
                pedge head_edge = ((*h1)->edges);
                if(head_edge != NULL){
                    if((head_edge)->endpoint != NULL){
                        while(head_edge){
                            if((head_edge)->endpoint-> node_num == dest){
                                return (head_edge)->weight;
                            }                 
                            head_edge = ((head_edge)->next);
                        }
                    }
                    else{
                        return -1;
                    }
                }
                else{
                    return -1;
                }
            }
        }
        h1 = &((*h1)->next);
    }
    return -1;
}