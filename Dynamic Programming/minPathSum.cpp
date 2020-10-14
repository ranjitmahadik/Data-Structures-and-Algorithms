#include<bits/stdc++.h>
using namespace std;

// Time Complexity => O(2^n) and Space Complexity => O(n) 
int minPathSum(vector<vector<int>>& mat,int i,int j){
	if(i < 0 || j < 0)	return INT_MAX;
	else if(i == 0 && j == 0)	return mat[i][j];
	return mat[i][j] + min(minPathSum(mat,i-1,j),minPathSum(mat,i,j-1));
}

// Time Complexity => O(n*m) and Space Complexity => O(n*m)
int minPathSumMemo(vector<vector<int>>& mat,int i,int j,vector<vector<int>>&dp){
	if(i<0 || j<0)	return INT_MAX;
	else if(i == 0 && j == 0)	return mat[i][j];
	else if(dp[i][j] !=-1)	return dp[i][j];
	return dp[i][j] = mat[i][j] + min(minPathSum(mat,i-1,j),minPathSum(mat,i,j-1));
}

// Time Complexity => O(n*m) and Space Complexity => O(n*m)
int minPathSumIterative(vector<vector<int>>& path){
	int n = path.size(),m=path[0].size();
	int dp[n][m];
	dp[0][0] = path[0][0];								
	for(int i=1;i<m;i++)	dp[0][i] = dp[0][i-1] + path[0][i];
	for(int j=1;j<n;j++)	dp[j][0] = dp[j-1][0] + path[j][0];
	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			dp[i][j] = path[i][j] + min(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[n-1][m-1]; 
}

int main(){
	#ifndef minPathSum
		freopen("output.txt","w",stdout);
	#endif
	vector<vector<int>> mat = {{1,3,1},
							   {1,5,1},
							   {4,2,1}};
	cout<<minPathSum(mat,2,2);
	vector<vector<int>> dp(mat.size()+1,vector<int>(mat[0].size()+1,-1));
	cout<<":"<<minPathSumMemo(mat,2,2,dp);
	cout<<":"<<minPathSumIterative(mat);
	return 0;
}