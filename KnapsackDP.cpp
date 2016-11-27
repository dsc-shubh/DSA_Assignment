#include<bits/stdc++.h>
using namespace std;
int N,C;
int main(){
	cin>>N>>C;
	int Data[2][N];
	int p,w;
	for(int i=0;i<N;i++){
		cin>>w>>p;
		Data[0][i]=w;
		Data[1][i]=p;
	}
	
	//0/1 knapsack using top down approach i.e. method of memoization
	int TableMemo[N+1][C+1];
	for(int i=0;i<=C;i++)
		TableMemo[0][i]=0;
	for(int i=1;i<=N;i++){
		TableMemo[i][0]=0;
		for(int j=1;j<=C;j++){
			if(Data[0][i]<=j&&TableMemo[i-1][j-Data[0][i]]+Data[1][i]>TableMemo[i-1][j])
				TableMemo[i][j]=TableMemo[i-1][j-Data[0][i]]+Data[1][i];
			else
				TableMemo[i][j]=TableMemo[i-1][j];
		}
	}			
	
	cout<<"Maximum Profit :"<<TableMemo[N][C];
	return 0;
}
