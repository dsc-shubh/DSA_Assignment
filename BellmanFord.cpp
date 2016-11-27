#include<bits/stdc++.h>
using namespace std;
int V,E;
void Initialization(vector<int> &Dist){
	for(int i=1;i<=V;i++)
		Dist[i]=INT_MAX;
}

int main(){
	cin>>V>>E;
	vector<pair<int,pair<int,int>>> EdgeDetail;
	int v1,v2,w;
	cout<<"Enter vetices and weight of edge joining them"<<endl;
	for(int i=1;i<=E;i++){		
		cin>>v1>>v2>>w;
		EdgeDetail.push_back(make_pair(v1,make_pair(v2,w)));
	}
	int source;
	cin>>source;
	//initialize distance of all vertices from source
	vector<int> Dist(V+1);
	Initialization(Dist);
	Dist[source]=0;			
		
	//relaxing each edges V-1 times
	vector<pair<int,pair<int,int>>>::iterator it=EdgeDetail.begin();
	for(int i=1;i<=V-1;i++){
		it=EdgeDetail.begin();
		while(it!=EdgeDetail.end()){
			int u=(*it).first;
			int v=(*it).second.first;
			int w=(*it).second.second;
			if(Dist[u]!=INT_MAX&&Dist[u]+w<Dist[v])
				Dist[v]=Dist[u]+w;
			it++;
		}
	}
	
		//checking negative weight cycle
	while(it!=EdgeDetail.end()){
			int u=(*it).first;
			int v=(*it).second.first;
			int w=(*it).second.second;
			if(Dist[u]!=INT_MAX&&Dist[u]+w<Dist[v])
				cout<<"Graph contains a negative weight cycle"<<endl;
	}
				
	
	//printing single source shortest path to all vertices from source
	cout<<"Distance of all vertices from source vertices :"<<source<<endl;
	for(int i=1;i<=V;i++)
		cout<<i<<" : "<<Dist[i]<<endl;
	return 0;
}
