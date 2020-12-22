#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
	int data;
	TreeNode* left,*right;
	TreeNode(int data){
		this->data = data;
		left  = NULL;
		right = NULL;
	}
};


int height(TreeNode* root){
	if(root == NULL)	return -1;
	int l = height(root->left);
	int r = height(root->right);
	return max(l,r)+1;
}

bool isBalanced(TreeNode* root){
	if(root == NULL)	return 1;
	bool left  = isBalanced(root->left);
	bool right = isBalanced(root->right);
	if(!left || !right)	return 0;
	int leftHeight  = height(root->left)+1;
	int rightHeight = height(root->right)+1;

	int ans = abs(leftHeight - rightHeight);
	if(ans >= 2){
		return 0;
	}
	return 1;
}

// height,isBalanced
pair<int,bool> isBalancedFaster(TreeNode*root){
	if(root == NULL){
		return {-1,1};
	}
	pair<int,bool> left  = isBalancedFaster(root->left); 
	pair<int,bool> right = isBalancedFaster(root->right);
	int currHeight = max(left.first,right.first)+1; 
	if(!left.second || !right.second)	return {currHeight,0}; 
	int leftHeight  = left.first + 1;	
	int rightHeight = right.first + 1;
	int ans = abs(leftHeight - rightHeight);
	if( ans >= 2)	return {currHeight,0};
	return {currHeight,1};
}

int main(int argc, char const *argv[])
{
	#ifndef Diameter
		freopen("output.txt","w",stdout);
	#endif
	TreeNode* root= new TreeNode(50);
	root->left  = new TreeNode(40);
	root->right = new TreeNode(60);
	root->left->left  = new TreeNode(20);
	root->left->right = new TreeNode(45);
	root->left->right->left = new TreeNode(42);
	root->left->right->right = new TreeNode(47);	
	root->left->left->left  = new TreeNode(10);
	root->left->left->right = new TreeNode(25); 
	root->right->left = new TreeNode(55);
	root->right->right = new TreeNode(65);

	cout<<isBalanced(root)<<" "<<isBalancedFaster(root).second;
	return 0;
}



	
