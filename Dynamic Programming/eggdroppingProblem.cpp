#include<bits/stdc++.h>
using namespace std;

// Time Complexity => O(2^n)
int eggDropRecursive(int f,int e){
	if(e == 1 || f <= 1)	return f;
	int ans = INT_MAX;
	for(int k=1;k<=f;k++){
					//breaks					//doen't
		int temp = max(eggDropRecursive(k-1,e-1),eggDropRecursive(f-k,e)) + 1;
		ans = min(temp,ans);
	}
	return ans;
}

// Time Complexity => O((f^2)*e) ans Space Complexity => O(f*e)
int eggDropMemo(int f,int e,vector<vector<int>>&dp){
	if(e == 1 || f <= 1)	return f;
	else if(dp[f][e] != -1)	return dp[f][e];
	int ans = INT_MAX;
	for(int k=1;k<=f;k++){
		int temp = max(eggDropMemo(k-1,e-1,dp),eggDropMemo(f-k,e,dp))+1;
		ans = min(ans,temp);
	}
	return dp[f][e] = ans;
}

// Time Complexity => O(f*e*log(f)) ans Space Complexity => O(f*e)
int eggDropOptimal(int f,int e,vector<vector<int>>&dp){
	if(e == 1 || f <= 1)	return f;
	else if(dp[f][e] != -1)	return dp[f][e];
	int ans = INT_MAX;
	int lo = 1, hi = f;
	while(lo <= hi){
		int curr_floor = (lo+hi)/2;
		int not_broken = eggDropOptimal(f-curr_floor,e,dp);
		int broken     = eggDropOptimal(curr_floor-1,e-1,dp);
		int k = max(not_broken,broken);
		if(not_broken > broken){
			lo = curr_floor+1;
		}else{
			hi = curr_floor-1;
		}
		ans = min(ans,k+1);
	} 

	return dp[f][e] = ans;
}


int main(){
	#ifndef eggDrop
		freopen("output.txt","w",stdout);
	#endif
	int floors = 10, eggs = 2;
	vector<vector<int>> dp(floors+1,vector<int>(eggs+1,-1));
	vector<vector<int>> dpp(floors+1,vector<int>(eggs+1,-1));
	cout<<eggDropRecursive(floors,eggs)<<":"<<eggDropMemo(floors,eggs,dp)<<":"<<eggDropOptimal(floors,eggs,dpp);
	return 0;
}