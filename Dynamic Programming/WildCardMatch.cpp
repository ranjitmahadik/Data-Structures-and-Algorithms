#include<bits/stdc++.h>
using namespace std;

/*
	problem_link => "https://www.interviewbit.com/problems/regular-expression-match/";
*/

// Time Complexity => O(2^n) 
bool WildCardMatchRecursive(string&s,string&pat,int i,int j){
	int n = s.size(),m=pat.size();
	if(i >= n && j >=m )	return 1;
	if(i == n){
		if(pat[j] == '*'){
			return WildCardMatchRecursive(s,pat,i,j+1);
		}
		return 0;
	}
	else if(s[i] == pat[j] || pat[j] == '?'){
		return WildCardMatchRecursive(s,pat,i+1,j+1);
	}else if(pat[j] == '*'){
		return WildCardMatchRecursive(s,pat,i+1,j)||WildCardMatchRecursive(s,pat,i,j+1);
	}
	return 0;
}

// Time Complexity => O(n*m) and Space Complexity => O(n*m)
bool WildCardMatchMemo(string&s,string&p,int i,int j,vector<vector<int>>&dp){
	int n = s.size(),m=p.size();
	if(i >= n && j >= m)	return 1;
	else if(dp[i][j] != -1)	return dp[i][j];
	else if(i == n){
		if(p[j] == '*')	return dp[i][j] = WildCardMatchMemo(s,p,i,j+1,dp);
		return dp[i][j] = 0;
	}else if(s[i] == p[j] || p[j] == '?'){
		return dp[i][j] = WildCardMatchMemo(s,p,i+1,j+1,dp);
	}else if(p[j] == '*'){
		return dp[i][j] = (WildCardMatchMemo(s,p,i+1,j,dp)||WildCardMatchMemo(s,p,i,j+1,dp));
	}
	return dp[i][j] = 0;
}

// Time Complexity => O(n*m) and Space Complexity => O(n*m)
int WildCardMatchBottomUp(string&s,string&p){
	int n = s.size(),m = p.size();
	int dp[n+1][m+1];
	dp[0][0] = 1;
	for(int i=1;i<m+1;i++){
		if(p[i-1] == '*')
			dp[0][i] = dp[0][i-1];
	}
	for(int i=1;i<n+1;i++){
		for(int j=1;j<m+1;j++){
			if(s[i-1] == p[j-1]||p[j-1]=='?')	dp[i][j] = dp[i-1][j-1];
			else if(p[j-1] == '*')	dp[i][j] = dp[i-1][j]||dp[i][j-1];
			else dp[i][j] = 0;
		}
	}
	return dp[n][m];
}

int main(){
	#ifndef Regex
		freopen("output.txt","w",stdout);
	#endif
	string a = "ad",pat="??*";
	cout<<WildCardMatchRecursive(a,pat,0,0);
	vector<vector<int>> dp(a.size()+1,vector<int>(pat.size()+1,-1));
	cout<<":"<<WildCardMatchMemo(a,pat,0,0,dp);
	cout<<":"<<WildCardMatchBottomUp(a,pat);
	return 0;
}