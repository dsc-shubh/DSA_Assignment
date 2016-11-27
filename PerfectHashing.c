
/*
	Name: Perfect Hashing
	Copyright: 
	Author: Hemant Pandey
	Date: 04/11/16 14:58
	Description: each numbers are of 10 digit long and p>>>m and 1<a,b<p
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define SIZE 5
#define HTSIZE (2*SIZE)
long long int Prime[]={5915587277,		
		1500450271,
		3267000013,
		5754853343,
		4093082899,
		9576890767,
		3628273133,
		2860486313,
		5463458053,
		3367900313
		};
long long int A,B,P;
struct response{
	long long int a,b,p;
};
struct Hash{
	int key;
	long long int a,b,p;
	long long int *next;
};

struct List{
	int v;
	struct List *next;
};

struct response * setABP(long long int *,struct Hash *);
void ShowHashTable(struct Hash *FirstLevel){
	
	printf("Printing Hash Table in form of Ni a b p ->Secondary Level Hash table:\n ");
	int i;
	long long int *itr,t;
	for(i=0;i<HTSIZE;i++){
		printf("Ni:%d a:%lld b:%lld p:%llld ",FirstLevel[i].key,FirstLevel[i].a,FirstLevel[i].b,FirstLevel[i].p);
		itr=FirstLevel[i].next;
		if(FirstLevel[i].key<=0)
			continue;
		t=FirstLevel[i].key*FirstLevel[i].key;
		while(t--!=1){
			printf("-> %lld",*itr);
		}
		printf("\n");
	}
}

int main(){
	srand(time(NULL));
	long long int n[SIZE];
	int i;
	struct Hash *FirstLevel=(struct Hash*)malloc(sizeof(struct Hash)*HTSIZE);
		
	for(i=0;i<SIZE;i++)
		scanf("%lld",&n[i]);
	//setting A B P for first kevel Hashing
	struct response *ABP=setABP(n,FirstLevel);
	A=ABP->a;
	B=ABP->b;
	P=ABP->p;
	//printf("A:%lld B:%lld P:%lld\n",A,B,P);
	struct List **br;
	br=(struct List **)malloc(sizeof(struct List *)*HTSIZE);
	for(i=0;i<HTSIZE;i++)
		br[i]->next=NULL;
	long long int t;	
	for(i=0;i<SIZE;i++){
		t=((A*n[i]+B)%P)%HTSIZE;	
		struct List *newnode;
		newnode->v=n[i];
		newnode->next=br[t]->next;
		br[t]->next=newnode;
	}
	
	for(i=0;i<HTSIZE;i++){
		int flag=0;
		long long int *temp;
		int STS=FirstLevel[i].key*FirstLevel[i].key;
		struct List *it;
		it=br[i];
		it=it->next;		
		temp=(long long int *)calloc(STS,sizeof(long long int));
		while(flag!=1){
			long long int a,b,p,val;
			a=rand();
			b=rand();
			p=Prime[rand()%10];
			flag=1;
			while(it->next!=NULL&&flag==1){				
				val=((a*it->v+b)%p)%STS;
				if(temp[val]!=0){
					flag=0;
					it=br[i];										
					free(temp);
					break;
				}
				else{
					temp[val]=it->v;
					it=it->next;
				}					
			}
			if(flag==1){
				FirstLevel[i].next=temp;
				FirstLevel[i].a=a;
				FirstLevel[i].b=b;
				FirstLevel[i].p=p;								
			}
		}
	}
	
	//ShowHashTable(FirstLevel);
	return 0;
}


struct response * setABP(long long int n[],struct Hash *FirstLevel){
	srand(time(NULL));
	int i,k;
	long long int a,b,p;
	struct response *abp=(struct response *)malloc(sizeof(struct response));
	while(1){
		for(i=0;i<HTSIZE;i++)
			FirstLevel[i].key=0;
		a=rand();
		if(a<0)
			a*=-1;
		b=rand();
		if(b<0)
			b*=-1;
		p=Prime[rand()%10];
		for(i=0;i<SIZE;i++){
			k=((a*n[i]+b)%p)%HTSIZE;
			FirstLevel[k].key++;
		}					
		long long int sumNi=0;
		int flag=0;
		for(i=0;i<HTSIZE;i++){
			sumNi+=((FirstLevel[i].key)*(FirstLevel[i].key));
			if(sumNi>HTSIZE){
				flag=1;
				break;
			}
		}
		if(flag==0){			
			abp->a=a;
			abp->b=b;
			abp->p=p;
		//	printf("%lld  %lld  %lld",a,b,p);
			break;
		}
										
	}
	printf("\n");
	for(i=0;i<HTSIZE;i++)
			printf("%lld ",FirstLevel[i].key);
	return abp;
}
