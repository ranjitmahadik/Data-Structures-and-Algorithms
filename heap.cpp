#include<bits/stdc++.h>
typedef std::pair<int,int> p_i;
using namespace std;

class HeapProblems{
public:
	int kthSmallestElement(vector<int>& arr,int k){
		priority_queue<int> pq;
		for(int i=0;i<arr.size();i++){	
			pq.push(arr[i]);
			if(pq.size() > k){
				pq.pop();
			}	
		}
		return pq.top();
	}
	int kthLargestElement(vector<int>&arr,int k){
		priority_queue<int,vector<int>,greater<int>> pq;
		for(int i : arr){
			pq.push(i);
			if(pq.size() > k){
				pq.pop();
			}
		}
		return pq.top();
	}
	void show(vector<int>&arr){
		for(int i: arr)
			cout<<i<<" ";
	}
	void sortKSortedArray(vector<int>&arr,int k){
		priority_queue<int,vector<int>,greater<int>> pq(arr.begin(),arr.begin()+k+1);
		int idx= 0;
		for(int i=k+1;i<arr.size();i++){
			arr[idx++] = pq.top();
			pq.pop();
			pq.push(arr[i]);
		}
		while(!pq.empty()){
			arr[idx++] = pq.top();
			pq.pop();
		}
		show(arr);
	}
	void kClosestNumbers(vector<int>&arr,int k,int x){
		priority_queue<p_i > pq;
		for(int i=0;i<arr.size();i++){
			pq.push({abs(x-arr[i]),arr[i]});
			if(pq.size() > k){
				pq.pop();
			}
		}
		while(!pq.empty()){
			cout<<pq.top().second<<" ";
			pq.pop();
		}
	}
	void topKFrequentNumbers(vector<int>&arr,int k){
		unordered_map<int,int> look;
		for(int i=0;i<arr.size();i++){
			look[arr[i]]++;
		}
		priority_queue<p_i, vector<p_i >,greater<p_i > > pq;
		for(auto& p : look){
			pq.push({p.second,p.first});
			if(pq.size() > k){
				pq.pop();
			}
		}
		while(!pq.empty()){
			cout<<pq.top().second<<":"<<pq.top().first<<endl;
			pq.pop();
		}
	}

	void frequencySort(vector<int>& arr){
		unordered_map<int,int> mp;
		for(int i:arr){
			mp[i]++;
		}
		priority_queue<p_i> pq;
		for(auto& p : mp){
			pq.push({p.second,p.first});
		}
		int idx = 0;
		while(!pq.empty()){
			int frq = pq.top().first;
			int item = pq.top().second;
			for(int i =0;i<frq;i++){
				arr[idx++] = item;
			}
			pq.pop();
		}	
		show(arr);
	}
	void kClosestToOrigin(vector<vector<int>>&arr,int k){
		priority_queue<pair<int,pair<int,int> > > pq;
		for(int i=0;i<arr.size();i++){
			int formula = pow(arr[i][0],2)+pow(arr[i][1],2);
			pq.push({formula,{arr[i][0],arr[i][1]}});
			if(pq.size() > k){
				pq.pop();
			}
		}
		while(!pq.empty()){
			cout<<"("<<pq.top().second.first<<","<<pq.top().second.second<<")\n";
			pq.pop();
		}
	}

	int connectRopesToMinimizeCost(vector<int>&arr){
		int ans = 0;
		priority_queue<int,vector<int>,greater<int> > pq(arr.begin(),arr.end());
		while(pq.size() > 1){
			int f = pq.top(); pq.pop();
			int s = pq.top(); pq.pop();
			pq.push(f+s);			
			ans += (f+s);
		}
		return ans;
	}
};


int main(){
	#ifndef HEAP
		freopen("output.txt","w",stdout);
	#endif
	HeapProblems *hp = new HeapProblems();
	//2,3,5,6,8,9,10
	// vector<int> elements = {-10,-50,20,17,80};
	// cout<<hp->kthSmallestElement(elements,2)<<":"<<hp->kthLargestElement(elements,2);
	// hp->sortKSortedArray(elements,3);
	// hp->kClosestNumbers(elements,2,20);

	// vector<int> freq = {1,3,5,1,3,5,2,9,5,8};
	// hp->topKFrequentNumbers(freq,3);
	// hp->frequencySort(freq);

	// vector<vector<int>> points = {{1,3},{-2,2},{5,8},{0,1},{1,1}};
	// hp->kClosestToOrigin(points,3);

	// vector<int> ropes = {20,4,8,2};
	// cout<<hp->connectRopesToMinimizeCost(ropes);
	
	return 0;
}