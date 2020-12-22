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

	void dfs(int u,int target,string src,bool* vis){
		if(u == target){
			cout<<src<<endl;
			return;
		}
		for(int v: G[u]){
			if(!vis[v]){
				vis[v] = 1;
				dfs(v,target,src+"->"+to_string(v),vis);
				vis[v] = 0;
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
	void dfsC(){
		bool vis[size] = {0};
		vis[0] = 1;
		dfs(0,4,"0",vis);
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
	g->addEdge(0,1);
	g->addEdge(0,2);
	g->addEdge(1,3);
	g->addEdge(2,3);
	g->addEdge(3,4);
	g->addEdge(3,5);
	g->addEdge(4,6);
	g->addEdge(5,6);
	// g->bfs(0);
	g->dfsC();
	return 0;
}