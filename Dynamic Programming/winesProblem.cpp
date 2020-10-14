#include<bits/stdc++.h>
using namespace std;

/*
Given n wines in a row, with integers denoting the cost of each wine respectively.
Each year you can sale the first or the last wine in the row. However, 
the price of wines increases over time. Let the initial profits 
from the wines be P1, P2, P3…Pn. On the Yth year, the profit from 
the ith wine will be Y*Pi. For each year, your task is to print “beg” or “end” 
denoting whether first or last wine should be sold. Also, calculate the 
maximum profit from all the wines.
*/

//Time Complexity => O(2^n) and Space complexity => O(n)
int maxProfitRecursive(vector<int>&price,int beg,int end,int year){
	if(beg == end)	return year*price[end];
	int first = price[beg] * year + maxProfitRecursive(price,beg+1,end,year+1);
	int last  = price[end] * year + maxProfitRecursive(price,beg,end-1,year+1);
	return max(first,last);	
}

// Time Complexity => O(n^3) and Space Complexity => O(n^3)
int maxProfitMemo(vector<int>&price,int beg,int end,int year,vector<vector<vector<int>>>&dp){
	if(beg == end)	return year*price[end];
	else if(dp[beg][end][year] != -1)	return dp[beg][end][year];
	int first = price[beg]*year + maxProfitMemo(price,beg+1,end,year+1,dp);
	int last = price[end]*year + maxProfitMemo(price,beg,end-1,year+1,dp);
	return dp[beg][end][year] = max(first,last);
}

// Time Complexity => O(n^2) and Space Complexity => O(n^2)
int maxProfitOptimal(vector<int>&price,int beg,int end,int n,vector<vector<int>>&dp){
	int year = n - abs(end-beg);
	if(beg == end)	return year*price[beg];
	else if(dp[beg][end] != -1)	return dp[beg][end];
	int first = price[beg]*year + maxProfitOptimal(price,beg+1,end,n,dp);
	int last = price[end]*year + maxProfitOptimal(price,beg,end-1,n,dp);
	return dp[beg][end] = max(first,last);
}

int main(){
	#ifndef wineProblem
		freopen("output.txt","w",stdout);
	#endif
	vector<int> price = {2,4,6,2,5};
	cout<<maxProfitRecursive(price,0,price.size()-1,1);
	vector<vector<vector<int>>> dp(price.size()+1,vector<vector<int>>(price.size()+1,vector<int>(price.size()+1,-1)));
	cout<<":"<<maxProfitMemo(price,0,price.size()-1,1,dp);
	vector<vector<int>> dpp(price.size()+1,vector<int>(price.size()+1,-1));
	cout<<":"<<maxProfitOptimal(price,0,price.size()-1,price.size(),dpp);
	return 0;
}