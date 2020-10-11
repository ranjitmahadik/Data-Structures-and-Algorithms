#include<bits/stdc++.h>
using namespace std;

//Time Complexity O(2^n)
int LCSRecursive(string a,string b,int i,int j){
	if(i == 0 || j == 0){
		return 0;
	}
	else if(a[i-1] == b[j-1]){
		return 1 + LCSRecursive(a,b,i-1,j-1);
	}else{
		return max(LCSRecursive(a,b,i-1,j),LCSRecursive(a,b,i,j-1));
	}
}

// Time Complexity => O(n*m)
int LCSMemo(string a,string b,int i,int j,vector<vector<int>>&dp){
	if(i == 0 || j == 0){
		return 0;
	}
	else if(dp[i][j] !=-1){
		return dp[i][j];
	}
	else if(a[i-1] == b[j-1]){
		return dp[i][j] = 1 + LCSRecursive(a,b,i-1,j-1);
	}else{
		return dp[i][j] =  max(LCSRecursive(a,b,i-1,j),LCSRecursive(a,b,i,j-1));
	}
}

// Time Complexity => O(n*m) and Space Complexity => O(n*m)
int LCSBottomUp(string a,string b){
	int n = a.size(), m = b.size();
	int dp[n+1][m+1];
	for(int i=0;i<n+1;i++)	dp[i][0] = 0;
	for(int j=0;j<m+1;j++)	dp[0][j] = 0;
	for(int i=1;i<n+1;i++){
		for(int j=1;j<m+1;j++){
			if(a[i-1] == b[j-1])	dp[i][j] = 1 + dp[i-1][j-1];
			else	dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[n][m];	
}


int main(){
	#ifndef lcs
		freopen("output.txt","w",stdout);
	#endif
	string a = "abcdef", b = "abdg";
	vector<vector<int>> dp(a.size()+1,vector<int>(b.size()+1,-1));
	cout<<"Longest Common Subsequence : \n";
	cout<<LCSRecursive(a,b,a.size(),b.size())<<":"<<LCSMemo(a,b,a.size(),b.size(),dp)<<":"<<LCSBottomUp(a,b);
	return 0;
}