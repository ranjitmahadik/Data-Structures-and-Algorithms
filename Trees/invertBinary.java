import java.util.*;

class Node{
	char c;
	Node left,right;
	
	Node(char c){
		this.c = c;
	}
	
	Node(char c,Node left,Node right){
		this.c = c;
		this.left = left;
		this.right = right;
	}
	
	static void display(Node root){
		Queue<Node> q = new LinkedList<>();
		q.add(root);
		while(!q.isEmpty()){
			Node p = (Node)q.poll();
			System.out.print(" "+p.c);
			if(p.left != null){
				q.add(p.left);
			}
			if(p.right !=null){
				q.add(p.right);
			}
		}
	}
		
	Node invertTree(Node root){
		if(root == null){
			return root;
		}
		
		Node left = invertTree(root.left);
		Node right= invertTree(root.right);
		root.left = right;
		root.right= left;
		return root;
	}
		
	void invertTreeB(Node root){
		Queue<Node> q = new LinkedList<>();
		q.add(root);
		Node p = null;
		
		while(q.size() > 0){
			p = (Node)q.poll();
			
			
			Node temp = p.left;
			p.left = p.right;
			p.right = temp;
			
			if(p.left != null){
				q.add(p.left);
			}
			if(p.right !=null){
				q.add(p.right);
			}
		}
	}	
		
	
}

class Demo{
	public static void main(String[] args){
		Node root = new Node('a');
		root.left = new Node('b');
		root.right= new Node('c');
		root.left.left = new Node('d');
		root.left.right = new Node('e');
		root.right.left = new Node('f');
		root.display(root);
		System.out.println(" ");
		//root = root.invertTree(root);
		//root.display(root);
		root.invertTreeB(root);
		root.display(root);
		
		
	}
}