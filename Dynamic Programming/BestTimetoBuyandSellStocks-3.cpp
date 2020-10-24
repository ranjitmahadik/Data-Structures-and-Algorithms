#include<bits/stdc++.h>
using namespace std;

// Time Complexity => O(2^n)
int maxProfitWith2Transactions(vector<int>& stocks,int idx,bool state,int k){
	if(k == 0 || idx == stocks.size())	return 0;
	else if(state){
		return max(maxProfitWith2Transactions(stocks,idx+1,0,k-1)+stocks[idx],
				   maxProfitWith2Transactions(stocks,idx+1,1,k));
	}else{
		return max(maxProfitWith2Transactions(stocks,idx+1,1,k)-stocks[idx],//purchased stock
				   maxProfitWith2Transactions(stocks,idx+1,0,k));	//didnt
	}
}

// Time Complexity => O(n*k*s) where k = 2 and s = 2 (0/1) & Space Complexity => O(n*k*s) 
int maxProfitWith2TransMemo(vector<int>& stocks,int idx,bool state,int k,vector<vector<vector<int>>>&dp){
	if(k == 0 || idx == stocks.size())	return 0;
	else if(dp[idx][k][state] != -1)	return dp[idx][k][state];
	else if(state){
		return dp[idx][k][state] = max(maxProfitWith2Transactions(stocks,idx+1,0,k-1)+stocks[idx],
				   maxProfitWith2Transactions(stocks,idx+1,1,k));
	}else{
		return dp[idx][k][state] =max(maxProfitWith2Transactions(stocks,idx+1,1,k)-stocks[idx],//purchased stock
				   maxProfitWith2Transactions(stocks,idx+1,0,k));	//didnt
	}

}

// Time Complexity => O(n*k) and Space Complexity => O(n*k)
int maxProfitWith2TransBottomUp(vector<int>&stocks){
	int n = stocks.size();
	int K = 2;
	int dp[K+1][n+1];
	memset(dp,0,sizeof(dp));
	for(int k=1;k<K+1;k++){
		int diff = INT_MIN;
		for(int i=1;i<n;i++){
			diff = max(diff,dp[k-1][i-1]-stocks[i-1]);
			dp[k][i] = max(dp[k][i-1],diff+stocks[i]);
		}
	}
	return dp[K][n-1];
}

int main(){
	#ifndef BestTimeToBuyStock
		freopen("output.txt","w",stdout);
	#endif
	vector<int> stocks = {7, 2, 4, 8, 7};
	cout<<maxProfitWith2Transactions(stocks,0,0,2);
	vector<vector<vector<int>>> dp(stocks.size()+1,vector<vector<int>>(2+1,vector<int>(2+1,-1)));
	cout<<":"<<maxProfitWith2TransMemo(stocks,0,0,2,dp);
	cout<<":"<<maxProfitWith2TransBottomUp(stocks);
	return 0;
}