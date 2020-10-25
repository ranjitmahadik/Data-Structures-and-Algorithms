#include<bits/stdc++.h>
using namespace std;


// Time Complexity = O(4^n)
int coinsInaLine(vector<int>&arr,int i,int j){
	if(i > j)	return 0;
	int opt1 = arr[i] + min(coinsInaLine(arr,i+2,j),coinsInaLine(arr,i+1,j-1));
	int opt2 = arr[j] + min(coinsInaLine(arr,i+1,j-1),coinsInaLine(arr,i,j-2));
	return max(opt1,opt2);
}

// Time Complexity and Space Complexity => O(n^2) 
int coinsInaLineMemo(vector<int>&arr,int i,int j,vector<vector<int>>&dp){
	if(i > j)	return 0;
	else if(dp[i][j] != -1)	return dp[i][j];
	int opt1 = arr[i] + min(coinsInaLineMemo(arr,i+2,j,dp),coinsInaLineMemo(arr,i+1,j-1,dp));
	int opt2 = arr[j] + min(coinsInaLineMemo(arr,i+1,j-1,dp),coinsInaLineMemo(arr,i,j-2,dp));
	return dp[i][j] = max(opt1,opt2);
}


int main(){
	#ifndef CoinsinaLine
		freopen("output.txt","w",stdout);
	#endif
	vector<int> arr = {5,4,8,10};
	int n = arr.size();
	vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
	cout<<coinsInaLine(arr,0,n-1)<<":"<<coinsInaLineMemo(arr,0,n-1,dp);
	return 0;
}