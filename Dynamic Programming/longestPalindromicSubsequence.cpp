#include<bits/stdc++.h>
using namespace std;

// Time Complexity => O(2^n)
int longestPalindromicSubsequence(string& a,int i,int j){
	if(i > j)	return 0;
	else if(i == j)	return 1;
	else if(a[i] == a[j]){
		return 2 + longestPalindromicSubsequence(a,i+1,j-1);
	}else{
		return max(longestPalindromicSubsequence(a,i+1,j),
				   longestPalindromicSubsequence(a,i,j-1));
	}
}

// Time Complexity => O(n^2)
int longestPalindromicSubsequenceMemo(string& a,int i,int j,vector<vector<int>>&dp){
	if(i > j)	return 0;
	else if(i == j)	return 1;
	else if(dp[i][j] !=-1)	return dp[i][j];
	else if(a[i] == a[j]){
		return dp[i][j] =  2 + longestPalindromicSubsequence(a,i+1,j-1);
	}else{
		return dp[i][j] =  max(longestPalindromicSubsequence(a,i+1,j),
							   longestPalindromicSubsequence(a,i,j-1));
	}	
}

// Time Complexity => O(n^2) and Space Complexity => O(n^2)
int longestPalindromicSubsequenceBottomUp(string& a){
	int n =a.size();
	int dp[n][n];
	for(int i=0;i<n;i++)	dp[i][i] = 1;
	for(int len=2;len<=n;len++){
		for(int i=0;i<n-len+1;i++){
			int j = i+len-1;
			if(len == 2 && a[i] == a[j]){
				dp[i][j] = 2;
			}else if(a[i] == a[j]){
				dp[i][j] = dp[i+1][j-1] + 2;
			}else{
				dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
			}
		}
	}
	return dp[0][n-1];
}

int main(){
	#ifndef lcs
		freopen("output.txt","w",stdout);
	#endif
	string a = "bebeeed";
	vector<vector<int>> dp(a.size()+1,vector<int>(a.size()+1,-1));
	cout<<"longest Palindromic Subsequence \n";
	cout<<longestPalindromicSubsequence(a,0,a.size()-1)<<":"<<longestPalindromicSubsequenceMemo(a,0,a.size()-1,dp)<<":"<<longestPalindromicSubsequenceBottomUp(a);
	return 0;
}