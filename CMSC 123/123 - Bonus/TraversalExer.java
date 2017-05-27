import java.util.LinkedList;
import java.util.Queue;
import java.util.Iterator;

class Node{
	Object item;
	Node left;
	Node right;
	Node(Object item){
		this.item = item;
		left = right = null;
	}
	static void preorder(Node node){
		if(node != null) {	
			System.out.print(node.item);
			preorder(node.left);
			preorder(node.right);
		}
	}
	static void inorder(Node node){
		if(node != null) {
			inorder(node.left);
			System.out.print(node.item);
			inorder(node.right);
		}
	}
	static void postorder(Node node){
		if(node != null) {
			postorder(node.left);
			postorder(node.right);
			System.out.print(node.item);
		}
	}

	static void levelorder(Node node){
		if(node == null)
			return;
		else {
			Queue<Node> queue = new LinkedList<Node>();
			queue.add(node);

			while(!queue.isEmpty()) {
				Node newNode = queue.remove();
				System.out.print(newNode.item);
				if(newNode.left != null)
					queue.add(newNode.left);
				if(newNode.right != null)
					queue.add(newNode.right); 
			}
		}
}

}
class Test{
	public static void main(String[] args){
		Node a = new Node("a");
		Node b = new Node("b");
		Node c = new Node("c");
		Node d = new Node("d");
		a.left = b;
		a.right = c;
		b.right = d;

		System.out.println("preorder should be a b c:");
		Node.preorder(a);
		System.out.println();
		System.out.println("inorder should be b a c:");
		Node.inorder(a);
		System.out.println();
		System.out.println("postorder should be b c a:");
		Node.postorder(a);
		System.out.println();
		System.out.println("levelorder: should be a b c:");
		Node.levelorder(a);
		System.out.println();
	}
}