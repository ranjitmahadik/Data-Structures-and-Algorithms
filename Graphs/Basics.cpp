#include<bits/stdc++.h>
using namespace std;

class Graph
{
	vector<int>* G;
	int size;

	void dfs(int curr,bool* vis){
		printf("%d\n",curr);
		vis[curr] = 1;
		for(int nbr : G[curr]){
			if(!vis[nbr]){
				dfs(nbr,vis);
			}
		}
	}
public:
	Graph(int size){
		this->size = size;
		this->G = new vector<int>[size];
	}
	void addEdge(int src,int dest,bool isUndirected = true){
		G[src].push_back(dest);
		if(isUndirected){
			G[dest].push_back(src);
		}
	}
	void dfs(int curr){
		bool* vis = new bool[this->size];
		memset(vis,0,sizeof(vis));
		dfs(curr,vis);
	}
	void bfs(int curr){
		queue<int> q;
		bool vis[size] = {0};
		q.push(curr);
		vis[curr] = 1;
		while(!q.empty()){
			int par = q.front(); q.pop();
			cout<<par<<" ";
			for(int nbr : G[par]){
				if(!vis[nbr]){
					vis[nbr] = 1;
					q.push(nbr);
				}				
			}
		}
	}
	void degrees(){
		for(int i=0;i<size;i++){
			cout<<i<<" : "<<G[i].size()<<endl;
		}
	}

	void singleSourceShortestPath(int src,int dest){
		queue<pair<int,string>> q;		// int currVertex,Path
		bool vis[size] = {0};
		q.push({src,to_string(src)});
		vis[src] = 1;
		while(!q.empty()){
			int currNode = q.front().first;
			string currPath = q.front().second;
			q.pop();
			if(currNode == dest){
				cout<<currPath<<endl;
				vis[currNode] = 0;
			}
			for(int nbr : G[currNode]){
				if(!vis[nbr]){
					vis[nbr] = 1;
					q.push({nbr,currPath+"-"+to_string(nbr)});
				}
			}
		}
		return;
	}
	
	~Graph(){
		delete G;
	}
};




int main(int argc, char const *argv[])
{
	#ifndef Graph_B
		freopen("output.txt","w",stdout);
	#endif

	Graph *g = new Graph(7);
	g->addEdge(2,1);
	g->addEdge(2,3);
	g->addEdge(0,1);
	g->addEdge(0,3);
	g->addEdge(4,3);
	g->addEdge(5,4);

	g->singleSourceShortestPath(5,0);

	return 0;
}