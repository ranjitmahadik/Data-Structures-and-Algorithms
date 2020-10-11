#include<bits/stdc++.h>
using namespace std;

// Time Complexity => O(2^n)
int repeatingsubsequenceRecursive(string&a,int i,int j){
	if(i == 0 || j == 0)	return 0;
	else if(a[i-1] == a[j-1] && i != j)	return 1 + repeatingsubsequenceRecursive(a,i-1,j-1);
	else{
		return max(repeatingsubsequenceRecursive(a,i-1,j),
			repeatingsubsequenceRecursive(a,i,j-1));
	}
}

// Time Complexity => O(n^2) and Space Complexity => O(n^2)
int repeatingsubsequenceMemo(string&a,int i,int j,vector<vector<int>>&dp){
	if(i == 0 || j == 0)	return 0;
	else if(dp[i][j] !=-1)	return dp[i-1][j-1];
	else if(a[i-1] == a[j-1] && i != j)	return dp[i][j] = 1 + repeatingsubsequenceMemo(a,i-1,j-1,dp);
	else{
		return dp[i][j] =  max(repeatingsubsequenceMemo(a,i-1,j,dp),
			repeatingsubsequenceMemo(a,i,j-1,dp));
	}
}

// Time Complexity => O(n^2) and Space Complexity => O(n^2)
int repeatingsubsequenceBottomUp(string&A){
	int n = A.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            if(A[i-1] == A[j-1] && i != j){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][n];
}

int main(){
	#ifndef repeatingsubsequence
		freopen("output.txt","w",stdout);
	#endif
	string a = "abab";
	cout<<repeatingsubsequenceRecursive(a,a.size(),a.size());
	vector<vector<int>> dp(a.size()+1,vector<int>(a.size()+1,-1));
	cout<<":"<<repeatingsubsequenceMemo(a,a.size(),a.size(),dp);
	cout<<":"<<repeatingsubsequenceBottomUp(a);
	return 0;
}