#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
	int data;
	TreeNode* left,*right;
	TreeNode(int data){
		this->data = data;
		right = left = NULL;
	}
};

int maxSumPath(TreeNode* root,int& res){
	if(root == NULL)	return 0;

	int l = maxSumPath(root->left,res);
	int r = maxSumPath(root->right,res);

	int pass = max(l,r) + root->data;
	int temp = max(pass,l+r+root->data);
	res =  max(res,temp);
	return pass;
}


int main(int argc, char const *argv[])
{
	#ifndef LeafToLeaf
		freopen("output.txt","w",stdout);
	#endif

	TreeNode* root = new TreeNode(-1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(23);
	//Left Part
		root->left->left = new TreeNode(20);
		root->left->right = new TreeNode(40);
	//right Part
		root->right->left = new TreeNode(-90);
		root->right->right = new TreeNode(0);

	int ans = 0;
	maxSumPath(root,ans);
	cout<<ans;

	return 0;
}