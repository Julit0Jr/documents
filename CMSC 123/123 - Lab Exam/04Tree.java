class Node{
	Object item;
	Node left;
	Node right;

	Node(Object item){
		this.item = item;
		left = null;
		right = null;
	}
	static int height(Node node){
		//Fill in your code here
	}
}

class Tree{
	public static void main(String[] args){
		Node a = new Node("a");
		Node b = new Node("b");
		Node c = new Node("c");
		Node d = new Node("d");
		Node e = new Node("e");
		Node f = new Node("f");
		Node g = new Node("g");
		Node h = new Node("h");
		Node i = new Node("i");
		Node j = new Node("j");
		Node k = new Node("k");

		f.left = d;
		f.right = j;
		d.left = b;
		d.right = e;
		j.left = g;
		j.right = k;
		b.left = a;
		b.right = c;
		g.right = i;

		System.out.println(Node.height(f)+ " should be 3");
		System.out.println(Node.height(d)+ " should be 2");
		System.out.println(Node.height(j)+ " should be 2");
		System.out.println(Node.height(b)+ " should be 1");
		System.out.println(Node.height(g)+ " should be 1");
		System.out.println(Node.height(c)+ " should be 0");

	}
}