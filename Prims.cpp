#include<bits/stdc++.h>
#define INF 0x7fffffff
int vertices, edges,source;
void PrimsUG(vector<list<pair<int,int>>> &Adj);
using namespace std;

int main(){
	int v1, v2, weight;     
   	cout<<"Enter the Number of Vertices"<<endl;
    cin>>vertices;
    source=1; 
    cout<<"Enter the Number of Edges"<<endl;
    cin>>edges;    
    vector< list< pair<int, int> > > adjacencyList(vertices + 1);
	vector<int> status(vertices+1,-1);    
    cout<<"Enter the Edges V1 -> V2, of weight W"<<endl;
     
    for (int i = 1; i <= edges; ++i) {
        cin>>v1 >>v2 >>weight;       
        adjacencyList[v1].push_back(make_pair(v2, weight));
        adjacencyList[v2].push_back(make_pair(v1, weight));
    }
    
    //Finding MST of a undirected Graph
    PrimsUG(adjacencyList,source);
	return 0; 
}

void PrimsUG(vector<list<pair<int,int>>> &Adj){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > MinHeap;
	vector<bool> inMST(vertices+1,false);	
	vector<int> Key(vertice+1,INF);
	vector<int> parent(vertices+1,-1);
	source=1;
	MinHeap.push(0,source);
	Key[source]=0;
	
	while(!MinHeap.empty()){
		int u=MinHeap.top().second;
		MinHeap.pop();
		inMST[u]=true;
		vector<list<pair<int,int>>>::iterator it;
		for(it=Adj[u].begin();it!=Adj[u].end();it++){
			int v=(*it).first;
			int w=(*it).second;
			if (inMST[v]==false&&key[v]>w){                
                key[v] = w;
                MinHeap.push(make_pair(key[v], v));
                parent[v] = u;
            }
		}
		
	}
	
	for (int i = 1; i < V; ++i)
        cout<<parent[i]<<"-"<<i<<endl;
}
