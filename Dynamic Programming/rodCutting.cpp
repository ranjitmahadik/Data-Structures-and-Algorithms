#include<bits/stdc++.h>
using namespace std;

int rodCuttingRecursive(vector<int>&price,int n){
	if(n <= 0)	return 0;
	int ans = INT_MIN;
	for(int i=0;i<n;i++){
		ans = max(ans,price[i] + rodCuttingRecursive(price,n-i-1));
	}
	return ans;
}

// Time Complexity => O(n*m) and Space complexity => O(m)
int rodCuttingMemo(vector<int>&price,int n,vector<int>&dp){
	if(n <= 0)	return 0;
	else if(dp[n] != -1)	return dp[n];
	int ans = INT_MIN;
	for(int i=0;i<n;i++){
		ans = max(ans,price[i] + rodCuttingMemo(price,n-i-1,dp));
	}
	return dp[n] = ans;
}


/* approach this problem same as knapsack.
	Time Complexity => O(2^n) and Space Complexity => O(n)
*/
int rodCuttingRecursive2(vector<int>&val,vector<int>&len,int total,int n){
	if(n == 0 || total == 0)	return 0;
	else if(len[n-1] <= total){
		return max(val[n-1]+rodCuttingRecursive2(val,len,total-len[n-1],n),
							rodCuttingRecursive2(val,len,total,n-1));
	}
	return rodCuttingRecursive2(val,len,total,n-1);
}

// Time Complexity => O(n*m) and Space complexity => O(n*m)
int rodCuttingMemo2(vector<int>&val,vector<int>&len,int total,int n,vector<vector<int>>&dp){
	if(n == 0 || total == 0)	return 0;
	else if(dp[n][total] != -1)	return dp[n][total];
	else if(len[n-1] <= total){
		return dp[n][total] = max(val[n-1]+rodCuttingMemo2(val,len,total-len[n-1],n,dp),
							rodCuttingMemo2(val,len,total,n-1,dp));
	}
	return dp[n][total] = rodCuttingMemo2(val,len,total,n-1,dp);
}

// Time Complexity => O(n*m) and Space Complexity => O(m)
int rodCuttingBottomUp(vector<int>&price,int len){
	int dp[len+1] = {0};
	dp[0] = 0;
	for(int i=1;i<len+1;i++){
		for(int j=0;j<i;j++){
			dp[i] = max(dp[i],price[j]+dp[i-j-1]);
		}
	}
	return dp[len];
}

int main(){
	#ifndef rodCutting
		freopen("output.txt","w",stdout);
	#endif
	vector<int> price = {1,5,8,9,10,17,17,20};
	int n = price.size();
	cout<<rodCuttingRecursive(price,n);
	vector<int> dp(n+1,-1);
	cout<<":"<<rodCuttingMemo(price,n,dp);
	cout<<":"<<rodCuttingBottomUp(price,n);
	vector<int> len;
	for(int i=1;i<=n;i++)	len.push_back(i);
	cout<<":"<<rodCuttingRecursive2(price,len,n,n);
	vector<vector<int>> t(n+1,vector<int>(n+1,-1));
	cout<<":"<<rodCuttingMemo2(price,len,n,n,t);
	return 0;
}