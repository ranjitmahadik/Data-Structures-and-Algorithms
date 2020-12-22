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


int diameter(TreeNode* root,int& res){
	if(root == NULL)	return -1;
	int l = diameter(root->left,res);
	int r = diameter(root->right,res);

	int	pass = max(l,r) + 1;
	int temp = max(pass,l+r+2); 
	res = max(res,temp);
	return pass;
}


int height(TreeNode* root){
	if(root == NULL)	return -1;
	int l = height(root->left);
	int r = height(root->right);
	return max(l,r)+1;
}

int SlowerDiameter(TreeNode* root){
	if(root == NULL)	return 0;
	int lsbtree = SlowerDiameter(root->left);
	int rsbtree = SlowerDiameter(root->right);
	int mainsubtree = height(root->left) + height(root->right) + 2;
	return max(lsbtree,max(rsbtree,mainsubtree));
}

pair<int,int> FasterDiamter(TreeNode*root){
	if(root == NULL){
		return {-1,0};
	}
	pair<int,int> left  = FasterDiamter(root->left);
	pair<int,int> right = FasterDiamter(root->right);

	pair<int,int> res ;
	res.first  = max(left.first,right.first) + 1;
	res.second = max(left.first+right.first+2,max(left.second,right.second));
	return res;
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


	int res = 0;
	diameter(root,res);
	cout<<res<<" ";
	cout<<SlowerDiameter(root)<<" : "<<FasterDiamter(root).second;

	return 0;
}