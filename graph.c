#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "graph.h"

int main(){
pnode p = NULL;
run(&p);
return 0;

}

void run (pnode *head){
    char c =0;
    char t=0;
    int flag =0; 
    int GraphSize =0;
    scanf("%c",&c);
    if( c =='A'){
        // add a flag that tells if there is already a graph.
        scanf("%d\n",&GraphSize);
        scanf("%c",&t);
        if(t=='n'){
            pnode Added =Add_Node(head);
            pedge e = Add_Edge(head,&Added);
           }
    }
}


pnode Add_Node(pnode *head){
    int NodeId=0;
    scanf("%d",&NodeId);
    printf("NodeId is %d", NodeId);
    pnode p = *head;
    if (p==NULL){
            p = (pnode) malloc(sizeof(node));
            printf("hamsus");
            p->edges=NULL;
            p->next=*head;
            p->node_num=NodeId;
            *head = p;
                return p;
    }
    p = *head;
    int CurrId=-1;
    while(p){
        CurrId=p->node_num;
        if(CurrId==NodeId){
            printf("already exsist");
            return p;
        }
        p=p->next;
    }
        p= *head;
        pnode prev = p;
        while(p){
            prev= p;
            p=p->next;
        }
        pnode NewNode=(pnode) malloc(sizeof(node));
        NewNode->node_num=NodeId;
        NewNode->next=NULL; 
        prev->next=NewNode;
    return NewNode;
}
void Delete_node(pnode *head,int NodeId){
    pnode p= *head; 
    pnode prev = *head;
    
    int CurrId=-1;
    int f=0;
    while(p){
        CurrId=p->node_num;
        if(CurrId==NodeId){
            f=1;
            break;
        }
        prev = p;
        p=p->next;
    }
    if(f==1){ // if the node exsist.
        prev->next= p->next; 
    }
}

// maybe write also "Find Node"..

pedge Add_Edge(pnode *head ,pnode *src){
     pnode dest=Add_Node(head);
     int w; 
     scanf("%d",&w);
     pedge p = (pedge) malloc(sizeof(edge));
     p->next=(*src)->edges;
     p->weight=w;
     p->endpoint=dest;
     (*src)->edges=p;
     return p;
}


void Del_Edge(pnode *head,int DestId , int SrcId){
    pnode p = *head;
    pnode Target ;
    int f=0;
    while(p){
        if(p->node_num==SrcId){
            f=1;
            pnode Target = p;
            break;
        }
        p=p->next;
    }
    int flag =0 ;
    if(f==1){   

        pedge res = (Target)->edges;
        pedge prev;
        while(res){
            if(res->endpoint->node_num==DestId){
                flag= 1;
                break;
            }
            prev=res;
            res=res->next;
        }
        if(flag == 1){
            prev->next=res->next;
        }
    }
}


