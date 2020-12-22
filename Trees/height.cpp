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
	int lh = height(root->left);
	int rh = height(root->right);
	return max(lh,rh) + 1;
}

void showPath(vector<int>&path){
	for(int i:path)	cout<<i<<" ";
}

//path from root to node x;
bool pathFromRoot(TreeNode* root,vector<int>& path,int x){
	if(root == NULL)	return 0;
	bool a = pathFromRoot(root->left,path,x);
	bool b = pathFromRoot(root->right,path,x);
	path.push_back(root->data);
	if(root->data == x){
		return 1;
	}
	if(a || b)	return 1;
	path.pop_back();
	return 0;
}

TreeNode* LCA(TreeNode* root,int x,int y){
	if(root == NULL)	return NULL;
	if(root->data == x || root->data == y)	return root;
	TreeNode* left  = LCA(root->left,x,y);
	TreeNode* right = LCA(root->right,x,y);
	if(left != NULL && right != NULL)	return root;
	if(left != NULL || right != NULL)	return left==NULL?right:left;
	return NULL;
}

void combinepath(vector<int>& p1,vector<int> p2){
	int n = p2.size();
	if(n > 0){
		p2.pop_back();
		n--;
	}
	for(int i=n-1;i>=0;i--)	p1.push_back(p2[i]);
}

void pathFromAtoB(TreeNode* root,int x,int y){
	if(root == NULL)	return;
	TreeNode* lca = LCA(root,x,y);			//O(n)
	cout<<lca->data;
	vector<int> path1,path2;
	pathFromRoot(lca,path1,x);
	pathFromRoot(lca,path2,y);				//O(logn)
	// combinepath(path1,path2);
	// showPath(path1);
}


int main(){
	#ifndef Tree
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
	vector<int> path1;
	// cout<<LCA(root,10,40)->data;
	// pathFromAtoB(root,10,40);
	something();
	return 0;
}