#include<bits/stdc++.h>
using namespace std;

// Time Complexity => O(3^m) ,where m is length of second string
int editDistanceRecursive(string&a,string&b,int i,int j){
	if(i == 0 || j == 0)	return max(i,j);
	else if(a[i-1] == b[j-1])	return editDistanceRecursive(a,b,i-1,j-1);
	else{
		return 1 + min(editDistanceRecursive(a,b,i-1,j), // delete
				   min(editDistanceRecursive(a,b,i,j-1), //insert
				   	   editDistanceRecursive(a,b,i-1,j-1) //replaced
				   	   ));
	}
}

// Time Complexity => O(n*m) and Space Complexity => O(n*m)
int editDistanceRecursiveMemo(string&a,string&b,int i,int j,vector<vector<int>>&dp){
	if(i == 0 || j == 0)	return max(i,j);
	else if(dp[i][j] !=-1)	return dp[i][j];
	else if(a[i-1] == b[j-1])	return dp[i][j] = editDistanceRecursiveMemo(a,b,i-1,j-1,dp);
	else{
		return dp[i][j] = 1 + min(editDistanceRecursiveMemo(a,b,i-1,j,dp), // delete
				   min(editDistanceRecursiveMemo(a,b,i,j-1,dp), //insert
				   	   editDistanceRecursiveMemo(a,b,i-1,j-1,dp) //replaced
				   	   ));
	}
}

// Time Complexity => O(n*m) and Space Complexity => O(n*m)
int editDistanceBottomUp(string&a,string&b){
	int n = a.size(),m=b.size();
	int dp[n+1][m+1];
	for(int i=0;i<n+1;i++)	dp[i][0] = i;
	for(int j=0;j<m+1;j++)	dp[0][j] = j;
	for(int i=1;i<n+1;i++){
		for(int j=1;j<m+1;j++){
			if(a[i-1] == b[j-1])	dp[i][j] = dp[i-1][j-1];
			else	dp[i][j] = 1 + min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
		}
	}
	return dp[n][m];
}

int main(){
	#ifndef editDistance
		freopen("output.txt","w",stdout);
	#endif
	string a = "Anshuman", b = "Antihuman";
	cout<<"editDistance:\n";
	cout<<editDistanceRecursive(a,b,a.size(),b.size());
	vector<vector<int>> dp(a.size()+1,vector<int>(b.size()+1,-1));
	cout<<":"<<editDistanceRecursiveMemo(a,b,a.size(),b.size(),dp);
	cout<<":"<<editDistanceBottomUp(a,b);
	return 0;
}