/*
	Name: Breadth First Traversal 
	Copyright: 
	Author: Hemant Pandey
	Date: 23/10/16 14:09
	Description: using adjacency list ripresentation of graph Run Time:O(V+E)
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Graph{
	int V;
	int E;
	int *AdjMatrix;
};

struct lListNode{
	int val;
	struct lListNode *next;
};

int main(){
	
	return 0;
}


//Adjacency List represntation
struct Graph *adjListOfGraph(){
	int i,x,y;
	struct lListNode *t;
	struct Graph *G=(struct Graph *)malloc(sizeof(struct Graph));
	
	//enter no of vertices and no of edges
	scanf("%d%d",&G->V,&G->E);
	
	G->AdjMatrix=malloc(sizeof(lListNode)*G->V);
	
	for(i=0;i<G->V;i++){
		G->AdjMatrix[i]=(struct lListNode *)malloc(sizeof(struct llListNode)*G->V);
		G->AdjMatrix[i]->val=i;
		G->AdjMatrix[i]->next=G->AdjMatrix[i];
	}
	
	for(i=0;i<G->E;i++){
		//reading edges
		scanf("%d%d",&x,&y);
		t=(struct lListNode *)malloc(sizeof(lListNode));
		t->val=y;
		t->next=G->AdjMatrix[x];
		G->AdjMatrix[x]->next=t;
		
		t=(struct lListNode *)malloc(sizeof(struct lListNode));
		t->val=x;
		t->next=G->AdjMatrix[y];
		G->AdjMatrix[y]->next=t;
	}
	
	return G;
}
