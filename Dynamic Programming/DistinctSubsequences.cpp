#include<bits/stdc++.h>
using namespace std;

// Time Complexity => O(2^n)
int distinctSubseqRecursive(string&a,string&b,int i,int j){
	if(j == 0)	return 1;
	else if(i == 0)	return 0;
	else if(a[i-1] == b[j-1]){
		return (distinctSubseqRecursive(a,b,i-1,j-1) +
				distinctSubseqRecursive(a,b,i-1,j));
	}
	return distinctSubseqRecursive(a,b,i-1,j);
}

// Time Complexity => O(n^2) and Space Complexity => O(n^2)
int distinctSubseqMemo(string&a,string&b,int i,int j,vector<vector<int>>&dp){
	if(j == 0)	return 1;
	else if(i == 0)	return 0;
	else if(dp[i][j] != -1)	return dp[i][j];
	else if(a[i-1] == b[j-1]){
		return dp[i][j] = (distinctSubseqRecursive(a,b,i-1,j-1) +
				distinctSubseqRecursive(a,b,i-1,j));
	}
	return dp[i][j] = distinctSubseqRecursive(a,b,i-1,j);
}

// Time Complexity => O(n^2) and Space Complexity => O(n^2)
int distinctSubseqBottomUp(string&a,string&b){
	int n = a.size(),m=b.size();
	int dp[n+1][m+1];
	for(int i=0;i<n+1;i++){
		for(int j=0;j<m+1;j++){
			if(j == 0)	dp[i][j] = 1;
			else if(i == 0)	dp[i][j] = 0;
			else if(a[i] == b[j]){
				dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
			}else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return dp[n][m];
}


int main(){
	#ifndef DistinctSubsequences
		freopen("output.txt","w",stdout);
	#endif
	string a = "Rabbbit",b = "Rabbit";
	cout<<distinctSubseqRecursive(a,b,a.size(),b.size());
	vector<vector<int>> dp(a.size()+1,vector<int>(b.size()+1,-1));
	cout<<":"<<distinctSubseqMemo(a,b,a.size(),b.size(),dp);
	cout<<":"<<distinctSubseqBottomUp(a,b);
	return 0;
}