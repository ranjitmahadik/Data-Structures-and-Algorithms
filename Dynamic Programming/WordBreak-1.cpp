#include<bits/stdc++.h>
using namespace std;

// Time Complexity => O(2^n)
bool wordBreakRec(string&s,int i,int j,unordered_set<string>&dct){
	if(i == j){
		return 1;
	}
	string pref = "";
	for(int k=i;k<j;k++){
		pref += s[k];
		if(dct.find(pref) != dct.end() && wordBreakRec(s,k+1,j,dct)){
			return 1;
		}
	}
	return 0;
}

// Time Complexity => O(n^2)
bool wordBreakDP(string&s,int i,int j,unordered_set<string>&dct,unordered_map<int,bool>&dp){
	if(i == j)	return 1;
	else if(dp.find(i) != dp.end())	return dp[i];
	string pref = "";
	for(int k=i;k<j;k++){
		pref += s[k];
		if(dct.find(pref) != dct.end() && wordBreakDP(s,k+1,j,dct,dp)){
			return dp[i] = 1;
		}
	}
	return dp[i] = 0;
}

int main(){
	#ifndef wordBreak
		freopen("output.txt","w",stdout);
	#endif
	string s = "myinterviewtrainer";
	unordered_set<string> dct;
	dct.insert("trainer"); dct.insert("my");dct.insert("interview");
	cout<<wordBreakRec(s,0,s.size(),dct);
	unordered_map<int,bool>dp;
	cout<<":"<<wordBreakDP(s,0,s.size(),dct,dp);
	return 0;
}