import java.lang.*;

class Testing {
	public void printing() {
		System.out.println("Testing 1");
	}
}

class Testing2 extends Testing{
	public void printing() {
		System.out.println("Testing 2");
	}
}

public class TESTering {
	public static void main(String[] args) {
		Testing2 te =  new Testing2();
		te.printing();
	}
}
