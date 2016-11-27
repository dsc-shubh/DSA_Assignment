#include<bits/stdc++.h>
using namespace std;
int V,E;
int **T2;
int AdjMatrix[1000][1000]={INT_MAX};
void FloydWarshall(int A[][1000]){
	int T1[V+1][V+1];
	for(int i=1;i<=V;i++)
		for(int j=1;j<=V;j++)
			T1[i][j]=A[i][j];
		
	for(int k=1;k<=V;k++){
		if(k!=1){
			for(int i=1;i<=V;i++)
				for(int j=1;j<=V;j++)
					T1[i][j]=T2[i][j];
		}
		for(int i=1;i<=V;i++){
			for(int j=1;j<=V;j++){
				T2[i][j]=((T1[i][j]<T1[i][k]+T1[k][j])?T1[i][j]:T1[i][k]+T1[k][j]);
			}
		}
	}

}
int main(){
	cin>>V>>E;
	
	T2=(int **)malloc(sizeof(int *)*(V+1));
	for(int i=0;i<=V;i++)
		T2[i]=(int *)malloc(sizeof(int)*(V+1));
	int v1,v2,w;
	for(int i=1;i<=E;i++){
		cin>>v1>>v2>>w;
		AdjMatrix[v1][v2]=w;
	}	
	int APSPResult[V+1][V+1];	
	FloydWarshall(AdjMatrix);	
	//printing all pair shortest path between vertices
	for(int i=1;i<=V;i++)
		for(int j=1;j<=V;j++)
			cout<<i<<"-->"<<j<<":"<<APSPResult[i][j]<<endl;
	return 0;
}
