#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
	int data;
	TreeNode* left,*right;
	TreeNode(int data){
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

void dfs(TreeNode* root){
	if(root == NULL)	return;
	dfs(root->left);
	cout<<root->data<<" ";
	dfs(root->right);
}

void sumOfheights(TreeNode* root,int& ans,int height){
	if(root == NULL)	return;
	ans+=height;
	sumOfheights(root->left,ans,height+1);
	sumOfheights(root->right,ans,height+1);
}

void getAllheights(TreeNode* root,int& ans){
	if(root == NULL)	return;
	sumOfheights(root,ans,0);
	getAllheights(root->left,ans);
	getAllheights(root->right,ans);
}

pair<int,int> heightDp(TreeNode* root,int& ans){
	pair<int,int> p = {1,0};		//No of Nodes,Sum Of heights
	if(root->left){
		pair<int,int> pChild = heightDp(root->left,ans);
		p.second += pChild.second + pChild.first;
		p.first += pChild.first;
	}
	if(root->right){
		pair<int,int> pChild = heightDp(root->right,ans);
		p.second += pChild.second + pChild.first;
		p.first += pChild.first;
	}
	ans += p.second;
	return p;
}

int main(){
	#ifndef TreeNode
		freopen("output.txt","w",stdout);
	#endif

	TreeNode* root = new TreeNode(1);
	root->left  = new TreeNode(2);
	root->left->left = new TreeNode(4);
	root->left->right= new TreeNode(5);
	root->right = new TreeNode(3);
	root->right->right= new TreeNode(7);
	root->right->left= new TreeNode(6);
	int ans = 0;
	// getAllheights(root,ans);
	pair<int,int> ans1 = heightDp(root,ans);
	cout<<ans;

	return 0;
}