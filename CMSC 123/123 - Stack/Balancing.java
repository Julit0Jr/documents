import java.util.LinkedList;
import java.util.Iterator;

class Balancing {
	public static final String OPEN = "{([";
	public static final String CLOSE = "}])";

	public static void main(String[] args){
		String[] a = {"/**/","{{","{)(}","{","{}[]","{{}","{[}]","(/","{({[]})}","{([)]}"};
		for(String str:a){
			System.out.println(str+":"+isBalanced(str));
		}
	}
	public static boolean isBalanced(String s){
		char check = s.charAt(0);

		for(int i = 1; i < s.length(); i++) {
			if((int)check == (int)check + 1 || 
				 (int)check == (int)check + 2) {
				return false;
			}
			if(s.length() % 2 == 0)
				if((int)check == ((int)s.charAt(i)) - 1 || 
					 (int)check == ((int)s.charAt(i)) - 2 ){
						isBalanced(s.substring(1));
						return true;
				}
		}	
		return false;
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
}