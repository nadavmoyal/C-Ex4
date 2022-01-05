#ifndef GRAPH_
#define GRAPH_

typedef struct GRAPH_NODE_ *pnode;;

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


void run(pnode *head);
pnode Add_Node(pnode *head);
pedge Add_Edge(pnode *head ,pnode *src);
void Del_Edge(pnode *head,int DestId , int SrcId);
void Delete_node(pnode *head,int NodeId);
void printGraph_cmd(pnode head); //for self debug
void deleteGraph_cmd(pnode* head);
void shortsPath_cmd(pnode head);
void TSP_cmd(pnode head);
char B_Func(pnode *head );
void D_Func(pnode *head );
void Del_FirstEdge(pedge * head);
char n_Func(pnode * head);
pnode Add_Node_Id(pnode *head,int id);
void  Delete_ALL_EdgesInto(pnode *head , int id);
 void Delete_All_Edges_Of_Node (pedge *head);
void Delete_Helper(pedge * head ,int id);
#endif
