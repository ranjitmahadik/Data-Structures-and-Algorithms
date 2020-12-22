#include<bits/stdc++.h>
using namespace std;

vector<int> graph[100];
void addEdge(int src,int dest){
	graph[src].push_back(dest);
	graph[dest].push_back(src);
}

int par[100][22],depth[100],m = 22;
void dfs(int u,int parent){
	par[u][0] = parent;
	for(int i = 1; i < m; i++)
		par[u][i] = par[par[u][i-1]][i-1];
	for(int v : graph[u]){
		if(parent != v){
			depth[v] = depth[u] + 1;
			dfs(v,u);
		}
	}
}

int lca(int u,int v){
	if(u == v)	return v;
	else if(depth[u] < depth[v])	swap(u,v);
	int diff = depth[u] - depth[v];
	for(int i = m-1;i>=0;i--){
		if((diff>>i) & 1){
			u = par[u][i];
		}
	}
	if(u == v)	return v;
	for(int i=m-1;i>=0;i--){
		if(par[u][i] != par[v][i]){
			u = par[u][i];
			v = par[v][i];
		}
	}
	return par[u][0];
}



int main(int argc, char const *argv[])
{
	#ifndef Diameter
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int n;
	cin>>n;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		addEdge(x,y);		
	}
	depth[1] = depth[0] = 0;
	dfs(1,0);
	cout<<lca(17,16);
	return 0;
}