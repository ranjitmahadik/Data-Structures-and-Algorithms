#include<bits/stdc++.h>
using namespace std;

class AllSorts{
public:
	void show(vector<int>&arr){
		for(int i=0;i<arr.size();i++)	cout<<arr[i]<<" ";
		cout<<endl;
	}
	void bubbleSort(vector<int>& arr){
		for(int i=0;i<arr.size()-1;i++){
			bool isSwapper = 0;
			for(int j=i+1;j<arr.size();j++){
				if(arr[i] > arr[j]){
					swap(arr[i],arr[j]);
					isSwapper = 1;
				} 
			}
			if(!isSwapper){
				cout<<"Found it already sorted that's why we quit at idx : "<<i<<endl;
				break;
			}
		}		
		show(arr);
	}
	void insertionSort(vector<int>& arr){
		int swaps = 0;
		for(int i=1;i<arr.size();i++){
			int j = i-1,key = arr[i];
			while(j >= 0 && arr[j] > key){
				arr[j+1] = arr[j];
				j--;
				swaps++;
			}
			arr[j+1] = key;
			swaps++;
		}
		cout<<"Numbers of Swaps Done : "<<swaps<<endl;
	}
	void selectionSort(vector<int>& arr){
		int n = arr.size(),swaps =0 ;
		for(int i=0;i<n-1;i++){
			int curr_min = arr[i],idx = i;
			for(int j=i+1;j<n;j++){
				if(curr_min > arr[j]){
					curr_min = arr[j];
					idx = j;
				}
			}
			if(i != idx){
				swaps++;
				swap(arr[i],arr[idx]);
			}
		}
		cout<<"Numbers of Swaps Done : "<<swaps<<endl;
	}
	void merge(vector<int>& arr,int beg,int mid,int end){
		int n1 = mid-beg+1;
		int n2 = end-mid;
		vector<int> L(n1,0),R(n2,0);
		for(int i=0;i<n1;i++){
			L[i] = arr[beg+i];
		}
		for(int j=0;j<n2;j++){
			R[j] = arr[mid+j+1];
		}
		int i=0,j=0,k=beg;
		while(i < n1 && j < n2){
			if(L[i] <= R[j]){
				arr[k++] = L[i++];
			}else{
				arr[k++] = R[j++];
			}
		}
		while(i < n1)	arr[k++] = L[i++];
		while(j < n2) 	arr[k++] = R[j++];
	}
	void mergeSort(vector<int>&arr,int beg,int end){
		if(beg < end){
			int mid = beg+(end-beg)/2;
			mergeSort(arr,beg,mid);
			mergeSort(arr,mid+1,end);
			merge(arr,beg,mid,end);
		}
	}
	int partition(vector<int>&arr,int beg,int end){
		int pivot = arr[beg],pIndx = beg;
		int i = beg,j=beg+1;
		while(j != end){
			if(pivot > arr[j]){
				swap(arr[++i],arr[j]);
			}
			j++;
		}
		swap(arr[i],arr[pIndx]);
		show(arr);
		return i;
	}
	void quickSort(vector<int>&arr,int beg,int end){
		if(beg < end){
			int pivot = partition(arr,beg,end);
			quickSort(arr,beg,pivot);
			quickSort(arr,pivot+1,end);
		}
	}
};



class Practice : public AllSorts{
public:
	void mergeStage(vector<int>&arr,int b,int m,int e){
		int n1 = m - b + 1;
		int n2 = e - m;
		vector<int> L(n1),R(n2);
		for(int i=0;i<n1;i++)	L[i] = arr[i+b];
		for(int j=0;j<n2;j++)	R[j] = arr[j+m+1];
		int i=0,j=0,k = b;
		while(i < n1 && j < n2){
			if(L[i] <= R[j]){
				arr[k] = L[i++];
			}else{
				arr[k] = R[j++];
			}
			k++;
		}
		while(i < n1)	arr[k++] = L[i++];
		while(j < n2)	arr[k++] = R[j++];
		// show(arr);		
	}
	void divideStage(vector<int>&arr,int b,int e){
		if(b < e){
			int m = b + (e-b)/2;
			divideStage(arr,b,m);
			divideStage(arr,m+1,e);
			mergeStage(arr,b,m,e);
		}
	}

	void countingSort(vector<int>& arr,int range,int mod=10){
		int n = arr.size();
		vector<int> B(n),C(range+1,0);
		for(int i=0;i<n;i++)	C[arr[i]]++;
		for(int i=1;i<range+1;i++)	C[i] += C[i-1];
		for(int j=n-1;j>=0;j--){
			B[C[arr[j]]-1] = arr[j];
			C[arr[j]]--;
		}
		show(B);
	}
	vector<int> McountingSort(vector<int>& arr,vector<int>& marr,int range=10,int mod=10){
		int n = arr.size();
		vector<int> B(n),C(range+1,0);
		for(int i=0;i<n;i++)	C[marr[i]%mod]++;
		for(int i=1;i<range+1;i++)	C[i] += C[i-1];
		for(int j=n-1;j>=0;j--){
			B[C[marr[j]%mod]-1] = arr[j];
			C[marr[j]%mod]--;
		}
		for(int i=0;i<n;i++)	marr[i] = B[i];
		return B;
	}
	void Radix(vector<int> arr){
		vector<int> marr(arr.begin(), arr.end());
		for(int d=0;d<3;d++){
			arr = McountingSort(arr,marr);
			for(int i=0;i<arr.size();i++){
				marr[i] /= pow(10,d+1);
			}
		}
		show(arr);
	}
};





int main(){
	// #ifndef tP
	// 	freopen("output.txt","w",stdout);
	// #endif
	AllSorts* as = new AllSorts();
	Practice* p = new Practice();
	vector<int> arr = {6,10,13,5,6,2,4};
	// p->divideStage(arr,0,arr.size()-1);
	// p->show(arr);
	//12,342,33,654,986,876,987,988
	// vector<int> arr = {12,33,987,986,988,876,};
	// p->countingSort(arr,*max_element(arr.begin(), arr.end()));
	// p->McountingSort(arr);
	// p->Radix(arr);
	countingSortV(arr);
	return 0;
}