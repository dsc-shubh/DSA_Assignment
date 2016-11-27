#include<bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;
void DijikstraShortestPathUG(vector<list<pair<int,int>>> &Adj,int source);
int vertices, edges,source;

int main()
{
    int v1, v2, weight;     
   	cout<<"Enter the Number of Vertices"<<endl;
    cin>>vertices;
    source=1;
    cout<<"Enter the Number of Edges"<<endl;
    cin>>edges;    
    vector<list<pair<int,int>>> adjacencyList(vertices+1);     
    cout<<"Enter the Edges V1 <-> V2, of weight W"<<endl;
     
    for (int i = 1; i <= edges; ++i) {
        cin>>v1 >>v2 >>weight;       
        adjacencyList[v1].push_back(make_pair(v2, weight));
        adjacencyList[v2].push_back(make_pair(v1, weight));
    }
    
    //Finding Minimum distance of all vertices from source vertices    
    DijikstraShortestPathUG(adjacencyList,source);
    return 0;
}

void DijikstraShortestPathUG(vector<list<pair<int,int>>> &Adj,int source){
	int weight;
	//pair<int,int> have value <vertex,distance>
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > MinHeap;
	vector<int> Distance(vertices+1,INF);
	MinHeap.push(make_pair(0,source));
	Distance[source]=0;
	while(!MinHeap.empty()){
		int u=MinHeap.top().second;
		MinHeap.pop();
		list<pair<int,int>>::iterator it;
		it=Adj[u].begin();
		while(it!=Adj[u].end()){
			int v=(*it).first;
			int weight=(*it).second;
			if(Distance[v]>Distance[u]+weight){
				Distance[v]=Distance[u]+weight;
				MinHeap.push(make_pair(Distance[v],v));
			}
			it++;
		}
	}
	cout<<"Vertex   Distance form Source :"<<source<<endl;
	int i;
	for(i=1;i<=vertices;i++)
		cout<<i<<"          "<<Distance[i]<<endl;
	return;
}
