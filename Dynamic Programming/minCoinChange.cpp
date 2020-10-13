#include<bits/stdc++.h>
using namespace std;

/*
	Given a value V, if we want to make change for V cents, and 
	we have infinite supply of each of C = { C1, C2, .. , Cm} valued coins, 
	what is the minimum number of coins to make the change?	
*/

// Time Complexity => O(2^n) and Space complexity => O(n)
int minCoinsRecursive(int n,vector<int>& coins,int idx){
	if(n == 0)	return 0;
	else if(n < 0 || idx == 0)	return INT_MAX-1;
	else if(coins[idx-1] <= n){
		return min(1+minCoinsRecursive(n-coins[idx-1],coins,idx),
					 minCoinsRecursive(n,coins,idx-1));
	}
	return minCoinsRecursive(n,coins,idx-1);
}

// Time Complexity => O(n*m) and Space complexity => O(n*m)
int minCoinsMemo(int n,vector<int>& coins,int idx,vector<vector<int>>&dp){
	if(n == 0)	return 0;
	else if(n < 0 || idx == 0)	return INT_MAX-1;
	else if(dp[n][idx] != -1)	return dp[n][idx];
	else if(coins[idx-1] <= n){
		return dp[n][idx] = min(1+minCoinsRecursive(n-coins[idx-1],coins,idx),
					 minCoinsRecursive(n,coins,idx-1));
	}
	return dp[n][idx] = minCoinsRecursive(n,coins,idx-1);
}

/*
	Time Complexity => O(n*m) and Space complexity => O(n)
	Where n => total worth,
		  m => no of coins
*/
int minCoinsOptimal(int total,vector<int>& coins){
	int dp[total+1] = {0};
	int m = coins.size();
	for(int i=1;i<total+1;i++){
		dp[i] = INT_MAX-1;
		for(int j=1;j<m+1;j++){
			if(i - coins[j-1] >= 0){
				int subproblem = dp[i - coins[j-1]];
				dp[i] = min(dp[i],subproblem+1);
			}
		}
	}
	return dp[total];
}

int main(){
	#ifndef minCoins
		freopen("output.txt","w",stdout);
	#endif
	vector<int> coins = {1,2,5,10};
	int n = 137;
	vector<vector<int>> dp(n+1,vector<int>(coins.size()+1,-1));
	cout<<minCoinsRecursive(n,coins,coins.size());
	cout<<":"<<minCoinsMemo(n,coins,coins.size(),dp);
	cout<<":"<<minCoinsOptimal(n,coins);
	return 0;
}