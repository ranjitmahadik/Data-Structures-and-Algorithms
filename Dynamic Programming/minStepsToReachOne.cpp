#include<bits/stdc++.h>
using namespace std;
/*
	Given a number n, count minimum steps to minimize it to 1 according to the 
	following criteria:
		* If n is divisible by 2 then we may reduce n to n/2.
		* If n is divisible by 3 then you may reduce n to n/3.
		* Decrement n by 1.
*/

// Time Complexity => O(3^n)  
int minStepsToReachOneRecursive(int n){
	if(n == 1)	return 0;
	int n2,n3,n1;
	n1=n2=n3=INT_MAX;
	if(n%2 == 0){
		n2 =  1 + minStepsToReachOneRecursive(n/2);
	}
	if(n%3 == 0){
		n3 =  1 + minStepsToReachOneRecursive(n/3);
	}
	n1 = 1 + minStepsToReachOneRecursive(n-1);
	return min(n1,min(n2,n3));
}

//	Time Complexity => O(n) and Space Complexity => O(n)
int minStepsToReachOneMemo(int n,vector<int>&dp){
	if(n == 1)	return 0;
	else if(dp[n] != -1)	return dp[n];
	int n2,n3,n1;
	n1=n2=n3=INT_MAX;
	if(n%2 == 0){
		n2 =  1 + minStepsToReachOneMemo(n/2,dp);
	}
	if(n%3 == 0){
		n3 =  1 + minStepsToReachOneMemo(n/3,dp);
	}
	n1 = 1 + minStepsToReachOneMemo(n-1,dp);
	return dp[n] =  min(n1,min(n2,n3));

}

// Time Complexity => O(n) and Space Complexity => O(n)
int minStepsToReachOneBotttomUp(int n){
	int dp[n+1] = {0};
	dp[1] = 0;
	for(int i=2;i<n+1;i++){
		int a1,a2,a3;	a1=a2=a3 = INT_MAX;
		if(i%2 == 0)	a2 = 1 + dp[i/2];
		if(i%3 == 0)	a3 = 1 + dp[i/3];
		a1 = 1 + dp[i-1];
		dp[i] = min(a1,min(a2,a3));
	}
	return dp[n];
}

int main(){
	#ifndef minSteps
		freopen("output.txt","w",stdout);
	#endif
	cout<<minStepsToReachOneRecursive(17);
	vector<int> dp(18,-1);
	cout<<":"<<minStepsToReachOneMemo(17,dp);
	cout<<":"<<minStepsToReachOneBotttomUp(17);
	return 0;
}