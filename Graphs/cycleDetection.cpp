#include<bits/stdc++.h>
using namespace std;

vector<int> G[10];

void addEdge(int src,int dest){
	G[src].push_back(dest);
	G[dest].push_back(src);
}

bool dfs1(int u,int par,bool*vis){
	vis[u] = 1;
	for(int v : G[u]){
		if(!vis[v]){
			bool ans = dfs1(v,u,vis);
			if(ans)	return true;
		}else if(v != par){
			return true;
		}
	}
	return false;
}
bool cycleDetection(){
	bool vis[10] = {0};
	return dfs1(1,-1,vis);
}

int main(int argc, char const *argv[])
{
	#ifndef Graph_B
		freopen("output.txt","w",stdout);
	#endif

	addEdge(1,2);addEdge(1,4);
	addEdge(2,3);addEdge(4,7);
	addEdge(3,9);addEdge(7,6);
	addEdge(9,6);addEdge(9,5);
	cout<<cycleDetection();
	return 0;
}