#include "algo.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
typedef int bool;
#define True 1
#define False 0

bool CMD_Delete(struct GRAPH_NODE_ **head1){
    int nodeId;
    char b;
    bool test_end = False;
    if(scanf("%c", &b) == EOF){
        return False;
    }
    if(b == ' '){
        if(scanf("%c", &b) == EOF){
            return False;
        }
    }
    nodeId= -1;
    while(b != ' ' && b!= '\n'){
        if(nodeId != -1){
            nodeId = (nodeId*10) + (b -'0');
        }
        else{
            nodeId = b -'0';
        }
        if(scanf("%c", &b) == EOF){
            test_end = True; break;
        }
        if(b == '\n'){
            test_end= True;break;
        }
    }
    DeleteNodeAll(head1,nodeId);
    return test_end;
}

bool CMD_Shortest(struct GRAPH_NODE_ **head1,int size){
    char b;
    char c;
    bool test_end = False;
    int num1 = -1;
    int num2 = -1;
    if(scanf("%c", &b) == EOF){
        return False;
    }
    if(b == ' '){
        if(scanf("%c", &b) == EOF){
            return False;
        }
    }
    while(b != ' '&& b != '\n'){
        if(num1 != -1){
            num1 = (num1*10) + (b -'0');
        }
        else{
            num1 = b -'0';
        }
        if(scanf("%c", &b) == EOF){
            return False;
        }
        if(b == '\n'){
            return False;
        }
    }
    if(scanf("%c", &c) == EOF){
        return False;
    }
    while(c != ' ' && c != '\n' ){
        if(num2 != -1){
            num2 = (num2*10) + (c -'0');
        }
        else{
            num2 = c -'0';
        }
        if(scanf("%c", &c) == EOF){
            test_end= True;break;
        }
        if(c == '\n'){
            test_end= True;break;
        }
    }
    int dis = ShortestP(head1,num1,num2,size);
    printf("Dijsktra shortest path: %d \n",dis);
    return test_end;
}

bool CMD_Tsp(struct GRAPH_NODE_ **head1,int size){
    char k;
    bool test_end = False;
    if(scanf("%c", &k) == EOF){
        return False;
    }
    if(k == ' '){
        if(scanf("%c", &k) == EOF){
            return False;
        }
    }
    int sizeTsp = -1;
    while(k != ' ' && k!= '\n'){
        if(sizeTsp != -1){
            sizeTsp = (sizeTsp*10) + (k -'0');
        }
        else{
            sizeTsp = k -'0';
        }
        if(scanf("%c", &k) == EOF){
            return False;
        }
        if(k == '\n'){
            return False;
        }
    }
    int path[sizeTsp];
    memset(path, 0, sizeTsp);
    int *path2 = path;
    char r;
    for(int h=0;h<sizeTsp;h++){
        if(scanf("%c", &r) == EOF){
            return False;
        }
        if(r == ' '){
            if(scanf("%c", &r) == EOF){
                return False;
            }
        }
        int num = -1;
        while(r != ' ' && r != '\n'){
            if(num != -1){
                num = (num*10) + (r -'0');
            }
            else{
                num = r -'0';
            }
            if(scanf("%c", &r) == EOF){
                test_end= True;break;
            }
            if(r == '\n'){
                test_end= True;break;
            }
        }
        path2[h] = num;
    }
    int minTSPr = TSP(head1,path,sizeTsp,size);
    printf("TSP shortest path: %d \n",minTSPr);
    return test_end;
}

void Dup(struct GRAPH_NODE_ ** h) {
    struct GRAPH_NODE_ ** h1 = h;
    pedge head = ((*h1)->edges);
    while(head){
        head = ((head)->next);
    }
}

void AddConnect(struct GRAPH_NODE_ **head111){
    struct GRAPH_NODE_ **head_node = head111;
    struct GRAPH_NODE_ ** h1 = head111;
    while(*h1){
        if((*h1)->edges != NULL){
            pedge head_edge = ((*h1)->edges);
            if(head_edge != NULL){
                if((head_edge)->endpoint != NULL){
                    while(head_edge){
                        if((head_edge)->endpoint != NULL){
                            while(*head_node){
                                if((head_edge)->endpoint-> node_num == (*head_node)->node_num){
                                    pnode f = (head_edge)->endpoint;
                                    if((head_edge)->endpoint->edges == NULL && (head_edge)->endpoint->next == NULL){
                                        RemoveNode(f);
                                    }
                                    (head_edge)->endpoint = (*head_node);
                                } 
                                head_node = &((*head_node)->next);
                            }
                            head_node = head111;
                        }
                        head_edge = ((head_edge)->next);
                    }
                }
            }
        }
        h1 = &((*h1)->next);
    }
}

void RemoveNode(pnode head_edge){
    node *p = head_edge;
    node **prev = &head_edge;
    while(p){
        *prev = p->next;
        free(p);
        p = *prev;
    }
}
void PrintGraph( struct GRAPH_NODE_ ** h){
    struct GRAPH_NODE_ ** h1 = h;
    while(*h1){
        printf("%d",(*h1)->node_num);
        pedge head = ((*h1)->edges);
        if(head->endpoint != NULL){
            while(head){
                printf("%d",(head)->endpoint->node_num);
                printf("%d",(head)->weight);
                head = ((head)->next);
            }
        }
        printf("\n");
        h1 = &((*h1)->next);
    }
}

void DeleteA( struct GRAPH_NODE_ ** h) {
    struct GRAPH_NODE_ ** h2 = h;
    if(! *h2 ){
        return;
    }
    while(*h2){
        pedge head_edge = (*h2)->edges;
        if((head_edge)->endpoint != NULL){
            edge *p = head_edge;
            edge **prev = &head_edge;
            while(p){
                *prev = p->next;
                free(p);
                p = *prev;
                (*h2)->edges=p;
            }
            free((*h2)->edges);
        }
        else{
            free(head_edge);
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
        *prev1 = p1->next;
        
        free(p1);
        p1 = *prev1;
    }
}
