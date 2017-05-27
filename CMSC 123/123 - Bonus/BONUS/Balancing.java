import java.util.LinkedList;
import java.util.Iterator;
import java.util.Stack;

class Balancing {
	public static final String OPEN = "{([";
	public static final String CLOSE = "]})";

	public static void main(String[] args){
		// String[] a = {"/**/","{{","{)(}","{","{}[]","{{}","{[}]","(/","{({[]})}","{([)]}"};
		String[] a = {"[]","{{","{)(}","{","{}[]","{{}","{[}]","(/","{({[]})}","{([)]}"};
		for(String str:a){
			System.out.println(str+":"+isBalanced(str));
		}
	}

	public static boolean isBalanced(String s) {
		Stack<Character> value = new Stack<Character>();

		if(!isValidOpen(s.charAt(0)) && isValidClose(s.charAt(0))) {
			return false;
		}

		for(int i = 0; i < s.length(); i++) {
			char x = s.charAt(i);
			if(!isValidOpen(x) && !isValidClose(x)) {
				return false;
			} else {
				if(OPEN.indexOf(x) != -1) {
					value.push(x);
				} else {
					char o = value.pop();
					if(!match(o, x)) {
						return false;
					}
				}
			}
		}

		return value.isEmpty() ? true : false;
	}

	private static boolean match(char open, char close){
		if((open=='(' && close==')') || 
		   (open=='{' && close=='}') ||
		   (open=='[' && close==']'))
			return true;
		return false;
	}
	private static boolean isValidOpen(char s){
		return OPEN.indexOf(s) > -1;
	}

	private static boolean isValidClose(char s){
		return CLOSE.indexOf(s) > -1;
	}

	// Output: []:true
	// {{:false
	// {)(}:false
	// {:false
	// {}[]:true
	// {{}:false
	// {[}]:false
	// (/:false
	// {({[]})}:true
	// {([)]}:false
	/*
		loop from 0 until the end of the string 
		
	*/
}