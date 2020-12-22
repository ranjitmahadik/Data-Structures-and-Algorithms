#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> G[10];

void addEdge(int src,int dest,int w){
	G[src].push_back({dest,w});
	G[dest].push_back({src,w});
}


int main(int argc, char const *argv[])
{
	#ifndef Graph_B
		freopen("output.txt","w",stdout);
	#endif

	return 0;
}