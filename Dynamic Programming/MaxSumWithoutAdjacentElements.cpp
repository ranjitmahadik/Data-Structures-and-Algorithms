#include<bits/stdc++.h>
using namespace std;

// Time Complexity => O(2^n) and Space Complexity => O(n)
int maxSumWithOutAdjRec(vector<vector<int>>&arr,int idx,int sum){
	if(idx >= arr[0].size())	return sum;
	int a = maxSumWithOutAdjRec(arr,idx+2,sum+max(arr[0][idx],arr[1][idx]));
	int b = maxSumWithOutAdjRec(arr,idx+1,sum);
	return max(a,b);
} 

// Time Complexity => O(2^n) and Space Complexity => O(n)
int maxSumWithOutAdjRec2(vector<vector<int>>&arr,int idx){
	if(idx >= arr[0].size())	return 0;	
	return max(maxSumWithOutAdjRec2(arr,idx+2)+max(arr[0][idx],arr[1][idx]),maxSumWithOutAdjRec2(arr,idx+1));
}

// Time Complexity => O(n*sum) and Space Complexity => O(n*sum)
int maxSumWithOutAdjMemo(vector<vector<int>>&arr,int idx,int sum,vector<vector<int>>&dp){
	if(idx >= arr[0].size())	return sum;
	else if(dp[idx][sum] != -1)	return dp[idx][sum];
	int a = maxSumWithOutAdjMemo(arr,idx+2,sum+max(arr[0][idx],arr[1][idx]),dp);
	int b = maxSumWithOutAdjMemo(arr,idx+1,sum,dp);
	return dp[idx][sum] = max(a,b);
}

// Time Complexity => O(n) and Space Complexity => O(n) 
int maxSumWithOutAdjMemo2(vector<vector<int>>&arr,int idx,vector<int>&dp){
	if(idx >= arr[0].size())	return dp[idx] =  0;
	else if(dp[idx] != -1)	return dp[idx];	
	return dp[idx] = max(maxSumWithOutAdjMemo2(arr,idx+2,dp)+max(arr[0][idx],arr[1][idx]),
		                 maxSumWithOutAdjMemo2(arr,idx+1,dp));
}

// Space can be Optimized
// Time Complexity => O(n) and Space Complexity => O(1)
int maxSumWithOutAdjOptimal(vector<vector<int>>&arr){
	int n = arr[0].size();
	int incl = max(arr[0][0],arr[1][0]);
	int excl = 0, new_excl = 0;
	for(int i=1;i<n;i++){
		new_excl = max(incl,excl);
		incl = excl + max(arr[0][i],arr[1][i]);
		excl = new_excl;
	}
}


int main(){
	#ifndef MaxSumWithOutAdj
		freopen("output.txt","w",stdout);
	#endif
	vector<vector<int>> arr = {{1,2,3,4},  //-> 10
							   {5,6,7,8}}; //-> 26 
	cout<<maxSumWithOutAdjRec(arr,0,0);
	vector<vector<int>> dp(arr[0].size()+1,vector<int>(26,-1));
	cout<<":"<<maxSumWithOutAdjMemo(arr,0,0,dp);
	vector<int> dpp(arr[0].size()+1,-1);
	cout<<":"<<maxSumWithOutAdjMemo2(arr,0,dpp);
	cout<<":"<<maxSumWithOutAdjOptimal(arr);
	return 0;
}