import java.util.LinkedList;
import java.util.Iterator;


interface Queue{
	public void enqueue(Object o);
	public Object dequeue();
	public Object front();
	public int size();
	public boolean isEmpty();
}
class QueueEmptyException extends RuntimeException{

}

class QueueA implements Queue{
	private LinkedList list;
	private int size;

	QueueA(){
		list = new LinkedList();
		size = 0;
	}


	public void enqueue(Object o){
		list.addLast(o);
		size++;
	}
	public Object dequeue(){
		if(isEmpty())
			throw new QueueEmptyException();
		Object o = list.removeFirst();
		size--;
		return o;
	}
	public Object front(){
		return list.getFirst();
	}
	public int size(){
		return size;
	}
	public boolean isEmpty(){
		return size == 0;
	}
	public String toString(){
		String s = "";
		Iterator i = list.listIterator(0);
		while(i.hasNext()){
			s += i.next()+"\t";
		}	
		return s;
	}
}

class TestQA{
	public static void main(String[] args){
		QueueA q = new QueueA();
		System.out.println(q);
		System.out.println(q.size());
		System.out.println("enqueue 1");
		q.enqueue(1);
		System.out.println(q);
		System.out.println("enqueue 2");
		q.enqueue(2);
		System.out.println(q);
		System.out.println("enqueue 3");
		q.enqueue(3);
		System.out.println(q);
		System.out.print("front:");
		Object o = q.front();
 		System.out.println(o);
 		System.out.println(q);
 		System.out.print("dequeue:");
 		o = q.dequeue();
 		System.out.println(o);
 		System.out.println(q);
 		System.out.print("dequeue:");
 		o = q.dequeue();
 		System.out.println(o);
 		System.out.println(q);
 		System.out.print("dequeue:");
 		o = q.dequeue();
 		System.out.println(o);
 		System.out.println(q);
 		System.out.print("dequeue:");
 		o = q.dequeue();
 		System.out.println(o);
 		System.out.println(q);
	}
}