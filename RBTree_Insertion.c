
/*
	Name: Red Black Tree Insertion
	Copyright: 
	Author: Hemant Pandey
	Date: 04/11/16 14:57
	Description: 
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Node{
	int data;
	char color;
	struct Node *left;
	struct Node *right;
	struct Node *parent;
};

void Insert(int );
void FixInsert(struct Node *);
void RotateLeft(struct Node *);
void RotateRight(struct Node *);

struct Node *Root=NULL;
int main(){
	printf("\n Red Black Tree Insertion:\n");
	while(1){
		printf("For Insertion press 1 otherwise press any key......\n");
		int choice;
		scanf("%d",&choice);
		if(choice!=1)
			break;
		int data;
		scanf("%d",&data);
		Insert(data);
	}
	return 0;
}

void RotateLeft(struct Node *p){
	if(p->right==NULL)
           return;
    else{
           struct Node *t=p->right;
           if(t->left!=NULL)
           {
                p->right=t->left;
                t->left->parent=p;
           }
           else
                p->right=NULL;
           	if(p->parent!=NULL)
                t->parent=p->parent;
           	if(p->parent==NULL)
                Root=t;
           	else{
               	if(p==p->parent->left)
                    p->parent->left=t;
               	else
                    p->parent->right=t;
           		}	
           t->left=p;
           p->parent=t;
    }
}

void RotateRight(struct Node *p){
	if(p->left==NULL)
        return;
    else
     {
        struct Node *t=p->left;
        if(t->right!=NULL)
         	{
                p->left=t->right;
                t->right->parent=p;
         	}
        else
            p->left=NULL;
        if(p->parent!=NULL)
            t->parent=p->parent;
        if(p->parent==NULL)
        	Root=t;
        else
         	{
            if(p==p->parent->left)
                p->parent->left=t;
            else
                p->parent->right=t;
         	}
        t->right=p;
        p->parent=t;
     }
}

void Insert(int data){
	struct Node* temp=(struct Node *)malloc(sizeof(struct Node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	temp->color='R';
	
	struct Node *t1,*t2;
	t1=Root;
	t2=NULL;
	if(Root==NULL){
		Root=temp;
		temp->parent=NULL;
	}
	else{
        while(t1!=NULL){
            t2=t1;
            if(t1->data<temp->data)
                t1=t1->right;
            else
                t1=t1->left;
        }
        temp->parent=t2;
        if(t2->data<temp->data)
            t2->right=temp;
        else
            t2->left=temp;
    }
    FixInsert(temp);
}

void FixInsert(struct Node *p){	
	if(Root==p){
		p->color='B';
		return;
	}
	struct Node *U,*G;
	while(p->parent!=NULL&&p->parent->color=='R'){
		G=p->parent->parent;
		if(G->left==p->parent){
                if(G->right!=NULL){
                    U=G->right;
                    if(U->color=='R'){
                        p->parent->color='B';
                        U->color='B';
                        G->color='R';
                        p=G;
                    }
                }
                else{
                    if(p->parent->right==p){
                        p=p->parent;
                        RotateLeft(p);
                    }
                    p->parent->color='B';
                    G->color='R';
                    RotateRight(G);
                }
        }
        else{
                if(G->left!=NULL){
                    U=G->left;
                    if(U->color=='R'){
                        p->parent->color='B';
                        U->color='B';
                        G->color='R';
                        p=G;
                    }
                }
                else{
                    if(p->parent->left==p){
                        p=p->parent;
                        RotateRight(p);
                    }
                    p->parent->color='B';
                    G->color='R';
                    RotateLeft(G);
                }
           	}
           Root->color='B';
	}
}
