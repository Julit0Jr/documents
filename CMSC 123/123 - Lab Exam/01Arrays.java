class Arrays{
	static int[] merge(int[] a, int[] b){
		//Write your solution here
	}
	static void print(int[] ar){
		for (int a:ar){
			System.out.print(a+" ");
		}
	}
	public static void main(String[] args){
			int[] a = {1,2,5,6,7};
			int[] b = {2,3,4,4};
			int[] c = merge(a,b);
			print(c);
			System.out.println("should be 1 2 2 3 4 4 5 6 7");

			int[] g = {0,0,1};
			int[] h = {1,1,2};
			int[] i = merge(g,h);
			print(i);
			System.out.println(" should be 0 0 1 1 1 2");

			int[] d = {};
			int[] e = {1,1,2};
			int[] f = merge(d,e);
			print(f);
			System.out.println(" should be  1 1 2");
			
			int[] j = {};
			int[] k = {};
			int[] l = merge(j,k);
			print(l);
			System.out.println(" should be  ");

			int[] m = {0};
			int[] n = {};
			int[] o = merge(m,n);
			print(o);
			System.out.println(" should be  0");

			int[] p = {1};
			int[] q = {0};
			int[] r = merge(p,q);
			print(r);
			System.out.println(" should be  0 1");
	}
}