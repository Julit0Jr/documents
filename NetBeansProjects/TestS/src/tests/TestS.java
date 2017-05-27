package tests;

import java.util.Iterator;
import java.util.LinkedList;

interface Stack{
	public void push(Object o);
	public Object pop();
	public Object top();
	public int size();
	public boolean isEmpty();
}

class StackEmptyException extends RuntimeException{

}

class StackA implements Stack{
	private LinkedList list;
	private int size;

	StackA(){
		list = new LinkedList();
		size = 0;
	}
	public void push(Object o){
		list.addFirst(o);
		size++;
	}
	public Object pop(){
		if(isEmpty()){
			throw new StackEmptyException();
		}
		Object o = list.removeFirst();
		size--;
		return o;
	}
	public Object top(){
		return list.getFirst();
		//return list.get(0);
	}
	public int size(){
		return size;
	}
	public boolean isEmpty(){
		return size == 0;
	}
	public String toString(){
		Iterator i = list.listIterator(0);
		String s = "";
		while(i.hasNext()){
			s += i.next()+"\n";
		}
		return s;
	}
}
public class TestS{
    public static final String OPEN = "<{([";
    public static final String ClOSE = ">})]";
        
    public static boolean isBalanced(String s){
        StackA bal = new StackA();
        for(int i = 0; i<s.length(); i++){
            for(int j = 0; j<OPEN.length(); j++){
                if(s.charAt(i) == OPEN.charAt(j)){
                    bal.push((char)OPEN.charAt(j));
                    break;
                }
                else if(s.charAt(i) == ClOSE.charAt(j)){
                    if(bal.isEmpty())
                        return false;
                    if(bal.top() == (Object)OPEN.charAt(j)){
                            bal.pop();
                            break;
                    }
                    else
                            return false;
                }
            }
        }
        if( bal.isEmpty()){
            return true;
        }
        return false;
    }
 	public static void main(String[] args){
 		String[] a = {"[]","{{","{)(}","{","{}[]","{{}","{[}]","(/","{({[]})}","{([)]}","<[]{<>}>","<>>"};

 		for(String str: a){
 			System.out.println(str + ": " + isBalanced(str)) ;
 		}
 		/*
 		StackA s = new StackA();
 		System.out.println("size:"+s.size());	
 		System.out.println(s);
 		System.out.println("push 1");
 		s.push(1);
 		System.out.println(s);
 		System.out.println("push 2");
 		s.push(2);
 		System.out.println(s);
 		System.out.print("top:");
 		Object o = s.top();
 		System.out.println(o);
 		System.out.println(s);
 		System.out.print("pop:");
 		o = s.pop();
 		System.out.println(o);
 		System.out.println(s);
 		System.out.print("pop:");
 		o = s.pop();
 		System.out.println(o);
 		System.out.println(s);
 		System.out.print("pop:");
 		o = s.pop();
 		System.out.println(o);
 		System.out.println(s);*/

 	}
 }
