#include<bits/stdc++.h>
using namespace std;
int N,S;
int main(){
	cin>>N>>S;
	int Data[N];
	int p;
	for(int i=0;i<N;i++){
		cin>>p;
		Data[i]=p;
	}
	
	//Subset sum
	bool TableMemo[N+1][S+1];
	for(int i=0;i<=S;i++)
		TableMemo[0][i]=false;
	TableMemo[0][0]=true;
	for(int i=1;i<=N;i++){
		TableMemo[i][0]=true;
		for(int j=1;j<=S;j++){
			if(Data[i]<=S)
				TableMemo[i][j]=TableMemo[i-1][j-Data[i]]||TableMemo[i-1][j];
			else
				TableMemo[i][j]=TableMemo[i-1][j];
		}
	}			
	if(TableMemo[N][S])
		cout<<"Sum :"<<S<<" using coins from given :"<<N<<" coins can be made";
	else
		cout<<"Sum :"<<S<<" using coins from given :"<<N<<" coins can not be made";
	return 0;
}
