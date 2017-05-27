import java.util.*;
class Run{
	public static void main(String[] args) throws Exception{
			UngroupedData.clear();
			Scanner scan = new Scanner(System.in);
			System.out.println("\n\n\t\tChoose type of data to be inputted: ");
			System.out.print("\n\n\t\t1. Ungrouped\n\t\t2. Grouped");
			int choice = scan.nextInt();
			int c = 0;
			do{
			if (choice == 2){
				Group data = new Group();
				data.GroupMainPart();
			}
			else if (choice==1){
				Main data = new Main();
				data.Ungrouped();
			}
		}while (c!=3);
		}	
}