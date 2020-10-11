#include<bits/stdc++.h>
using namespace std;

// Problem Link => "https://leetcode.com/problems/burst-balloons"

int burstBalloons(vector<int>&arr,int i,int j){
	if(i>=j)	return 0;
	int ans = INT_MIN;
	for(int k=i;k<j;k++){
		int temp = burstBalloons(arr,i,k)+burstBalloons(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
		ans = max(ans,temp);
	}
	return ans;
}

// Time Complexity => O(n^3) and Space Complexity => O(n^2)
int burstBalloonsMemo(vector<int>&arr,int i,int j,vector<vector<int>>&dp){
	if(i>=j)	return 0;
	else if(dp[i][j] != -1)	return dp[i][j];
	int ans = INT_MIN;
	for(int k=i;k<j;k++){
		int temp = burstBalloonsMemo(arr,i,k,dp)+burstBalloonsMemo(arr,k+1,j,dp);
		temp = temp + arr[i-1]*arr[k]*arr[j];
		ans = max(ans,temp);		
	}
	return dp[i][j] = ans;
}

int main(){
	#ifndef burstBalloons
		freopen("output.txt","w",stdout);
	#endif
	vector<int> arr = {3,1,5,8};
	arr.insert(arr.begin(),1); // add 1 at starting and ending
	arr.push_back(1);
	cout<<burstBalloons(arr,1,arr.size()-1);
	vector<vector<int>> dp(arr.size()+1,vector<int>(arr.size()+1,-1));
	cout<<":"<<burstBalloonsMemo(arr,1,arr.size()-1,dp);
	return 0;
}