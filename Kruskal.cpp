#include<bits/stdc++.h>
using namespace std;
int findSet(vector<set<int>> &Set,int num){
	
}

int main(){
	int V,E;
	cin>>V>>E;
	vector<pair<pair<int,int>,int>> EdgeDetail;
	int v1,v2,w;
	cout<<"Enter vetices and weight of edge joining them"<<endl;
	for(int i=1;i<=E;i++){		
		cin>>v1>>v2>>w;
		EdgeDetail.push_back(make_pair(make_pair(v1,v2),w));
	}
	//sorting Edgedetails based on it's weight
	sort(EdgeDetail.begin(),EdgeDetail.end(),
     [](const pair<pair<int,int>,int>& lhs, const pair<pair<int,int>,int>& rhs) {
             return lhs.second <rhs.second; } );
	vector<int> status(V+1,-1);
	int count=0;
	vector<pair<pair<int,int>,int>> KruskalMST;
	vector<pair<pair<int,int>,int>>::iterator itr=EdgeDetail.begin();
//	while(itr!=EdgeDetail.end()){
//		cout<<(*itr).first.first<<" "<<(*itr).first.second<<" "<<(*itr).second<<endl;
//		itr++;
//	}
	int t1,t2,x,y,t;
	while(count!=V-1){
		t1=(*itr).first.first;
		t2=(*itr).first.second;
		x=status[t1];
		y=status[t2];
		if(x<0&&y<0){
			KruskalMST.push_back(make_pair(make_pair(t1,t2),(*itr).second));
			count++;
			status[t1]+=status[t2];
			status[t2]=t1;
			itr++;
		}
		else if(x<0){			
			while(1){
				t=y;
				y=status[t];
				if(y<0)
					break;
			}
			if(t1==t)
				continue;
			else{
				KruskalMST.push_back(make_pair(make_pair(t1,t2),(*itr).second));
				count++;
				status[t1]+=status[t];
				status[t]=t1;
				itr++;
			}
		}
		else if(y<0){			
			while(1){
				t=x;
				x=status[t];
				if(x<0)
					break;
			}
			if(t2==t)
				continue;
			else{
				KruskalMST.push_back(make_pair(make_pair(t1,t2),(*itr).second));
				count++;
				status[t2]+=status[t];
				status[t]=t2;
				itr++;
			}
		}
		else{
			int tt;			
			while(1){
				t=y;
				y=status[t];
				if(y<0)
					break;
			}
			while(1){
				tt=x;
				x=status[tt];
				if(x<0)
					break;
			}
			if(t==tt)
				continue;
			else{
				KruskalMST.push_back(make_pair(make_pair(t1,t2),(*itr).second));
				count++;
				status[t]+=status[tt];
				status[tt]=t;
				itr++;
			}
		}						
	}
	itr=KruskalMST.begin();
	while(itr!=KruskalMST.end()){
		cout<<(*itr).first.first<<"-"<<(*itr).first.second<<" "<<(*itr).second<<endl;
		itr++;
	}		
	return 0;
}
