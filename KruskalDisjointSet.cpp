/************* Krushkal with Improved Disoint data set **********/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class DisjointSet{
    private:
        vector<int> parent;
        vector<int> rank;
    public:
        DisjointSet(int n)
        {
            parent.resize(n);
            rank.resize(n);
            for(int i=0;i<n;i++){
                parent[i]=i;
                rank[i]=1;
            }            
        }
        int findSet(int x)
        {
            while(parent[x]!=x)
                x=parent[x];
            return x;
        }
        void unionSet(int x, int y)
        {
            x=findSet(x);
            y=findSet(y);
            if(rank[x]>rank[y])
                parent[y]=x, rank[x] += rank[y];            
            else
                parent[x]=y, rank[y] += rank[x];     
        }
        bool isSameSet(int x, int y)
        {
            x=findSet(x);
            y=findSet(y);
            return x==y;
        } 
};


struct edge{
    int u,v,w;
    edge(int _src, int _dest, int _weight){
        u=_src;
        v=_dest;
        w=_weight;
    }
    bool operator < (const edge &e){
        return this->w<e.w;
    }
};

int main(){
    int nodes,edges,spanning_tree_weight=0;
    cin>>nodes>>edges;
    vector<edge> graph;
    for(int i=0;i<edges;i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph.push_back(edge(u,v,w));
    }
    sort(graph.begin(),graph.end());
    DisjointSet ds(nodes+1);
    int edges_in_spanning_tree=nodes-1;
    for(int i=0;edges_in_spanning_tree;i++){
        if(!(ds.isSameSet(graph[i].u,graph[i].v))){
            ds.unionSet(graph[i].u,graph[i].v);
            spanning_tree_weight+=graph[i].w;
            edges_in_spanning_tree--;
        }
    }
    cout<<spanning_tree_weight<<endl;
}
