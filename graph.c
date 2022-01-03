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
    while(flag==0){
    if(scanf("%c", &c)==EOF){
        flag=1;
        break;
    }
    c=getchar();
    if( c =='A'){
        // add also a flag that tells if there is already a graph.
        scanf("%d\n",&GraphSize);
    }
        if(c=='n'){
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
     if (dest==NULL){
         return NULL;
     }
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

void Del_FirstEdge(pedge *head){
    pedge e = *head;
    if( e == NULL){
        return;
    }
    (*head)= e->next;
}

pnode SearchNode(pnode *head ,int id){
    pnode p = *head;
    while (p)
    {
        if(p->node_num==id){
            return p;
        }
        p=p->next;
    }
    return NULL;
}
void Delete_All_Edges_Of_Node (pedge *head){
    while((*head)){
        Del_FirstEdge(head);
    }
}

void B_Func(pnode *head , int id){
   if(SearchNode(*head,id)==NULL){
        Add_Node_Id(*head,id);
   }
    pnode target = SearchNode(*head,id);
    Delete_All_Edges_Of_Node(target->edges);
    // need to add the new edges.
}

void DeleteNode(pnode *head, int id){
  pnode p =SearchNode(*head ,id);
   if(p==NULL){
       return;
   } 
   if(p->node_num==(*head)->node_num){ // if its the first node. 
           (*head)= p->next;
            return;
   }
   p=*head;
   pnode prev =p;
   while(p){
       if(p->node_num==id){
           prev->next=p->next;
           return;
       }
       prev = p;
       p = p->next;
   }
}

void Delete_ALL_EdgesInto(pnode *head , int id){
    pnode p = *head;
    pedge e = p->edges;
    while(p){
       e = p->edges;
       while(e){
           if(e->endpoint->node_num==id){
               Del_Edge(*head,id,p->node_num);
           }
           e=e->next;
       }
        p=p->next;
    }
}


void D_Func(pnode *head , int id){
       if(SearchNode(*head,id)==NULL){
           return;
   }
    pnode target = SearchNode(*head,id);
   
    Delete_All_Edges_Of_Node(target->edges);
   
    Delete_ALL_EdgesInto(*head,id);
   
    DeleteNode(*head,id); 
}



