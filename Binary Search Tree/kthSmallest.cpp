#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
	int data;
	TreeNode*left,*right;
	TreeNode(){}
	TreeNode(int data){
		this->data = data;
		left = right = NULL;
	} 
};

vector<int> inorder;
void approchOne(TreeNode *root,int K){
	// Perform Inorder Traversal to get sorted array and the return K-1 item
	if(root == NULL)	return;
	approchOne(root->left,K);
	inorder.push_back(root->data);
	approchOne(root->right,K);
}

int approchTwo(TreeNode* root,int& K){
	if(root == NULL)	return INT_MAX;
	int l =approchTwo(root->left,K);
	if(l != INT_MAX)	return l;
	K--;
	if(K == 0)	return root->data;
	int r = approchTwo(root->right,K);
	return r;
}

int main(){
	#ifndef kthSmallest
		freopen("output.txt","w",stdout);
	#endif

	TreeNode* root =new TreeNode(16);
	root->left = new TreeNode(10);root->right = new TreeNode(20);
	root->left->left = new TreeNode(5);root->left->right = new TreeNode(12);
	root->left->left->left = new TreeNode(4);root->left->left->right = new TreeNode(7);
	int k = 3;
	approchOne(root,k);
	cout<<"3th smallest element is : "<<inorder[k-1]<<":"<<approchTwo(root,k);
	return 0;
}