import java.util.LinkedList;
import java.util.ArrayList;

class Stack{
	static int evaluate(String[] s){
		  int temp = 0;
			LinkedList ans = new LinkedList();
			for(int i = 0; i < s.length; i++){
				if(!isOperand(s[i])){
					ans.addFirst(Integer.parseInt(s[i]));
				} else {
					temp = result((int)(ans.removeFirst()), (int)(ans.removeFirst()), s[i]);
					ans.addFirst(temp);
				}
			}
			return temp;
		
	}
	static int result(int a, int b, String operand){
		int result = 0;
		if(operand.equals("+")){
			result =  a+b;
		}else if(operand.equals("-")){
			result = a - b;
		}else if(operand.equals("*")){
			result = a * b;
		}else if(operand.equals("/")){
			result = a/b;
		}
		return result;
	}
	static boolean isOperand(String o){
		String[] op = {"+","-","*","/"};
		for (String p:op) {
			if(p.equals(o)){
				return true;
			}
		}
		return false;
	}
	public static void main(String[] args){
		String a = "4 5 2 + -";
		//4 5 2 + -
		//4 7 - 
		//3
		String[] s = a.split(" ");
		System.out.println(Stack.evaluate(s)+" should be 3");

		//2 2 1 * / 3 2 - -
		//2 2 / 3 2 - -
		//1 3 2 - -
		//1 -1 -
		//-2
		System.out.println(Stack.evaluate("2 2 1 * / 3 2 - -".split(" ")) + " should be -2");

		String c = "1 9 3 4 4 - 3 - * / +";
		//1 9 3 0 3 - * / +
		//1 9 3 3 * / +
		//1 9 9 / +
		//1 1 +
		//2
		System.out.println(Stack.evaluate(c.split(" ")) + " should be 2");

	}
}