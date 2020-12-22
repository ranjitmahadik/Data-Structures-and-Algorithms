#include<bits/stdc++.h>
#define db(x) cout<<#x<<" "<<x<<endl;
using namespace std;

typedef vector<int> vi;

class SlidingWindowFixed
{
public:
	int maxSizeSubarray(vi& arr,int k){
		int ans = 0, n = arr.size();
		for(int i=0;i<k;i++){
			ans += arr[i];
		}
		int maxSoFar = ans;
		for(int i=k;i<n;i++){
			ans = ans + arr[i] - arr[i-k];
			maxSoFar = max(maxSoFar,ans);
		}
		return maxSoFar;
	}	

	void firstNegativeInSubArray(vi& arr,int k){
		int n =arr.size();
		int i,j; i = j =0;
		list<int> l;
		while(j < n){
			if(arr[j] < 0)	l.push_back(arr[j]);
			if(j-i+1 != k)	j++;
			else if(j-i+1 == k){
				if(l.size() > 0){
					int p = l.front();
					if(arr[i] == p)	l.pop_front();
					cout<<p<<" ";
				}else{
					cout<<0<<" ";
				}
				i++;j++;
			}
		}
	}

	int countOccurrencesOfAnagram(string s,string pat){
		int n = s.size(), k = pat.size();
		int i,j; i=0;j=0;
		unordered_map<char,int> looks;
		int uLetters = 0,cnt =0 ;
		for(int p=0;p<k;p++)	looks[pat[p]]++;
		uLetters = looks.size();
		while(j < n){
			if(looks.find(s[j])!=looks.end()){
				looks[s[j]]--;
				if(looks[s[j]] == 0)	uLetters--;
			}
			if(j-i+1 != k)	j++;
			else if(j-i+1 == k){
				if(uLetters == 0){
					cnt++;
				}
				if(looks.find(s[i])!=looks.end()){
					looks[s[i]]++;
					if(looks[s[i]] == 1)
						uLetters++;
				}
				i++;j++;
			}
		}
		return cnt;
	}

	void maxOfAllSubArrays(vi& arr,int k){
		int n =arr.size();
		int i,j; i=j=0;
		int maxSoFar = INT_MIN,secondMax;
		list<int> l;
		while(j<n){
			if(l.size() == 0){
				l.push_back(arr[j]);
			}else if(l.size() > 0){
				while(l.size() > 0 && l.back() < arr[j])	l.pop_front();
				l.push_back(arr[j]);
			}
			if(j-i+1 != k)	j++;
			else if(j-i+1 == k){
				db(l.front());
				if(l.front() == arr[i]){
					l.pop_front();
				}
				i++;j++;
			}
		}
	}

};

int main(){
	#ifndef STK
		freopen("output.txt","w",stdout);
	#endif

	SlidingWindowFixed* sl = new SlidingWindowFixed();
	vi arr = {1, 2, 3, 1, 4, 5, 2, 3, 6};
	// sl->firstNegativeInSubArray(arr,3);
	// db(sl->countOccurrencesOfAnagram("fororfrdofr","for"));
	// int a = 'c';cout<<a;
	sl->maxOfAllSubArrays(arr,3);
	return 0;
}