#include<bits/stdc++.h>
#define db(x) cout<<#x<<" "<<x<<endl;
using namespace std;

typedef vector<int> vi;

class stackE
{
public:
	void show(vector<int>& arr){
		for(int i : arr){
			cout<<i<<" ";
		}
	}
	vector<int> nearestGreaterToRight(vector<int>& arr){
		int n = arr.size();
		vector<int> v;
		stack<int> s;
		for(int i=n-1;i>=0;i--){
			if(s.empty()){
				v.push_back(-1);
			}else if(!s.empty() && s.top() > arr[i]){
				v.push_back(s.top());
			}else if(!s.empty() && s.top() < arr[i]){
				while(!s.empty() && s.top() < arr[i])	s.pop();
				if(s.empty())	v.push_back(-1);
				else v.push_back(s.top());
			}
			s.push(arr[i]);
		}
		reverse(v.begin(), v.end());
		return v;
	}
	vector<int> nearestGreaterToLeft(vector<int>& arr){
		int n = arr.size();
		stack<int> s;
		vector<int> v;
		for(int i=0;i<n;i++){
			if(s.empty())	v.push_back(-1);
			else if(!s.empty() && s.top() > arr[i]){
				v.push_back(s.top());
			}else if(!s.empty() && s.top() < arr[i]){
				while(!s.empty() && s.top() < arr[i])	s.pop();
				if(s.empty())	v.push_back(-1);
				else	v.push_back(s.top());
			}
			s.push(arr[i]);
		}
		// reverse(v.begin(), v.end());
		return v;
	}

	vector<int> nearestSmallerToRight(vector<int>& arr){
		vi v;
		int n = arr.size();
		stack<int> s;
		for(int i=n-1;i>=0;i--){
			if(s.empty())	v.push_back(-1);
			else if(!s.empty() && s.top() < arr[i]){
				v.push_back(s.top());
			}else if(!s.empty() && s.top() > arr[i]){
				while(!s.empty() && s.top() > arr[i])	s.pop();
				if(s.empty())	v.push_back(-1);
				else 	v.push_back(s.top());
			}
			s.push(arr[i]);
		}
		reverse(v.begin(), v.end());
		return v;
	}

	void Trick(vi& arr){
		int n = arr.size();
		vi v(n,-1);
		int minSoFar = 0;
		for(int i=1;i<n;i++){
			if(arr[i] < arr[minSoFar]){
				minSoFar = i;
				v[i] = -1;
			}else{
				v[i] = arr[minSoFar];
			}
		}
		show(v);
	}

	void nearestSmallerToLeft(vi & arr){
		vi v;
		int n = arr.size();
		stack<int> s;
		for(int i = 0;i<n;i++){
			if(s.empty())	v.push_back(-1);
			else if(!s.empty() && s.top() < arr[i]){
				v.push_back(s.top());
			}else if(!s.empty() && s.top() >= arr[i]){
				while(!s.empty() && s.top() >= arr[i])	s.pop();
				if(s.empty())	v.push_back(-1);
				else	v.push_back(s.top());
			}
			s.push(arr[i]);
		}
		show(v);
	}

	void stockSpanProblem(vi arr){
		int n = arr.size();
		vi v;
		stack<pair<int,int>> s;
		for(int i=0;i<n;i++){
			if(s.empty()){
				v.push_back(1);
			}else if(!s.empty() && s.top().first < arr[i]){
				while(!s.empty() && s.top().first < arr[i])	s.pop();
				if(s.empty())	v.push_back(i);
				else	v.push_back(i-s.top().second);	
			}else if(!s.empty() && s.top().first >= arr[i]){
				v.push_back(1);
			}
			s.push({arr[i],i});
		}		
		show(v);
	}

	void maxAreaUnderHistogram(vi& arr){
		int n = arr.size();
		vi left,right;
		stack<pair<int,int>> s,r;
		for(int i=0;i<n;i++){
			if(s.empty())	left.push_back(-1);
			else if(!s.empty() && s.top().first >= arr[i]){
				while(!s.empty() && s.top().first >= arr[i])	s.pop();
				if(s.empty())	left.push_back(-1);	
				else	left.push_back(s.top().second);
			}else if(!s.empty() && s.top().first < arr[i]){
				left.push_back(s.top().second);
			}
			s.push({arr[i],i});
		}

		for(int i=n-1;i>=0;i--){
			if(r.empty())	right.push_back(n);
			else if(!r.empty() && r.top().first < arr[i]){
				right.push_back(r.top().second);
			}else if(!r.empty() && r.top().first >= arr[i]){
				while(!r.empty() && r.top().first >= arr[i])	r.pop();
				if(r.empty())	right.push_back(n);
				else	right.push_back(r.top().second);
			}
			r.push({arr[i],i});
		}
		reverse(right.begin(), right.end());
		for(int i=0;i<n;i++){
			cout<<(right[i]-left[i]-1)*arr[i]<<" ";
		}
	}

};

int main(){
	#ifndef STK
		freopen("output.txt","w",stdout);
	#endif
	stackE* s =  new stackE();
	//				   0   1 2  3  4 5 6
	vector<int> arr = {6,2,5,4,5,1,6};
	s->maxAreaUnderHistogram(arr);

	return 0;
}