class X {
	void printing () {
		System.out.println("X class");
	}
}

class Y extends X {
	void printing () {
		System.out.println("Y class");
	}
}

class Tester {
	public static void main(String[] args) {
		X xa = new X();
		X ya = new Y();
		Y yay = new Y();

		ya = xa;
		xa = (X) ya;
	}
}
