#include<bits/stdc++.h>
using namespace std;

/*
Given n wines in a row, with integers denoting the cost of each wine respectively.
Each year you can sale the first or the last wine in the row. However, 
the price of wines increases over time. Let the initial profits 
from the wines be P1, P2, P3…Pn. On the Yth year, the profit from 
the ith wine will be Y*Pi. For each year, your task is to print “beg” or “end” 
denoting whether first or last wine should be sold. Also, calculate the 
maximum profit from all the wines.
*/

//Time Complexity => O(2^n) and Space complexity => O(n)
int maxProfitRecursive(vector<int>&price,int beg,int end,int year){
	if(beg == end)	return year*price[end];
	int first = price[beg] * year + maxProfitRecursive(price,beg+1,end,year+1);
	int last  = price[end] * year + maxProfitRecursive(price,beg,end-1,year+1);
	return max(first,last);	
}




int main(){
	#ifndef wineProblem
		freopen("output.txt","w",stdout);
	#endif
	vector<int> price = {2,4,6,2,5};
	cout<<maxProfitRecursive(price,0,price.size()-1,1);
	return 0;
}