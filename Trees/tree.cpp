#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

void printTree(TreeNode<int>* root){
	cout<<root->data<<" : ";
	for(int i=0;i<root->children.size();i++){
		cout<<root->children[i]->data<<",";
	}
	cout<<endl;
	for(int i=0;i<root->children.size();i++){
		printTree(root->children[i]);
	}
}
int heightOfTree(TreeNode<int>* root){
	int ans = 1;
	for(int i=0;i<root->children.size();i++){
		int temp = heightOfTree(root->children[i]);
		ans = max(ans,temp+1);
	}
	return ans;
}

void sumOfDepts(TreeNode<int>* root,int& ans,int depth){
	if(root == nullptr)	return;
	ans += depth;
	for(int i=0;i<root->children.size();i++){
		sumOfDepts(root->children[i],ans,depth+1);
	}
}

void getDept(TreeNode<int>* root,int& ans){
	sumOfDepts(root,ans,0);
	for(int i=0;i<root->children.size();i++){
		getDept(root->children[i],ans);
	}
}


/*																ans
				1							- 0 				0		
			2			3					- 1					1		12
		4		5	6		7				- 2	2				3		11
	8		9								- 3	3				6		9			

*/


int main(){
	#ifndef Tree
		freopen("output.txt","w",stdout);
	#endif

	TreeNode<int>* root = new TreeNode<int>(1);
	TreeNode<int>* node1 = new TreeNode<int>(2);
	TreeNode<int>* node2 = new TreeNode<int>(3);
	TreeNode<int>* node3 = new TreeNode<int>(4);
	TreeNode<int>* node4 = new TreeNode<int>(5);
	TreeNode<int>* node5 = new TreeNode<int>(6);
	TreeNode<int>* node6 = new TreeNode<int>(7);
	TreeNode<int>* node7 = new TreeNode<int>(8);
	TreeNode<int>* node8 = new TreeNode<int>(9);

	root->children.push_back(node1);
 	root->children.push_back(node2);
 	node1->children.push_back(node3);
 	node1->children.push_back(node4);
 	node2->children.push_back(node5);
 	node2->children.push_back(node6);
 	node3->children.push_back(node7);
 	node3->children.push_back(node8);
 	
 	// printTree(root);
 	// cout<<"Height of Tree is : "<<heightOfTree(root)<<endl;
	// delete root; 
	int ans = 0;
 	// sumOfDepts(root,ans,0);
	getDept(root,ans);
	cout<<ans;

	return 0;
}