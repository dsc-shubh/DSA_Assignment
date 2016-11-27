
/*
	Name: Red Black Tree Deletion
	Copyright: 
	Author: Hemant Pandey
	Date: 03/11/16 14:56
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

void Delete();
struct Node* Successor(struct Node *);
void FixDelete(struct Node *);
void RotateLeft(struct Node *);
void RotateRight(struct Node *);

struct Node *Root=NULL;
int main(){	
	printf("\n Red Black Tree Deletion:\n");
	while(1){
		printf("For Deletion press 1 otherwise press any key......\n");
		int choice;
		scanf("%d",&choice);
		if(choice!=1)
			break;
		else
		Delete();
		
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


void Delete(){
	 if(Root==NULL){
        printf("\nEmpty Tree." );
        return;
    }
    int x;
    printf("\nEnter the key of the node to be deleted: ");
    scanf("%d",&x);
    struct Node *p;
    p=Root;
    struct Node *y=NULL;
    struct Node *q=NULL;
    int found=0;
     while(p!=NULL&&found==0){
        if(p->data==x)
            found=1;
        if(found==0){
            if(p->data<x)
                p=p->right;
	        else
                p=p->left;
        }
    }
    if(found==0){
        printf("\nElement Not Found.");
        return;
    }
    else{
        printf("\nDeleted Element: %d",p->data);
        printf("\nColour: ");
        if(p->color=='B')
     		printf("Black\n");
    	else
     		printf("Red\n");

        if(p->parent!=NULL)
            printf("\nParent: %d",p->parent->data);
		else
            printf("\nThere is no parent of the node.  ");
        if(p->right!=NULL)
            printf("\nRight Child: %d",p->right->data);
        else
            printf("\nThere is no right child of the node.  ");
        if(p->left!=NULL)
            printf("\nLeft Child:  %d",p->left->data);
        else
            printf("\nThere is no left child of the node.  ");
        printf("\nNode Deleted.");
        if(p->left==NULL||p->right==NULL)
            y=p;
        else
            y=Successor(p);
        if(y->left!=NULL)
            q=y->left;
        else{
            if(y->right!=NULL)
                q=y->right;
            else
                q=NULL;
        }
        if(q!=NULL)
            q->parent=y->parent;
        if(y->parent==NULL)
            Root=q;
        else{
            if(y==y->parent->left)
                y->parent->left=q;
            else
                y->parent->right=q;
        }
        if(y!=p){
            p->color=y->color;
            p->data=y->data;
        }
        if(y->color=='B')
            FixDelete(q);
    }
}

struct Node* Successor(struct Node *p){
	struct Node *y=NULL;
    if(p->left!=NULL){
        y=p->left;
        while(y->right!=NULL)
        	y=y->right;
    }
    else{
        y=p->right;
        while(y->left!=NULL)
            y=y->left;
    }
    return y;
}

void FixDelete(struct Node *p){
	struct Node *s;
    while(p!=Root&&p->color=='B')
    {
        if(p->parent->left==p)
        {
            s=p->parent->right;
            if(s->color=='R')
            {
                s->color='B';
                p->parent->color='R';
                RotateLeft(p->parent);
                s=p->parent->right;
            }
            if(s->right->color=='B'&&s->left->color=='B')
            {
                s->color='R';
                p=p->parent;
            }
            else
            {
                if(s->right->color=='B')
                {
                    s->left->color=='B';
                    s->color='R';
                    RotateRight(s);
                    s=p->parent->right;
            	}
                s->color=p->parent->color;
                p->parent->color='B';
   	            s->right->color='B';
                RotateLeft(p->parent);
                p=Root;
            }
        }
    	else
        {
            s=p->parent->left;
            if(s->color=='R')
            {
                s->color='B';
                p->parent->color='R';
                RotateRight(p->parent);
                s=p->parent->left;
	        }
            if(s->left->color=='B'&&s->right->color=='B')
           {
                s->color='R';
                p=p->parent;
            }
            else
            {
                if(s->left->color=='B')
                {
                    s->right->color='B';
                    s->color='R';
                    RotateLeft(s);
                    s=p->parent->left;
                }
                s->color=p->parent->color;
                p->parent->color='B';
                s->left->color='B';
                RotateRight(p->parent);
                p=Root;
            }
          }
       p->color='B';
       Root->color='B';
    }
}
