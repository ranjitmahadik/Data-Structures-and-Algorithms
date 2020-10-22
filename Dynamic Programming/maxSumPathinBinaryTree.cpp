#include<bits/stdc++.h>
using namespace std;

/*
	Problem Link => "https://www.interviewbit.com/problems/max-sum-path-in-binary-tree/"
*/


class TreeNode{
public:
	int data;
	TreeNode* left,*right;
	TreeNode(int data){
		this->data = data;
		right = left = NULL;
	}
};

// Time Complexity => O(n)
int maxSumPath(TreeNode* root,int& res){
	if(root == NULL)	return 0;

	int l = maxSumPath(root->left,res);
	int r = maxSumPath(root->right,res);

	int pass = max(max(l,r)+root->data,root->data);
	int temp = max(pass,l+r+root->data);
	res = max(res,temp);
	return pass;
}

/*
		Tree : 
				1
			2		3			ans => 6
		-4		-1

*/


int main(){
	#ifndef MaxSumPathinBinaryTree
		freopen("output.txt","w",stdout);
	#endif
	TreeNode* root = new TreeNode(1);
	root->left  = new TreeNode(2);
	root->left->left = new TreeNode(-4);
	root->left->right = new TreeNode(-1);
	root->right = new TreeNode(3);
	int ans = 0;
	maxSumPath(root,ans);
	cout<<ans;
	return 0;
}