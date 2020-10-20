#include<bits/stdc++.h>
using namespace std;

// Time Complexity => O(2^n)  
bool interleavingStringRecursive(string&a,string&b,string&c,int i,int j,int k){
	if(i == 0 && j == 0 && k == 0)	return 1;
	int ans = 0;
	if(i != 0 && a[i-1] == c[k-1]){
		ans |= interleavingStringRecursive(a,b,c,i-1,j,k-1);
	}
	if(j != 0 && b[j-1] == c[k-1]){
		ans |= interleavingStringRecursive(a,b,c,i,j-1,k-1);
	}
	return ans;
}

// Time Complexity => O(n*m) and Space Complexity => O(n*m)
bool interleavingStringMemo(string&a,string&b,string&c,int i,int j,int k,vector<vector<int>>&dp){
	if(i == 0 && j == 0 && k == 0)	return 1;
	else if(dp[i][j] != -1)	return dp[i][j];
	int ans = 0;
	if(i != 0 && a[i-1] == c[k-1]){
		ans |= interleavingStringRecursive(a,b,c,i-1,j,k-1);
	}
	if(j != 0 && b[j-1] == c[k-1]){
		ans |= interleavingStringRecursive(a,b,c,i,j-1,k-1);
	}
	return dp[i][j] = ans;	
}


int interleavingStringBottomUp(string&a,string&b,string&c){
	//Pending
}

int main(){
	#ifndef interleavingString
		freopen("output.txt","w",stdout);
	#endif
	string a = "aabcc",b="dbbca",c="aadbbcbcac";
	cout<<interleavingStringRecursive(a,b,c,a.size(),b.size(),c.size());
	vector<vector<int>> dp(a.size()+1,vector<int>(b.size()+1,-1));
	cout<<":"<<interleavingStringMemo(a,b,c,a.size(),b.size(),c.size(),dp);
	return 0;
}