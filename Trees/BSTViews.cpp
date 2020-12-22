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


//Left View
void bfs(TreeNode* root){
	queue<TreeNode*>q;
	q.push(root);
	while(!q.empty()){
		int n = q.size();
		while(n != 1){
			TreeNode* curr = q.front();
			if(curr->left)	q.push(curr->left);
			if(curr->right)	q.push(curr->right);
			q.pop();
			n--;
		}
		TreeNode* pNode = q.front(); q.pop();
		if(pNode->left) q.push(pNode->left);
		if(pNode->right) q.push(pNode->right);
		cout<<pNode->data<<" ";
	}
}

map<int,vector<int>> vt;
void VerticalTraversalDFS(TreeNode* root,int val){
	if(root == NULL)	return;
	vt[val].push_back(root->data);
	VerticalTraversalDFS(root->left,val-1);
	VerticalTraversalDFS(root->right,val+1);
}

map<int,vector<int>> vt2;
void VerticalTraversalBFS(TreeNode* root){
	if (root == NULL)	return;
	queue<pair<TreeNode*,int>> q;
	q.push({root,0});
	while(!q.empty()){
		TreeNode* curr = q.front().first;
		int hd = q.front().second;
		q.pop();
		vt2[hd].push_back(curr->data);
		if(curr->left)	q.push({curr->left,hd-1});
		if(curr->right)	q.push({curr->right,hd+1});	
	}
}

void show(map<int,vector<int>>& mp){
	for(auto& c : mp ){
		cout<<c.first<<" :  ";
		for(int k : c.second){
			cout<<k<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}


void bottomView(){	
/* Vertical Order using BFS gives us Correct Order so if that's true then
   what we can do is print all the nodes except First Node
*/
}
void CircularTraversal(){}

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
	// bfs(root);cout<<endl;
	// topView(root);
	// topView(root->right,false);cout<<endl
	VerticalTraversalDFS(root,0);
	show(vt);
	VerticalTraversalBFS(root);
	show(vt2);
	return 0;
}



	
