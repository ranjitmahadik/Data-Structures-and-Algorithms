#include<bits/stdc++.h>
using namespace std;

vector<int> G[10];

void addEdge(int src,int dest){
	G[src].push_back(dest);
	G[dest].push_back(src);
}

bool dfs(int u,int color,int par,int* vis){
	vis[u] = color;
	for(int v : G[u]){
		if(vis[v] == 0){
			return dfs(v,3-color,u,vis);
		}else if(v != par && color == vis[v]){
			return false;
		}
	}
	return true;
}

bool isBipartite(){
	int vis[10] = {0};
	return dfs(1,1,-1,vis);
}


int main(int argc, char const *argv[])
{
	#ifndef Graph_B
		freopen("output.txt","w",stdout);
	#endif
	addEdge(1,2);addEdge(1,3);	//1 -> 2,3,4
	addEdge(2,4);addEdge(3,4);	//2 -> 1,4	
	addEdge(1,4);				//3 -> 1,4
								//4 -> 2,3,1
	cout<<isBipartite();
	return 0;
}