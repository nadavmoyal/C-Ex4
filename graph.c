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
        scanf("%d\n",&GraphSize);
        scanf("%c",&t);
        if(t=='n'){
            pnode Added =Add_Node(head);
            Add_Edge(head,&Added);
            printf("PRINTUOSH");
                    }
    }
}


pnode Add_Node(pnode *head){
    int NodeId=0;
    if(scanf("%d",&NodeId)==1);
    pnode p= *head; 
    int CurrId=-1;
    int f=0;
    while(p){
        CurrId=p->node_num;
        if(CurrId==NodeId){
            f=1;
            break;
        }
        p=p->next;
    }
       pnode NewNode;
        NewNode->node_num=NodeId;
        NewNode->next=NULL; 
    if(f==0){ // if the node isn't exsist. 
        p= *head;
        while(p){
            p=p->next;
        }
        p->next=NewNode;
    }
    if(f==1){
        NewNode=NULL;
    }
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

void Add_Edge(pnode *head ,pnode *src){
     pnode dest=Add_Node(head);
     int w; 
     scanf("%d",&w);
     pedge p = (pedge) malloc(sizeof(edge));
     p->next=(*src)->edges;
     p->weight=w;
     p->endpoint=dest;
     (*src)->edges=p;
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


