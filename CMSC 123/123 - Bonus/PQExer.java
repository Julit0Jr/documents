import java.util.Queue;

interface PQ{
	Entry min();
	Entry removeMin();
	Entry insert(int key, Object value);
	int size();
	boolean isEmpty();
}
class Entry{
	int key;
	Object value;

	Entry(int key, Object value){
		this.key = key;
		this.value = value;
	}
}

class PQArray implements PQ{
	Entry[] ar;
	int size;
	int index;
	final int ROOT = 1;

	PQArray(){
		size = 0;
		index = 1;
		ar = new Entry[10];
	}

	PQArray(Entry[] a){
		ar = new Entry[a.length];
		for (int i=0;i<a.length ;i++ ) {
			ar[i] = a[i];
		}
		size = a.length-1;
		index = a.length;
	}

	public Entry min(){
		if(size >= 1)
			return ar[ROOT];
		return null;
	}

	public Entry removeMin(){
		//SOLUTION HERE
		if(size == 0)
			return null;
		
		Entry atROOT = ar[ROOT];
		int lastIndex = size;
		Entry atLAST = ar[size];
		int hole = ROOT;
		int smaller = smallerChildIdx(hole);

		while(smaller < lastIndex && atLAST.key > ar[smaller].key) {
			ar[hole] = ar[smaller];
			hole = smaller;
			smaller = smallerChildIdx(hole);
		}
		ar[hole] = atLAST;
		size--;
		index--;

		return atROOT;
	}

	private int smallerChildIdx(int hole){
		int lc = hole*2;
		int rc = hole*2+1;
		int idx = lc;
		if((rc<index-1) && ar[rc].key<ar[lc].key)
			idx = rc;
		return idx;
	}

	public Entry insert(int key, Object value) {
		// SOLUTION HERE
		Entry newEntry = new Entry(key, value);
		int parent = index/2;
		int hole = index;

		while(parent >= ROOT && newEntry.key < ar[parent].key) {
			ar[hole] = ar[parent];
			hole = parent;
			parent = parent/2;
		}
		ar[hole] = newEntry;
		index++;
		size++;

		return newEntry;
	}

	public int size(){
		return size;
	}
	public boolean isEmpty(){
		return size==0;
	}

	public String toString(){
		String s = "";
		for (int i=1;i<size+1;i++) {
				s = s+ ar[i].key+" ";
		}
		return s;
	}


	void bottomUpHeap(){
		//sSOLUTION HERE
		if(size == 0)
			return;
		 
		int parent = size/2;
		Entry temp;
		while(parent >= ROOT) {
			int smaller = smallerChildIdx(parent);
			if(ar[parent].key > ar[smaller].key) {
				temp = ar[smaller];
				ar[smaller] = ar[parent];
				ar[parent] = temp;
			}
			parent = parent/2;
		}		
	}
}

class TestPQ{
	public static void main(String[] args){
		PQArray p = new PQArray();
		p.insert(5, "test");
		p.insert(0, "test");
		p.insert(2, "test");
		p.insert(7, "test");
		p.insert(6, "test");
		p.insert(4, "test");
		p.insert(3, "test");
		System.out.print(p);
		System.out.println("should be 0 5 2 7 6 4 3");
		System.out.print(p.min()!=null?p.min().key:null);
		System.out.println(" should be 0");
		Entry e = p.removeMin();
		System.out.print(e!=null?e.key:null);
		System.out.println(" should be 0");
		System.out.print(p);
		System.out.println(" should be 2 5 3 7 6 4");
		e = p.removeMin();
		System.out.print(e!=null?e.key:null);
		System.out.println(" should be 2");
		System.out.print(p);
		System.out.println(" should be 3 5 4 7 6");
		e = p.removeMin();
		System.out.print(e!=null?e.key:null);
		System.out.println(" should 3 ");
		System.out.print(p);
		System.out.println(" should 4 5 6 7");

		Entry[] a = {null,
					new Entry(2,""),
					new Entry(0,""),
					new Entry(5, ""),
					new Entry(3,""),
					new Entry(7,""),
					new Entry(4,""),
					new Entry(6,"")
					};
		PQArray q = new PQArray(a);
		q.bottomUpHeap();
		System.out.print(q);
		System.out.println("shoud be 0 2 4 3 7 5 6");

	}
}