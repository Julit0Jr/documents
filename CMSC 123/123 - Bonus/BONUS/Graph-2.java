import java.util.Stack;

class Graph{
	private boolean[][] matrix;
	private boolean[] visited;
	private int vertices;

	Graph(int vertices){
		matrix = new boolean[vertices][vertices];
		for (int i=0; i<vertices; i++ ) {
			for (int j=0; j<vertices ;j++ ) {
				matrix[i][j] = false;
			}
		}
		this.vertices = vertices;
	}

	private void resetVisited(){
		visited = new boolean[vertices];
		for (int i=0;i<vertices;i++ ) {
			visited[i] = false;
		}
	}
	//precondition: v and w are valid vertices
	public void addEdge(int v, int w){
		if(isValidVertex(v) && isValidVertex(w))
			matrix[v][w] = true;
	}
	private boolean isValidVertex(int v){
		return v>=0 && v<vertices;
	}

	public	String toString(){
		String s = "";
		for (int i=0;i<vertices ;i++ ) {
			for (int j=0; j<vertices ; j++ ) {
				s = s + (matrix[i][j]?" T ":" . " + "");
			}
			s = s + "\n";
		}
		return s;
	}

	// public void dfs(int vertex){
	// 	visited[vertex] = true;
	// 	System.out.print(vertex+">");
	// 	for (int i=0; i<vertices; i++ ) {
	// 		if(matrix[                 ][i] && !visited[i])
	// 			// visited[i] = true;
	// 			dfs(i);
	// 	}
	// }

	public void dfs(int vertex) {
		Stack<Integer> stack = new Stack<Integer>();
		stack.push(vertex);
		int ctr = 0;
	
		while(!stack.isEmpty()) {
			if(ctr == vertices) {
				break;
			}

			int v = stack.pop();
			System.out.print(v+">");
			if(!visited[v]) {
				visited[v] = true;
				ctr++;
				for(int i = vertices-1; i >= 0; i--) {
					if(matrix[v][i] && !visited[i]) {
						stack.push(i);
					}
				}	
			}
		}
	}

	public static void main(String[] args) {
		Graph g = new Graph(6);
		g.addEdge(0,2);
		g.addEdge(0,3);
		g.addEdge(0,4);
		g.addEdge(1,3);
		g.addEdge(1,4);
		g.addEdge(1,5);
		g.addEdge(2,0);
		g.addEdge(2,3);
		g.addEdge(2,4);
		g.addEdge(3,0);
		g.addEdge(3,1);
		g.addEdge(3,2);
		g.addEdge(4,0);
		g.addEdge(4,1);
		g.addEdge(4,2);
		g.addEdge(5,1);
		System.out.println(g);
		g.resetVisited();
		g.dfs(5);
		System.out.println();

	}
}