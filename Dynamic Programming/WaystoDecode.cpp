#include<bits/stdc++.h>
using namespace std;

const int mod = pow(10,9) + 7;

// Time Complexity => O(2^n)
int waystoDecodeRec(string& s,int idx){
	if(idx == s.size() || idx == s.size()-1)	return 1;
	int count = 0;
	count = waystoDecodeRec(s,idx+1);
	if(idx+1 < s.size()){
		int no = s[idx+1] - '0';
		if((s[idx] == '2' && no <= 6)|| s[idx] == '1')
			count += waystoDecodeRec(s,idx+2);
	}
	return count%mod;
}

// Time Complexity => O(n) and Space Complexity => O(n)
int waystoDecodeMemo(string&s,int idx,vector<int>&dp){
	if(idx == s.size())	return 1;
	else if(dp[idx]!=-1)	return dp[idx];
	int cnt = 0;
	if(s[idx] != '0')
	cnt = waystoDecodeMemo(s,idx+1,dp);
	if(idx+1 < s.size()){
		int no = s[idx+1]-'0';
		if((s[idx]!='0' && s[idx] == '2' && no <= 6) || s[idx] == '1'){
			cnt += waystoDecodeMemo(s,idx+2,dp);
		}
	}
	return dp[idx] = (cnt)%mod;
}

int main(){
	#ifndef WaystoDecode
		freopen("output.txt","w",stdout);
	#endif
	string no = "25";
	vector<int> dp(no.size()+1,-1);
	cout<<waystoDecodeRec(no,0)<<":"<<waystoDecodeMemo(no,0,dp);
	return 0;
}