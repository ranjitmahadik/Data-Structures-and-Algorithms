#include<bits/stdc++.h>
using namespace std;

/*
	Problem Link => "https://leetcode.com/problems/regular-expression-matching/"
*/

// Time Complexity => O(2^m) a 
bool RegexMatchingRecursive(string&s,string&p,int i=0,int j=0){
	int n = s.size(),m=p.size();
	if(j == m)	return i == n;
	bool isMatch = (s[i] == p[j] || p[j] == '.');
	if(j+1 < m && p[j+1] == '*'){
		return RegexMatchingRecursive(s,p,i,j+2)||(isMatch && RegexMatchingRecursive(s,p,i+1,j));
	}else{
		return isMatch && RegexMatchingRecursive(s,p,i+1,j+1);
	}
	return 0;
}

bool RegexMatchingBottomUp(string&s,string&p){
	int n = s.size(),m=p.size();
	int dp[n+1][m+1];
	memset(dp,0,sizeof(dp));	
	dp[0][0] =1 ;
	for(int i=1;i<m+1;i++){
		if(p[i-1] == '*')	dp[0][i] = dp[0][i-2];
	}
	for(int i=1;i<n+1;i++){
		for(int j=1;j<m+1;j++){
			if(s[i-1] == p[j-1] || p[j-1] == '.'){
				dp[i][j] = dp[i-1][j-1]; 
			}else if(p[j-1] == '*'){
				dp[i][j] = dp[i][j-2];
				if(p[j-2] == '.' || p[j-2] == s[i-1])
					dp[i][j] |= dp[i-1][j];
			}else{
				dp[i][j] = 0;
			}
		}
	}
	return dp[n][m];
}

int main(){
	#ifndef RegexMatching
		freopen("output.txt","w",stdout);
	#endif
	string a = "aab", b = "a*b";
	cout<<RegexMatchingRecursive(a,b);
	cout<<":"<<RegexMatchingBottomUp(a,b);
	return 0;
}