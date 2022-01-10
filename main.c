#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "algo.h"
typedef int bool;
#define True 1
#define False 0
#define GRAPH_
struct GRAPH_NODE_ * graph_node1;

void ScanfEx4(){
    char X;
    char Y;
    char Z;
    int first = 0;
    int firstE = 0;
    int Sum;
    int ID;
    int W;
    int End;
    if(scanf("%c", &X) == EOF){
        return;
        }
        if(X == ' '){
            if(scanf("%c", &X) == EOF){
                return;
            }
        }
    while((X == 'A') || (X == 'T') || (X == 'S') || (X == 'D') || (X == 'B') || (X == 'n')){
        if (X == 'A')
        {
            scanf("%c", &Z);
            if(Z == ' '){
                scanf("%c", &Z);
            }
            Sum = -1;
            while(Z != ' '){
                if(Sum != -1){
                    Sum = (Sum*10) + (Z -'0');
                }
                else{
                    Sum = Z -'0';
                }
                if(scanf("%c", &Z) == EOF){
                    return;
                }
            }
            first = 0;
            if(scanf("%c", &X) == EOF){
                return;
            }
            while((X >= '0' && X <= '9') || (X == 'n')){
                struct edge_ *p;
                if(X == 'n'){
                    if(scanf("%c", &X) == EOF){
                        return;
                    }
                    if(X == ' '){
                        if(scanf("%c", &X) == EOF){
                            return;
                        }
                    }
                    ID = -1;
                    while(X != ' ' && X !='\n'){
                        if(ID != -1){
                            ID = (ID*10) + (X -'0');
                        }
                        else{
                            ID = X -'0';
                        }
                        if(scanf("%c", &X) == EOF){
                            return;
                        }
                    }
                    if(first == 0){
                        (graph_node1) = New(ID,NULL,NULL);
                    }
                    else{
                        Insert(ID,&graph_node1,NULL);
                    }
                    first += 1;
                }
                if(scanf("%c", &X) == EOF){
                    return;
                }
                firstE = 0;
                while((X >= '0' && X <= '9')){
                    End = -1;
                    while (X != ' ' && X != '\n'){
                        if(End != -1)
                        {
                            End = (End*10) + (X -'0');
                        }
                        else{
                            End = X -'0';
                        }
                        if(scanf("%c", &X) == EOF){
                            return;
                        }
                    }
                    if(scanf("%c", &Y) == EOF){
                        return;
                    }
                    W= -1;
                    while(Y != ' ' && Y != '\n'){
                        if(W != -1){
                            W = (W*10) + (Y -'0');
                        }
                        else{
                            W = Y -'0';
                        }
                        if(scanf("%c", &Y) == EOF){
                            return;
                        }
                    }
                    if(firstE == 0){
                        p = New1(W,NULL,&graph_node1,End,NULL);  
                    }
                    else{
                        InsertL(W,&graph_node1,End,&p);
                    }
                    firstE += 1;
                    if(scanf("%c", &X) == EOF){
                        return;
                    }
                }
                if(firstE == 0){
                    p = (struct edge_*) malloc (sizeof(struct edge_));
                    memset(p, 0, sizeof(struct edge_));
                }
                Insertlastp(&graph_node1,&p);
                Dup(&graph_node1);
            }
            AddConnect(&graph_node1);
        }

        if(X == 'B'){
            if(scanf("%c", &Y) == EOF){
                return;
            }
            if(Y == ' '){
                if(scanf("%c", &Y) == EOF){
                    return;
                }
            }
            ID= -1;
            while(Y != ' '){
                if(ID != -1){
                    ID = (ID*10) + (Y -'0');
                }
                else{
                    ID = Y -'0';
                }
                if(scanf("%c", &Y) == EOF){
                    return;
                }
            }
            if(scanf("%c", &X) == EOF){
                return;
            }
            bool delete = DeleteNode(&graph_node1,ID);
            if(!delete){
                Sum++;
            }
            if(first == 0){
                graph_node1=(struct GRAPH_NODE_*)malloc(sizeof(struct GRAPH_NODE_));
                memset(graph_node1, 0, sizeof(struct GRAPH_NODE_));
                (graph_node1) = New(ID,NULL,NULL);
            }
            else{
                Insert(ID,&graph_node1,NULL);
            }
            first += 1;
            struct edge_ *p;
            firstE = 0;
            if(p==NULL){
                printf("Insufficient Memory, Exiting... \n");
                return;
            }
            while((X >= '0' && X <= '9')){
                End= -1;
                while(X != ' '){
                    if(End != -1){
                        End = (End*10) + (X -'0');
                    }
                    else{
                        End = X -'0';
                    }
                    if(scanf("%c", &X) == EOF){
                        return;
                    }
                }
                if(scanf("%c", &Y) == EOF){
                    return;
                }
                W= -1;
                while(Y != ' '){
                    if(W != -1){
                        W = (W*10) + (Y -'0');
                    }
                    else{
                        W = Y -'0';
                    }
                    if(scanf("%c", &Y) == EOF){
                        return;
                    }
                }
                if(firstE == 0){   
                    p = New1(W,NULL,&graph_node1,End,NULL);
                }
                else{
                    InsertL(W,&graph_node1,End,&p);
                }
                firstE += 1;
                if(scanf("%c", &X) == EOF){
                    return;
                }
                Insertlastp(&graph_node1,&p);
            }
            AddConnect(&graph_node1);
        }

        if(X == 'D'){
            Sum--;
            bool test = CMD_Delete(&graph_node1);
            if(test == True){
                return;
            }
            if(scanf("%c", &X) == EOF){
                return;
            }
            if(X == ' '){
                if(scanf("%c", &X) == EOF){
                    return;
                }
            }
        }
        if(X == 'S'){
            bool test = CMD_Shortest(&graph_node1,Sum);
            if(test == True){
                return;
            }
            if(scanf("%c", &X) == EOF){
                return;
            }
            if(X == ' '){
                if(scanf("%c", &X) == EOF){
                    return;
                }
            }
        }
        if(X == 'T'){
            bool test = CMD_Tsp(&graph_node1,Sum);
            if(test == True){
                return;
            }
            if(scanf("%c", &X) == EOF){
                return;
            }
        } 
    }
} 

int main(){
    ScanfEx4();
    DeleteA(&graph_node1);
    F(graph_node1);
}
