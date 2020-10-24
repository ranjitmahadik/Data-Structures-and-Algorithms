#include<bits/stdc++.h>
using namespace std;

// Time Complexity = O(2^n)
int coinSumInfiniteRec(vector<int>&coins,int sum,int idx){
	if(sum == 0)	return 1;
	else if(idx == 0)	return 0;
	else if(coins[idx-1] <= sum){
		return coinSumInfiniteRec(coins,sum-coins[idx-1],idx)+coinSumInfiniteRec(coins,sum,idx-1);
	}
	return coinSumInfiniteRec(coins,sum,idx-1);
}

// Time Complexity and Space Complexity => O(n*w) where n = no of coins and w = sum of coins
int coinSumInfiniteMemo(vector<int>&coins,int sum,int idx,vector<vector<int>>&dp){
	if(sum == 0)	return 1;
	else if(idx == 0)	return 0;
	else if(dp[idx][sum] != -1)	return dp[idx][sum];
	else if(coins[idx-1] <= sum){
		return dp[idx][sum] = coinSumInfiniteMemo(coins,sum-coins[idx-1],idx,dp)+coinSumInfiniteMemo(coins,sum,idx-1,dp);
	}
	return dp[idx][sum] = coinSumInfiniteMemo(coins,sum,idx-1,dp);
}

int main(int argc, char const *argv[])
{
	#ifndef CoinSumInfinite
		freopen("output.txt","w",stdout);
	#endif
	vector<int> coins = {1,2,3};
	int sum = 4;
	cout<<coinSumInfiniteRec(coins,sum,coins.size());
	vector<vector<int>> dp(coins.size()+1,vector<int>(sum+1,-1));
	cout<<":"<<coinSumInfiniteMemo(coins,sum,coins.size(),dp);
	return 0;
}