#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "graph.h"

int main(){
pnode p = NULL;
run(&p);
printf("\n finish");
return 0;

}

void run (pnode *head){
    char c =0;
    char t=0;
    int temp=0;
    int flag =0; 
    int GraphSize =0;
    while(1!=0){
    if(flag == 0){
     if(scanf("%d", &temp)!=1){
            c = getchar();
        }
    }
   // scanf("%c", &c);
    if( c =='A'){
        flag=0;
        // add also a flag that tells if there is already a graph.
        scanf("%d",&GraphSize);
    }
     if(c=='n'){
         flag = 1 ;
        c = n_Func (head);

        continue;
    }
    if(c=='B'){
        flag = 1;
        c = B_Func (head);
        continue;
    }
    if(c=='D'){
         flag = 0;
       D_Func (head);
        continue;  
     }
       if(c=='T'){
         flag =0;
        T_Func(head);
         continue;
    }
    if(c=='S'){
      flag =0;
      S_Func(head);
    continue;
    }
    if(c=='K'){
            flag=0;
            pnode p = *head; 
             printf("This is the graph nodes: ");
            while(p){
               
                 printf("%d,",p->node_num);
                 p=p->next;
            }
             p = *head; 
             printf("\nThis is the graph edges: ");
            while(p){
               pedge e = p->edges;
               while(e){
                 printf("(%d ->%d) w=%d, ",p->node_num,e->endpoint->node_num,e->weight);
                 e=e->next;
               }
                 p=p->next;
            }
             printf("\n");
            continue;


    }
    
}
}
void T_Func(pnode * head){
    int NumOfNodes, start , end,temp;
    scanf("%d", &NumOfNodes);
    int array [NumOfNodes] ;
    for(int i=0;i<NumOfNodes;i++){
       scanf("%d", &temp);
       array[i]=temp;
    }
    start = array[0];
    end = array[NumOfNodes-1];
    int dist = dijikstra(head, start, end);
    printf("Dijsktra shortest path: %d", dist);
}

void S_Func(pnode * head)
{
    int start , end;
    if( scanf("%d", &start));
    if( scanf("%d", &end));
    int dist = dijikstra(head, start, end);
    printf("Dijsktra shortest path: %d", dist);
}
char n_Func(pnode * head)
{
    pnode p = Add_Node(head);
    if(p != NULL){
     Delete_All_Edges_Of_Node (&(p->edges));
    }
    char c;
    do{
        pedge Temp = Add_Edge(head, &p);
        if(Temp==NULL)
        {
            c = getchar();
            return c;
        }
    } while(1!=0);
}

pnode Add_Node(pnode *head){
    int NodeId=0;
     if(scanf("%d",&NodeId)==0){
         return NULL;
    }
    
    // printf("NodeId is %d", NodeId);
    pnode p = *head;
    if (p==NULL){
            // printf("already exsist");
            p = (pnode) malloc(sizeof(node));
            // printf("hamsus");
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

void Del_FirstEdge (pedge* head){
    pedge e = *head;
    if( e == NULL){
        return;
    }
    pedge tmp = *head;
    (*head)=tmp->next;
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
void Delete_All_Edges_Of_Node (pedge * head){  /// need to check !!!!
  
    while(*head){
        Del_FirstEdge(head);
    }
}

// void Delete_All_Edges(pnode * head){
//         pnode p = *head;
//     while (p)
//         {
//         Del_FirstEdge(p);
//       } 
  
// }

pnode Add_Node_Id(pnode *head,int id){
      pnode p = *head;
      pnode prev = p;
        while(p){
            prev=p;
            p=p->next;
        }
        pnode NewNode=(pnode) malloc(sizeof(node));
        NewNode->node_num=id;
        NewNode->next=NULL; 
        prev->next=NewNode;
    return NewNode;




}
char B_Func(pnode *head ){
    int id=0;
    scanf("%d",&id);
   pnode target = SearchNode(head,id);
   if(target==NULL){
        Add_Node_Id(head,id);
   }
   target = SearchNode(head,id);
    Delete_All_Edges_Of_Node(&(target->edges));
    // need to add the new edges.
   char c;
    do{
        pedge Temp = Add_Edge(head, &target);
        if(Temp==NULL)
        {
            c = getchar();
            return c;
        }
    } while(1!=0);
}

void DeleteNode(pnode *head, int id){
  pnode p =SearchNode(head ,id);
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
    pedge e = ((p)->edges);
    if(p == NULL){
        return;
    }
    while(p){
         e = ((p)->edges);
         if(e!=NULL){
         Delete_Helper(&(e),id);
         }
        p=p->next;
    }
}
        void Delete_Helper(pedge * head ,int id){
            pedge e = *head;
            if(e->endpoint->node_num==id){
                Del_FirstEdge(head);
                return;
            }
            pedge prev = *head;
            e=e->next;
            while(e){
                prev = *head;
                if(e->endpoint->node_num==id){
                    prev->next=e->next;
                    return;
                }
            e=e->next;
        }
        
        }
        
void D_Func(pnode *head){
     int id=0;
    scanf("%d",&id);
       if(SearchNode(head,id)==NULL){
           return;
   }
    pnode target = SearchNode(head,id);
   
     Delete_All_Edges_Of_Node(&(target->edges));
   
  Delete_ALL_EdgesInto(head,id);
   
    DeleteNode(head,id); 
}


   int dijikstra( pnode *head, int startnode,int endnode){
    pnode p = *head;
    if(p==NULL){
        return -1;
    }
    int n=0;
    while(p){
        n++;
        p=p->next;
    }
    
    int G[n][n];
   int src, dest;
   for(src=0; src<n; src++) {
      for(dest=0;dest<n;dest++) {
         G[src][dest]=0;
      }
   }
   // insert the edge's weight.
    p = *head;
    while(p){
        pedge k = p->edges; // double check.
        while(k){
            int start = p->node_num;
            int end = k->endpoint->node_num;
            G[start][end] = k->weight;
            k=k->next;
        }
        p=p->next;
    }

	int cost[n][n], distance[n], pred[n];
	int visited[n], count, mindistance, nextnode, i,j;
	for(i=0;i < n;i++)
		for(j=0;j < n;j++)
			if(G[i][j]==0)
				cost[i][j]=100000; // infinity.
			else
				cost[i][j]=G[i][j];
	
	for(i=0;i< n;i++){
		distance[i]=cost[startnode][i];
		pred[i]=startnode;
		visited[i]=0;
	}
	distance[startnode]=0;
	visited[startnode]=1;
	count=1;
	while(count < n-1){
		mindistance=100000; // infinity.
		for(i=0;i < n;i++)
			if(distance[i] < mindistance&&!visited[i])
			{
				mindistance=distance[i];
				nextnode=i;
			}
		visited[nextnode]=1;
		for(i=0;i < n;i++)
			if(!visited[i])
				if(mindistance+cost[nextnode][i] < distance[i])
				{
					distance[i]=mindistance+cost[nextnode][i];
					pred[i]=nextnode;
				}
			count++;
	}
    i=0;
   for(i=0;i < n;i++){
        if(distance[i]== 100000 ){
            distance[i]=-1;
        }
    }

	for(i=0;i < n;i++)
		if(i!=startnode)
		{
			printf("\nDistance of %d = %d", i, distance[i]);
			printf("\nPath = %d", i);
			j=i;
			do
			{
				j=pred[j];
				printf(" <-%d", j);
			}
			while(j!=startnode);
		}
        
    return distance[endnode];
}


