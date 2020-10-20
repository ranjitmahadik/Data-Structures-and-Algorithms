#include<bits/stdc++.h>
using namespace std;

int noOfBSTRecursive(int n){
	if(n <= 1)	return 1;
	else if(n == 2)	return 2;
	else if(n == 3)	return 5;
	int ans = 0;
	for(int i=1;i<n+1;i++){
		ans += noOfBSTRecursive(i-1) * noOfBSTRecursive(n-i);
	}
	return ans;
}

// Time Complexity => O(n^2) and Space Complexity => O(n)
int noOfBSTMemo(int n,vector<int>&dp){
	if(n <= 1)	return 1;
	else if(n == 2)	return 2;
	else if(n == 3)	return 5;
	else if(dp[n] != -1)	return dp[n];
	int ans = 0;
	for(int i=1;i<n+1;i++){
		ans += noOfBSTMemo(i-1,dp) * noOfBSTMemo(n-i,dp);
	}
	return dp[n] = ans;
}

// Time Complexity => O(n) and Space Complexity => O(n)
int noOfBSTBottomUp(int n){
	int dp[n+1] = {0};
	dp[0] = 1; dp[1] = 1; dp[2] = 2; dp[3] = 5;
	for(int i=4;i<n+1;i++){
		for(int j=1;j<=i;j++){
			dp[i] += dp[j-1] * dp[i-j];
		}
	}
	return dp[n];
}


int main(){
	#ifndef uniqueBSTs
		freopen("output.txt","w",stdout);
	#endif
	vector<int> dp(5+1,-1);
	cout<<noOfBSTRecursive(5);
	cout<<":"<<noOfBSTMemo(5,dp);
	cout<<":"<<noOfBSTBottomUp(5);
	return 0;
}