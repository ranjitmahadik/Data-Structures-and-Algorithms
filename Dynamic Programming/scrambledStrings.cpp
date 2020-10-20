#include<bits/stdc++.h>
using namespace std;

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


int main(){
	#ifndef scrambledString
		freopen("output.txt","w",stdout);
	#endif
	string a = "great",b = "rgeat";
	cout<<scrambledString(a,b);
	return 0;
}