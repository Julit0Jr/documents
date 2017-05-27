import java.util.*;
import java.lang.Math;
import java.text.*;
import java.lang.*;
import javax.swing.*;
import java.awt.event.*;
class Main{
	static Double[] dataset;
	static String[] inputs;
	static Scanner scan = new Scanner(System.in);
	static DecimalFormat df = new DecimalFormat("#");
	static String description;
	static int ungroupedChoice;

	public static void main(String[] args) throws Exception{
		Scanner scan = new Scanner(System.in);
		int choice = 1;

		int choice4=0;
		do{
		UngroupedData.clear();
		do{
		System.out.println("\n\n\t\tChoose type of data to be inputted: ");
		System.out.print("\n\n\t\t1. Ungrouped\n\t\t2. Grouped\n\n\t\tEnter the number of your choice: ");
		choice4 = scan.nextInt();
		}while(!validChoice(2,choice4));
		if (choice4==1 || ungroupedChoice==2){
			phase1();
				getch();
				UngroupedData.clear();
				display();
				do{
				getch();
				System.out.println("\n\n\n\t\tChoose your next action:\n\n\t\t1. Run the program again (using the same data)"
					+ "\n\t\t2. Run the program again (using a new set of data)\n\t\t3. Exit the program");
				do{
				System.out.print("\n\n\t\tEnter the number of your choice: ");
				choice = scan.nextInt();
				}while(!validChoice(1,choice));
				if (choice==1){
					ungroupedChoice = 1;
					phase2();
				}
				else if (choice == 2){
					ungroupedChoice = choice;
				}
				else if (choice==3)
					ungroupedChoice = choice;
				}while(choice == 1);
				if (ungroupedChoice!=3)
					ungroupedChoice = 0;
		}
		else if (choice4==2){
			if (Group.groupChoice == 2){
				System.out.println("\t-- Enter new data for the simulation --\n");
				Group.getSize(); Group.getVals(); Group.collapse(); Group.ContEd();
			}
			Group.GroupMainPart();
			if (Group.groupChoice!=3)
				Group.groupChoice = 0;
		}
		if (ungroupedChoice==3 || Group.groupChoice==3)
			break;
		}while(ungroupedChoice!=3 || Group.groupChoice!=3);


	}

	static void phase1() throws Exception{
		UngroupedData.clear();
		System.out.println("\n");
		System.out.print("Enter the size of your input: ");
		int size = scan.nextInt();
		System.out.print ("\n\n");

		inputs = new String[size];
		for (int i=0; i<size; i++){
			do{
			System.out.print("\nInput [" + (i+1) + "]	");
			inputs[i] = scan.next();
			}while (!valid(inputs[i]));
		}

		parseInput(inputs);
		UngroupedData.clear();
		display();

		int choice2 = 0;
		int index = 0;
		do{
			System.out.println("\n\n\t\tChoose your next action: \n\n\t\t1. Edit entry(ies)\n\t\t2. Continue");
			do{
			System.out.print("\n\n\t\tEnter the number of your choice: ");
			choice2 = scan.nextInt();
			}while(!validChoice(2,choice2));
			if (choice2==1){
				UngroupedData.clear();
				display();
				do{
				System.out.print("\n\n\tEnter the index number of the entry you want to edit:\t");
				index = scan.nextInt();
				}while(!validIndex(index));
				do{
				System.out.print("\n\n\tEnter the new value of Input [" + index + "]:\t");
				inputs[index-1] = scan.next();
				}while(!valid(inputs[index-1]));
				insertNewInput(inputs[index-1],index-1);
				getch();
				UngroupedData.clear();
				display();
			}
		}while (choice2!=2);
		phase2();
	}

	static void phase2() throws Exception{
		decimalPlace();
		UngroupedData d = new UngroupedData(dataset);
		UngroupedData.clear();
		display();
		int choice3 = 0;
		System.out.println("\n\n\t\tChoose the measures of central tendency to calculate:\n\n\t\t1. Mean\n\t\t2. Median" +
			"\n\t\t3. Mode\n\t\t4. All measures");
		do{
		System.out.print("\n\n\t\tEnter the number of your choice: ");
		choice3 = scan.nextInt();
		}while(!validChoice(3,choice3));
		UngroupedData.clear();
		display();
		if (choice3 == 1){
			d.setMean();
			d.displayMean();
			System.out.print("\n\n\t\tInterpretation: ");
			description = scan.next();
		}
		else if (choice3 == 2){
			d.setMedian();
			d.displayMedian();
			System.out.print("\n\n\t\tInterpretation: ");
			description = scan.next();
		}
		else if (choice3 == 3){
			d.setMode();
			d.displayMode2();
			System.out.print("\n\n\t\tInterpretation: ");
			description = scan.next();
		}
		else if (choice3 == 4){
			d.setAll();
			System.out.print("\n\n\t\tInterpretation: " );
			description = scan.next();
		}
	}

	static boolean valid(String x){
		boolean valid = true;
		if (!x.matches("[0-9,.]+"))
			{valid = false;
			System.out.print("\n\tInvalid input. Please enter another value.\n");
			}
		return valid;
	}

	static void parseInput(String[] data){
		dataset = new Double[data.length];
		for (int i=0; i<data.length; i++){
			dataset[i] = Double.parseDouble(data[i]);
		}
	}

	static void insertNewInput(String data, int index){
		dataset[index] = Double.parseDouble(data); 
	}

	static void display() throws Exception{
		System.out.println("\n-----------------------------------------------------------------------------------------------------");
		for (int i=0; i<dataset.length; i++){
			System.out.print("[" + (i+1) + "] " + df.format(dataset[i]) + "\t\t");
			if ((i+1)%5 == 0){
				System.out.print("\n");
			}
		}
		System.out.println("\n-----------------------------------------------------------------------------------------------------");
	}

	static void decimalPlace(){
		String text = Double.toString(Math.abs(dataset[0]));
		int integerPlaces = text.indexOf('.');
		int decimalPlaces = text.length() - integerPlaces - 1;
		if (decimalPlaces == 1){
			if (text.charAt(integerPlaces+1) == '0')
				df = new DecimalFormat("#.#");
			else df = new DecimalFormat("#.##");
		}
		else if (decimalPlaces == 2){
			df = new DecimalFormat("#.###");
		}
		else{
			df = new DecimalFormat("#");
		}
	}

	public static void getch(){
		try{
			System.in.read();
		}
		catch(Exception e){}
	}

	public static boolean validChoice(int c, int choice){
		boolean valid = true;
  		if (c==2 && (choice!=1 && choice!=2))
  			valid = false;
  		else if (c==3 && (choice<1 && choice>4))
  			valid = false;
  		else if (c==1 && (choice<1 && choice>3))
  			valid = false;
  		if (!valid)
  			System.out.print("\n\n\t\tInvalid choice.\n");
  		return valid;
  	}

  	public static boolean validIndex(int index){
  		boolean valid = true;
  		if(index>dataset.length){
  			valid = false;
  			System.out.print("\n\n\tInvalid index.\n");}
  		return valid;
  	}
}