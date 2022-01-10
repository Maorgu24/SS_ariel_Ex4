#include "nodes.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
typedef int bool;
#define True 1
#define False 0

void InsertLast(int data, struct GRAPH_NODE_ **head,struct edge_ **head_edge){
    struct GRAPH_NODE_ **p = head;
    while(*p){
        p = &((*p)->next);
    }
    *p = New(data,NULL,NULL);
}

bool DeleteNode( struct GRAPH_NODE_ ** h,int id){
    struct GRAPH_NODE_ **head_node = h;
    struct GRAPH_NODE_ ** h1 = h;
    while(*h1){
        if((*h1)->edges != NULL){
            pedge head_edge = ((*h1)->edges);
            if(head_edge != NULL){
                if((head_edge)->endpoint != NULL){
                    while(head_edge){
                        if((head_edge)->endpoint != NULL){
                            while(*head_node){
                                if((head_edge)->endpoint-> node_num == id){
                                    pnode f = (head_edge)->endpoint;
                                    if((head_edge)->endpoint->edges == NULL && (head_edge)->endpoint->next == NULL){
                                        RemoveNode(f);
                                    }
                                    (head_edge)->endpoint = New(id,NULL,NULL);
                                } 
                                head_node = &((*head_node)->next);
                            }
                            head_node = h;
                        }
                        head_edge = ((head_edge)->next);
                    }
                }
            }
        }
        h1 = &((*h1)->next);
    }
    bool delete = False;
    struct GRAPH_NODE_ ** h11 = h;
    if(! *h11 ){
        return False;
    }
    struct GRAPH_NODE_ *p = *h11;
    struct GRAPH_NODE_ **prev = h11;
    while(p){
        if(p->node_num == id){

            *prev = p->next;
            pedge head = (p->edges);
            if((head)->endpoint != NULL){
                RemoveEdge(head);
            }
            delete = True;
            free(p);
            p = *prev;
        }
        else{
            prev = &(p->next);
            p = p->next;
        }
    }
    return delete;
}

void DeleteNodeAll( struct GRAPH_NODE_ ** h,int id){
    struct GRAPH_NODE_ ** h2 = h;
    if(! *h2 ){
        return;
    }
    while(*h2){
        pedge head_edge = (*h2)->edges;
        bool first = True;
        if((head_edge)->endpoint != NULL){
            edge *p = head_edge;
            edge **prev = &head_edge;
            while(p){
                if(p->endpoint->node_num == id){
                    pnode f = (p)->endpoint;
                    if((p)->endpoint->edges == NULL && (p)->endpoint->next == NULL){
                        RemoveNode(f);
                    }
                    *prev = p->next;
                    free(p);
                    p = *prev;
                    if(first){
                        (*h2)->edges=p;
                    }
                }
                else{
                    first = False;
                    prev = &(p->next);
                    p = p->next;
                }
            }
        }
        h2 = &((*h2)->next);
    }
    struct GRAPH_NODE_ ** h11 = h;
    if(! *h11 ){
        return;
    }
    struct GRAPH_NODE_ *p1 = *h11;
    struct GRAPH_NODE_ **prev1 = h11;
    while(p1){
        if(p1->node_num == id){
            *prev1 = p1->next;
            pedge head_edge = (p1)->edges;
            edge *p = head_edge;
            edge **prev = &head_edge;
            while(p){
                *prev = p->next;
                free(p);
                p = *prev;
            }
            free(p1);
            p1 = *prev1;
        }
        else{
            prev1 = &(p1->next);
            p1 = p1->next;
        }
    }
}