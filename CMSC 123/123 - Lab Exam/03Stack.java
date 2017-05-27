import java.util.LinkedList;

class Stack{
	static int evaluate(String[] s){
		//Fill in your code here
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