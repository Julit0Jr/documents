import java.util.*;
class Main2{
	public static void main(String[] args) throws Exception{
		UngroupedData.clear();
		int choice = 2;
		int choice4 = 0;
		Scanner scan = new Scanner (System.in);
		do{
		if (choice==2){
		do{
		System.out.println("\n\n\t\tChoose type of data to be inputted: ");
		System.out.print("\n\n\t\t1. Ungrouped\n\t\t2. Grouped\n\n\t\tEnter the number of your choice: ");
		choice4 = scan.nextInt();
		}while(!Main.validChoice(2,choice4));
		if (choice4==1){
			Main.phase1();
			Main.getch();
			UngroupedData.clear();
			Main.display();
		}
		else if (choice4==2){
			Group.phase1();
		}
		}
		else if (choice==1){
			if (choice4==1){
				Main.phase2();
				Main.getch();
				UngroupedData.clear();
				Main.display();
			}
			else if (choice4==2){
				Main.getch();
				UngroupedData.clear();
				Group.phase2();
			}
		}
		System.out.println("\n\n\n\t\tChoose your next action:\n\n\t\t1. Run the program again (using the same data)"
					+ "\n\t\t2. Run the program again (using a new set of data)\n\t\t3. Exit the program");
				do{
					System.out.print("\n\n\t\tEnter the number of your choice: ");
					choice = scan.nextInt();
				}while(!Main.validChoice(1,choice));
		}while(choice!=3);

	}

}