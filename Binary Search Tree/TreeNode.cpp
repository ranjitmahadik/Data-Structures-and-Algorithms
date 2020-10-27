#include<bits/stdc++.h>
using namespace std;

template<typename T>
class TreeNode{
public:
	T data;
	TreeNode*left,*right;
	TreeNode(){}
	TreeNode(T data){
		this->data = data;
		left = right = NULL;
	} 

	void inOrder(TreeNode<T>* root){
		if(root == NULL)	return ;
		inOrder(root->left);
		cout<<root->data<<" ";
		inOrder(root->right);
	}

	void postOrder(TreeNode<T>* root){
		if(root == NULL)	return;
		postOrder(root->left);
		postOrder(root->right);
		cout<<root->data<<" ";
	}

	void preOrder(TreeNode<T>* root){
		if(root == NULL)	return;
		cout<<root->data<<" ";
		preOrder(root->left);
		preOrder(root->right);
	}

	T getMax(TreeNode<T>* root){
		if(root != NULL && root->right == NULL){
			return root->data;
		}
		return getMax(root->right);
	}

	T getMin(TreeNode<T> * root){
		if(root != NULL && root->left == NULL){
			return root->data;
		}
		return getMin(root->left);
	}

	bool search(TreeNode<T> * root,T key){
		if(root == NULL)	return false;
		if(root->data == key)	return true;
		if(root->data < key)	return search(root->right,key);
		else
			return search(root->left,key);
	}

	TreeNode<T>* insert(TreeNode<T>*root,T key){
		if(root == NULL){
			return new TreeNode<T>(key);
		}else if(key > root->data){
			root->right = insert(root->right,key); 
		}else{
			root->left  = insert(root->left,key);
		}
		return root;
	}

	int getHeight(TreeNode<T>* root){
		if(root == NULL)	return -1;
		int l = getHeight(root->left);
		int r = getHeight(root->right);
		return max(l,r)+1;
	}
	int noOfNode(TreeNode<int>* root){
		if(root == NULL)	return 0;
		int l = noOfNode(root->left);
		int r = noOfNode(root->right);
		return l+r+1;	
	}

	void bfs(TreeNode<T>*root){
		queue<TreeNode<T>*> q;
		q.push(root);
		while(!q.empty()){
			TreeNode* curr = q.front();
			cout<<curr->data<<" ";
			if(curr->left != NULL)	q.push(curr->left);
			if(curr->right != NULL)	q.push(curr->right);
			q.pop();
		}
	}
};
	
int main(){

	#ifndef TreeNode
		freopen("output.txt","w",stdout);
	#endif

	TreeNode<int>* root = new TreeNode<int>(16);
	root->insert(root,8);root->insert(root,24);root->insert(root,6);
	root->insert(root,12);root->insert(root,18);root->insert(root,28);
	root->insert(root,4);root->insert(root,6);root->insert(root,14);
	root->insert(root,26);root->insert(root,30);

	// root->inOrder(root);
	// cout<<"\nMax Item is : "<<root->getMax(root);
	// cout<<"\nMin Item is : "<<root->getMin(root);
	// cout<<"\nElement 22 is present ?[Y/N] "<<(root->search(root,22)==true?"Y":"N");
	// root->FindParents(root,INT_MIN);
	// root->printParents();
	// cout<<"height of Tree is -> "<<root->getHeight(root);
	// cout<<"\nTotal Number of Nodes in Tree are -> "<<root->noOfNode(root)<<endl;
	root->bfs(root);	
	return 0;
}