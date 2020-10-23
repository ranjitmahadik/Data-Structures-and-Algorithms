#include<bits/stdc++.h>
using namespace std;

// Time Complexity => O(n^2) and Space Complexity => O(n)
int lengthofLongestSubsequence(vector<int>&arr){
	int n = arr.size();
	vector<int> LIS(n,1),DIS(n,1);
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(arr[i] > arr[j])	LIS[i] = max(LIS[i],LIS[j]+1);
		}
	}
	for(int i=n-2;i>=0;i--){
		for(int j=n-1;j>i;j--){
			if(arr[i] > arr[j])	DIS[i] = max(DIS[i],DIS[j]+1);
		}
	}
	int ans = -1;
	for(int i=0;i<n;i++)		ans = max(ans,LIS[i]+DIS[i]-1);
	return ans;
}


int main(){
	#ifndef longest
		freopen("output.txt","w",stdout);
	#endif
	vector<int> arr = {1, 11, 2, 10, 4, 5, 2, 1};
	cout<<lengthofLongestSubsequence(arr);
	return 0;
}
