#include<bits/stdc++.h>
using namespace std;

//Time Complexity => O(2^n)
vector<string> wordBreak2(string& s,unordered_set<string>& dct,int i,int j){
	vector<string> res; 
	if(i >= j){
		res.push_back("");
		return res;
	}
	string pref = "";
	for(int k=i;k<j;k++){
		pref += s[k];
		if(dct.find(pref) != dct.end()){
			vector<string> temp = wordBreak2(s,dct,k+1,j);
			for(string curr: temp){
				res.push_back(pref+(curr==""?"":" ")+curr);
			}
		}
	}
	return res;
}

// Time Complexity => O(n*2)
vector<string> wordBreakMemo2(string& s,unordered_set<string>& dct,int i,int j,unordered_map<int,vector<string>>&dp){
	vector<string> res; 
	if(i >= j){
		res.push_back("");
		return res;
	}else if(dp.find(i) != dp.end())	return dp[i];
	string pref = "";
	for(int k=i;k<j;k++){
		pref += s[k];
		if(dct.find(pref) != dct.end()){
			vector<string> temp = wordBreakMemo2(s,dct,k+1,j,dp);
			for(string curr: temp){
				res.push_back(pref+(curr==""?"":" ")+curr);
			}
		}
	}
	return dp[i] = res;
}


int main(){
	#ifndef WordBreak2
		freopen("output.txt","w",stdout);
	#endif
			//	0123456789
	string s = "catsanddog";
	unordered_set<string> dct;	dct.insert("cat"); dct.insert("cats"); dct.insert("and"); dct.insert("sand"); dct.insert("dog");
	unordered_map<int,vector<string>> dp;
	vector<string> res = wordBreakMemo2(s,dct,0,s.size(),dp);
	for(int i=0;i<dp.size();i++){
		cout<<i<<":-> ";
		for(string k : dp[i]){
			cout<<k;
		}
		cout<<endl;
	}
	return 0;
}