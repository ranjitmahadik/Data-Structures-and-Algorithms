#include<bits/stdc++.h>
using namespace std;

// Time Complexity => O(2^n)
int maxProfitRecursive(vector<int>&arr,int idx,bool state){
	if(idx == arr.size())	return 0;
	else if(state){
		return max(maxProfitRecursive(arr,idx+1,0)+arr[idx],
				   maxProfitRecursive(arr,idx+1,1));
	}else{
		return max(maxProfitRecursive(arr,idx+1,1)-arr[idx],
			 	   maxProfitRecursive(arr,idx+1,0));
	}
}

// Time Complexity => O(2n) and Space Complexity => O(2n)
int maxProfitMemo(vector<int>&arr,int idx,bool state,int dp[][2]){
	if(idx == arr.size())	return 0;
	else if(dp[idx][state] != -1)	return dp[idx][state];
	else if(state){
		return dp[idx][state] = max(maxProfitRecursive(arr,idx+1,0)+arr[idx],
				   maxProfitRecursive(arr,idx+1,1));
	}else{
		return dp[idx][state] = max(maxProfitRecursive(arr,idx+1,1)-arr[idx],
			 	   maxProfitRecursive(arr,idx+1,0));
	}
}

// Time Complexity => O(n) and Space Complexity => O(1)
int maxProfitBottomUp(vector<int>&arr){
	int n = arr.size();
	if(n == 0)	return 0;
	int profit = 0;
	for(int i=1;i<n;i++){
		if(arr[i]-arr[i-1] > 0){
			profit += arr[i] - arr[i-1];
		}
	}
	return profit;
}

int main(){
	#ifndef stocks2
		freopen("output.txt","w",stdout);
	#endif
	vector<int> arr = {7,1,5,3,6,4};
	int dp[arr.size()+1][2];
	memset(dp,-1,sizeof(dp));
	cout<<maxProfitRecursive(arr,0,0)<<":"<<maxProfitMemo(arr,0,0,dp)<<":"<<maxProfitBottomUp(arr);
	return 0;
}