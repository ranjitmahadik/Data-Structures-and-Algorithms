#include<bits/stdc++.h>
using namespace std;

// Problem link 	-> "https://www.interviewbit.com/problems/merge-elements/"
// Similar Problem 	-> "https://leetcode.com/problems/minimum-cost-to-merge-stones/"

int mergeElementsRecursive(vector<int>&arr,int i,int j){
	if(i >= j)	return 0;
	int sum = 0;
	for(int k=i;k<=j;k++)	sum+=arr[k];
	int ans = INT_MAX;
	for(int k=i;k<j;k++){
		int temp = mergeElementsRecursive(arr,i,k) + mergeElementsRecursive(arr,k+1,j) + sum;
		ans = min(ans,temp);
	}
	return ans;
}

// Time Complexity => O(n^3) and space complexity => O(n^2)
int mergeElementsMemo(vector<int>&arr,int i,int j,vector<vector<int>>&dp){
	if(i >= j)	return 0;
	else if(dp[i][j] !=-1)	return dp[i][j];
	int sum = 0;
	for(int k=i;k<=j;k++)	sum+=arr[k];
	int ans = INT_MAX;
	for(int k=i;k<j;k++){
		int temp = mergeElementsMemo(arr,i,k,dp) + mergeElementsMemo(arr,k+1,j,dp) + sum;
		ans = min(ans,temp);
	}
	return dp[i][j] = ans;
}

int mergeKPiles(vector<int>&stones,int K,int i,int j,vector<vector<int>>&dp){
	if(i >= j)	return 0;
	else if(dp[i][j] !=-1)	return dp[i][j];
	int sum = 0,ans = INT_MAX;
	for(int k=i;k<=j;k++)	sum+= stones[k];
	for(int k=i;k<j;k+=(K-1)){
		int temp = mergeKPiles(stones,K,i,k,dp) + mergeKPiles(stones,K,k+1,j,dp);
		ans = min(ans,temp);
	}
	if((j-i)%(K-1) == 0){
		ans = ans + sum;
	}
	return ans;
}

int main(){
	#ifndef mergeElements
		freopen("output.txt","w",stdout);
	#endif
	vector<int> arr = {1,2,3,4};
	int K = 2;
	vector<vector<int>> dp(arr.size()+1,vector<int>(arr.size()+1,-1));
	cout<<mergeElementsRecursive(arr,0,arr.size()-1);
	cout<<":"<<mergeElementsMemo(arr,0,arr.size()-1,dp);
	cout<<":"<<mergeKPiles(arr,K,0,arr.size()-1,dp);
	return 0;
}