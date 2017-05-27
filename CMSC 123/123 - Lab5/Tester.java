interface Z {
	public static final int got = 8;
}

class X{
	public static final int got = 7;
	public void implement() {
		System.out.printf("X class");
	}
	public void sameMethod() {
		System.out.println("X Same Method");
	}
}

class Y extends X  implements Z{
	public void implement(int i) {
		System.out.printf("Y class");
	}
	public void sameMethod() {
		super.sameMethod();
	}
	public static void main(String[] args) {
		//System.out.println(got); PART 3 Letter B.
		System.out.println("X Final = " + X.got);
		System.out.println("Y Final = " + Z.got);
	}
}

class Tester {
	public static void main(String[] args) {

	//PART 1.
		X[] xa = new Y[2];
		Y[] ya = new Y[2];

		xa = ya;
		ya = (Y[]) xa;

		//answers

		//a.
			/*We can only assign ya to xa but not the other way around.
				Casting is needed when we assign xa to ya in order for it to have a compatible type since xa is in type X[]*/

		//b.
			/* 	We can assign xa to ya but we can't assign ya to xa because xa is a subclass which needs casting. */

		X[] xa1 = new Y[2];
		//ya = xa1;
		xa1 =  ya;

		//c.
			/* We can't assign ya to xa but we can assign ya to xa.
				 Same thing will happen if the object created is in type X[] with Y classes values.
				 Because the object created is still in type X[].*/

	//PART 2.
		//a
			/* YES! It will compile.*/

		//b
			/* It won't compile because the methods that is declared in the interface and the class where it was implemented needs
				 to have the same prototype.*/

		//c
			/* It still won't compile. It needs to have the same parameter type.*/

		//d
			/*It will compile. As long as the return type and the number of parameter and its type is the same.*/

	//Part 3.
		//a
			/*YES! It will compile and it won't make any difference.*/

		//b
			/*NO! Java won't compile the program. It will say that the variable used is ambiguous. */

		//c
			/*We need to modify it through specifying the class where the final variable you want to access is found.*/

	//PART 4.

		//a
			Y ya1= new Y();
			((X) ya1).implement();

			/*It will call the superclass.*/

		//b
			X xa2= new X();
			//((Y) xa2).implement();

			/*It will compile but when you run the program, there will be an error ClassCastException which says that the superclass
				can't be casted to its subclass.*/

		//c
			Y ya2 =  new Y();
			//ya2.sameMethod();
			/* We cannot access the method in the super class without going through the method in subclass because the object created is in the type of the subclass*/
	}
}