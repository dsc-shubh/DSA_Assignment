#include<bits/stdc++.h>
#include<cstring>
using namespace std;
char String1[1000],String2[1000];
int min(int x,int y){
	return x>y?y:x;
}
int main(){
	cin>>String1;
	cin>>String2;
	int L1=strlen(String1),L2=strlen(String2);
	int delCost,upCost,addCost;
	cin>>addCost>>delCost>>upCost;
	int minCost[L1+1][L2+1];
	for(int i=0;i<=L2;i++)
		minCost[0][i]=i*addCost;
	for(int i=1;i<=L1;i++){
		minCost[i][0]=i*delCost;
		for(int j=1;j<=L2;j++){
			if(String1[i]==String2[j])
				minCost[i][j]=minCost[i-1][j-1];
			else{
				minCost[i][j]=min(minCost[i-1][j-1]+upCost,min(minCost[i-1][j]+delCost,minCost[i][j-1]+addCost));
			}
		}
	}
	
	cout<<"Total min cost inorder to convert String1 into String2"<<minCost[L1+1][L2+1]<<endl;
	return 0;
}
