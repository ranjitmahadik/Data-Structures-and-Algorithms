#include<bits/stdc++.h>
using namespace std;

// Time Complexity => O(4^n)
bool scrambledString(string a,string b){
	int n=a.size(),m=b.size();
	if(n != m)	return 0;
	else if(a.compare(b) == 0)	return 1;
	for(int k=1;k<n;k++){
		if((scrambledString(a.substr(0,k),b.substr(m-k,k)) && scrambledString(a.substr(k,n-k),b.substr(0,m-k)))
		   ||(scrambledString(a.substr(0,k),b.substr(0,k)) && scrambledString(a.substr(k,n-k),b.substr(k,m-k)))){
			return 1;
		}
	}
	return 0;
}

bool scrambledStringMemo(string a,string b,unordered_map<string,bool>&dp){
	int n = a.size(), m = b.size();
	string key = a+":"+b;
	if(n!=m)	return 0;
	else if(dp.find(key)!=dp.end())	return dp[key];
	else if(a.compare(b)==0)	return dp[key] = 1;
	for(int k=1;k<n;k++){
		if((scrambledStringMemo(a.substr(0,k),b.substr(m-k,k),dp) && scrambledStringMemo(a.substr(k,n-k),b.substr(0,m-k),dp))||
		   (scrambledStringMemo(a.substr(0,k),b.substr(0,k),dp)&& scrambledStringMemo(a.substr(k,n-k),b.substr(k,m-k),dp))){
			return dp[key] = 1;
		}
	}
	return dp[key] = 0;
}


int main(){
	#ifndef scrambledString
		freopen("output.txt","w",stdout);
	#endif
	string a = "great",b = "rgeat";
	unordered_map<string,bool> dp;
	cout<<scrambledString(a,b)<<":"<<scrambledStringMemo(a,b,dp);
	return 0;
}