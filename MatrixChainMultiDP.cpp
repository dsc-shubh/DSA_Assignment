#include<bits/stdc++.h>
using namespace std;
int main(){
	cout<<"Enter length of array of dimension"<<endl;
	int N;
	cin>>N;
	int dim[N+1];

	for(int i=1;i<=N;i++)
		cin>>dim[i];
	int mul,j;
	int m[N+1][N+1];
	for(int i=1;i<=N;i++)
		m[i][i]=0;
	for(int l=2;l<=N;l++){
		for(int i=1;i<=N-l+1;i++){
			j=i+l-1;
			m[i][j]=INT_MAX;
			for(int k=i;k<=j-1;k++){
				mul=m[i][k]+m[k+1][j]+dim[i-1]*dim[k]*dim[j];
				if(mul<m[i][j])
					m[i][j]=mul;
			}
		}
	}
	
	cout<<"optimal min number of multiplication is:"<<endl;
	cout<<m[0][N];
	return 0;
}
