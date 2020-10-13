#include<bits/stdc++.h>
using namespace std;

/*
	min cuts required to make given string palindrome.
	link => "https://leetcode.com/problems/palindrome-partitioning-ii"
*/

bool isPalin(string&s, int i,int j){
	if(i == j)	return 1;
	while(i < j){
		if(s[i] != s[j])	return 0;
		i++; j--;
	}
	return 1;
}
int minCutsPalin(string&s,int i,int j){
	if(i>=j)	return 0;
	else if(isPalin(s,i,j))	return 0;
	int ans = INT_MAX;
	for(int k=i;k<j;k++){
		int temp = 1 + minCutsPalin(s,i,k) + minCutsPalin(s,k+1,j);
		ans = min(ans,temp);
	}
	return ans;
}

// Time Complexity => O(n^3) and Space Complexity => O(n^2)
int minCutsPalinMemo(string&s,int i,int j,vector<vector<int>>&dp){
	if(i>=j)	return 0;
	else if(dp[i][j] != -1)	return dp[i][j];
	else if(isPalin(s,i,j))	return 0;
	int ans = INT_MAX;
	for(int k=i;k<j;k++){
		int temp = 1 + minCutsPalinMemo(s,i,k,dp) + minCutsPalinMemo(s,k+1,j,dp);
		ans = min(ans,temp);
	}
	return dp[i][j] = ans;
}

/*
	States Reduced from n^2 to just n but in the worst case inner palindrome function
	loop runs n time so - 
	There are n states each state take almost O(n^2) time so overall time complexiy would
	be O(n^3).
	We can reduce to it O(n^2) but for that we have precalculate and all the prefixes 
	from each index i(i= 0 to n). 
	
*/
// Time Complexity => O(n^3) and Space Complexity => O(n^2)
int minCutsPalinOptimal(string&s,int i,int j,vector<int>&dp){
	if(i>=j)	return 0;
	else if(dp[i] != -1)	return dp[i];
	else if(isPalin(s,i,j))	return 0;
	int ans = INT_MAX;
	for(int k=i;k<j;k++){
		if(isPalin(s,i,k)){
			int temp = 1 +  minCutsPalinOptimal(s,k+1,j,dp);
			ans = min(ans,temp);
		}
	}
	return dp[i] = ans;
}

int main(){
	#ifndef minCuts
		freopen("output.txt","w",stdout);
	#endif
	string a = "madamk";  //1 
	cout<<minCutsPalin(a,0,a.size()-1);
	vector<vector<int>> dp(a.size()+1,vector<int>(a.size()+1,-1));
	cout<<":"<<minCutsPalinMemo(a,0,a.size()-1,dp);
	vector<int> dpp(a.size()+1,-1);
	cout<<":"<<minCutsPalinOptimal(a,0,a.size()-1,dpp);
	return 0;
}