import java.util.Scanner;
import java.util.*;
import java.text.*;
import java.lang.Math;

public class Group{
	static Scanner scan = new Scanner(System.in);
	static int ni = 0;
	static String[] lowerlimits = null;
	static String[] upperlimits = null;
	static String[] freq = null;
	static float[] midpoints = null;
	static float[] colD = null;
	static float[] colDsqr = null;
	static float totalfreq = 0;
	static float totalColD = 0;
	static float totalCsqr = 0;
	static boolean coll = false;
	static int width = 0;
	static String interpretion = null;
	static String ll, ul;
	static float variance, standev;
	static DecimalFormat df = new DecimalFormat("#.####");
	static int groupChoice = 0;
	static int start = 1;

	// public static void GroupMainPart() throws Exception{
	// 	clear(); boolean cont = true; int choice; getSize(); getVals(); collapse(); ContEd();

	// 	do{
	// 		System.out.println("Select program execution from the choices");
	// 		System.out.println("\t[1] Run the program with the same data");
	// 		System.out.println("\t[2] Run the program with new data");
	// 		System.out.println("\t[3] Exit the program\n");
	// 		System.out.print("\nEnter number of your choice: ");
	// 		choice = scan.nextInt(); clear();
	// 		if(choice==1){
	// 			cont = true; CentralTendency();
	// 		}else if(choice==2){
	// 			cont = true;
	// 			System.out.println("\t-- Enter new data for the simulation --\n");
	// 			getSize(); getVals(); collapse(); ContEd();
	// 		}else{
	// 			clear();
	// 			System.out.println("\nPROGRAM EXITS...\n");
	// 			cont = false;
	// 		}
	// 	}while(cont);
	// }

	public static void GroupMainPart() throws Exception{
			clear(); boolean cont = true; int choice; getSize(); getVals(); collapse(); ContEd();

		do{
			System.out.println("Select program execution from the choices");
			System.out.println("\t[1] Run the program with the same data");
			System.out.println("\t[2] Run the program with new data");
			System.out.println("\t[3] Exit the program\n");
			System.out.print("\nEnter number of your choice: ");
			choice = scan.nextInt(); clear();
			if(choice==1){
				cont = true; CentralTendency();
				groupChoice = 1;
			}else if(choice==2){
				groupChoice = choice;
				//cont = true;
				/*cont = true;
				System.out.println("\t-- Enter new data for the simulation --\n");
				getSize(); getVals(); collapse(); ContEd();*/
			}else{
				clear();
				System.out.println("\nPROGRAM EXITS...\n");
				cont = false;
				groupChoice = choice;
			}
		}while(cont && choice==1);
	}

	public static void phase2() throws Exception{
		System.out.println("\t-- Enter new data for the simulation --\n");
		getSize(); getVals(); collapse(); ContEd();
	}

	public static void phase1() throws Exception{
		clear(); boolean cont = true; int choice; getSize(); getVals(); collapse(); ContEd();
		cont = true; CentralTendency();
	}
	//3.2.1
	public static void getSize(){
		System.out.print("\nEnter number of intervals: ");
		ni = scan.nextInt();
		upperlimits = new String[ni];
		lowerlimits = new String[ni];
		freq = new String[ni];
		midpoints = new float[ni];
		colD = new float[ni];
		colDsqr = new float[ni];
	}

	//3.2.2
	public static void getVals() throws Exception{
		System.out.print("\n\tEnter data:\t[ LC Limit = Lower Class Limit ]\n\t\t\t[ UC Limit = Upper Class Limit ]\n\t\t\t[ Frequency ]\n");
		boolean ch1, ch2 = false;

		for(int i=0; i<ni; i++) {
			 do{
				System.out.print("\n[" + (i+1) + "] " + "LC Limit:\t");
				lowerlimits[i] = scan.next();
			 	ch1 = checkVals(lowerlimits[i]);
			 	if(!ch1 && i==1){
			 		float v1 = Float.parseFloat(lowerlimits[0]);
			 		float v2 = Float.parseFloat(lowerlimits[1]);
			 		width = (int)(v2-v1);
			 	} if(i>0 && !ch1)
			 		ch2 = errorIntervals(i,1);
			 }while(ch1 || ch2);

			 do{
				System.out.print("[" + (i+1) + "] " + "UC Limit:\t");
				upperlimits[i] = scan.next();
			 	ch1 = checkVals(upperlimits[i]);
			 	if(i>0 && !ch1)
			 		ch2 = errorIntervals(i,2);
			 }while(ch1 || ch2);

			do{
				System.out.print("[" + (i+1) + "]" + "Frequency:\t");
				freq[i] = scan.next();
				ch1 = checkVals(freq[i]);
			}while(ch1);	

			totalfreq += Float.parseFloat(freq[i]);
			float val1 = Float.parseFloat(lowerlimits[i]);
			float val2 = Float.parseFloat(upperlimits[i]);
			midpoints[i] = getMidpoints(val1, val2);

			val1 = Float.parseFloat(freq[i]);
			val2 = midpoints[i];
			colD[i] = getColD(val1, val2);
			totalColD += colD[i];
			colDsqr[i] = getColDsqr(val1, val2);
			totalCsqr += colDsqr[i];
		}
		clear();
		dispLimits();
	}

	//3.2.3
  public static void collapse() throws Exception{
		int c = 0;
		System.out.print("\nDo you wish to make your class intervals open-ended?");
		System.out.print("\n\t[1]YES\t[2]NO");
		System.out.print("\nEnter number of your choice: ");
		c = scan.nextInt();

		if(c==1){
			System.out.print("\n\t[1]Collapse First Class Interval\n\t[2]Collapse Last Class Interval\n\t[3]Collapse Both");
			System.out.print("\n\nEnter number of your choice: ");
			int c1 = scan.nextInt();
			if(c1 == 1){
				ll = lowerlimits[0];
				lowerlimits[0] = "<=";
			}else if(c==2){
				ul = upperlimits[ni-1];
				upperlimits[ni-1] = ">=";
			}else{
				ll = lowerlimits[0];
				ul = upperlimits[ni-1];
				lowerlimits[0] = "<=";
				upperlimits[ni-1] = ">=";
			}
			coll = true;
			clear();
		}else{
			coll = false;
			clear(); System.out.println("Nothing changed");
		}
		dispLimits();
	}

	public static void getch(){
		try{
			System.in.read();
		}
		catch(Exception e){}
	}

	//3.2.4
	public static void ContEd() throws Exception{
		boolean flag = false;
		System.out.println("Do you want to Continue the program or Edit the entry(ies)");
		System.out.println("\t[1]Continue\t[2]Edit");
		System.out.print("\nEnter number of your choice: ");
		int c = scan.nextInt(); scan.nextLine(); clear();

		if(c==1){
			System.out.println("Continue Program!");
			clear();
			CentralTendency();
		}else if(c==2){
			System.out.println("Edit entry!");
			editedEntry();
			clear();
			dispLimits();
			getch();
			clear();
			CentralTendency();
		}else{
			flag = true;
		}
	}

	//3.2.5 Edit
	public static void editedEntry() throws Exception{
  	int ed = 0;
  	boolean cont = true; 
  	
  		System.out.println("\nDo you want to edit the class limits?");
  		System.out.println("-- NOTE: Once you edit the class limits, you will enter the whole set of data --");
  		System.out.println("\t[1]YES -- Edit all the values\n\t[2]NO -- Only the Frequency");
  		System.out.print("\nEnter number of your choice: "); int cc = scan.nextInt(); scan.nextLine();
  		if(cc==1){
  			clear();
  			System.out.println("EDIT ALL ENTRIES");
  			getVals();
  		}else{
  			clear();
  			do{
					do{
					  	System.out.println("Enter the class intervals to edit:  ");
					  	System.out.print("\n\tLower Limit: ");
					  	String ll = scan.next();
				  		System.out.print("\n\tUpper Limit: ");
					  	String ul = scan.next();
					  	ed = search(ll, ul);
					  	if(ed == -1){
					  		System.out.println("\n---------------------------------------------------------------------------\n");
					  		System.out.println("   Class Limit Not Found!"); System.out.println("   Re-enter class limit.");
					  		System.out.println("\n---------------------------------------------------------------------------\n");
					  	}else{
					  		System.out.println(ll + " - " + ul + " -- " + ed);
					  	}

				  	}while(ed < 0);

  			totalfreq -= Float.parseFloat(freq[ed]); boolean ch1;
		  	do{
					System.out.print("\nFrequency: ");
					freq[ed] = scan.next();
					ch1 = checkVals(freq[ed]);
				}while(ch1);

		  	totalfreq +=  Float.parseFloat(freq[ed]);
		  	float val1 = Float.parseFloat(lowerlimits[ed]);
		  	float val2 = Float.parseFloat(upperlimits[ed]);
		  	
		  	midpoints[ed] = getMidpoints(val1,val2);
		  	val1 = Float.parseFloat(freq[ed]);
		  	val2 = midpoints[ed];

		  	totalColD -= colD[ed];
		  	colD[ed] = getColD(val1, val2);
				totalColD += colD[ed];
	  	
		  	totalCsqr -= colDsqr[ed];
		  	colDsqr[ed] = getColDsqr(val1, val2);
		  	totalCsqr += colDsqr[ed];

				System.out.println("\nEdit More? \t[1] YES\t[2] NO");
				System.out.print("\nEnter number of your choice: ");
				int c = scan.nextInt();
			
				if(c==1)
					cont = true;
				else
					cont = false;
		 	}while(cont);
  	}
  }

  public static double getVariance(){
  	return((double)(totalfreq*totalCsqr)-(totalColD*totalColD))/(totalfreq*(totalfreq-1));
  }

  public static double getStandardDev(){
  	return (double)((float)Math.sqrt(getVariance()));
  }

  //3.2.6 Continue
  public static void CentralTendency() throws Exception{ 
  	int c; do{
		System.out.print("\nMeasures of central tendency");
		System.out.print("\n\t[1] Mean\n\t[2] Median\n\t[3] Mode\n\t[4] All Measures");
		System.out.print("\nEnter number of your choice: ");
		c = scan.nextInt(); scan.nextLine();

		if(c==1){
			System.out.print("---------------------------------------------------------------------------");
			getMean();
		}else if(c==2){
			System.out.print("---------------------------------------------------------------------------");
			getMedian();
		}else if(c==3){
			System.out.print("---------------------------------------------------------------------------");
			getMode();
		}else if(c==4){
			System.out.print("---------------------------------------------------------------------------");
			getMean();
			getMedian();
			getMode();
		}else{
			clear();
			System.out.println("\t--> Error: Please select number from the given choices");
			System.out.println("---------------------------------------------------------------------------\n\n");
		}}while(c!=1 && c!=2 &&c!=3 && c!=4);
		System.out.println("\n---------------------------------------------------------------------------\n\n");
		System.out.print("\nInput your interpretion: ");
		interpretion = scan.nextLine();
		clear(); 

		System.out.println("Interpretion: " + interpretion);
		System.out.println("---------------------------------------------------------------------------");
		if(c==1){
			getMean();
		}else if(c==2){
			getMedian();
		}else if(c==3){
			getMode();
		}else if(c==4){
			getMean();
			getMedian();
			getMode();
		}
		System.out.println("\n---------------------------------------------------------------------------\n\n");
		

	} 

	public static void getMean(){
		if(coll)
			System.out.println("\n\nMEAN\t== Open-ended class interval!\n\tMean cannot be computed\n");
		else{
			System.out.println("\n\nMEAN\t== " + df.format((double)((totalColD/totalfreq))));
			System.out.println("\n\tVARIANCE = " + df.format((getVariance())));
			System.out.println("\n\tSTANDARD DEVIATION = " + df.format((getStandardDev())) + "\n");
		}
	}

	public static void getMedian(){
		if(coll)
			System.out.print("\n\nMEDIAN\t== Open-ended class interval!\n\tMedian cannot be computed\n");
		else
			System.out.print("\n\nMEDIAN\t== Median not Computed\n");
	}

	public static void getMode() throws Exception{
		System.out.print("\n\nMODE\t== ");
		float[] floatvals = new float[ni];
		for(int i=0; i < floatvals.length; i++){
			floatvals[i] = Float.parseFloat(freq[i]);}

		Arrays.sort(floatvals);
		int max = (int)floatvals[ni-1];
		int ctr = 0, curr = 1;
		float cur;

		ArrayList<String> ll = new ArrayList<>();
		ArrayList<String> ul = new ArrayList<>();

		for(int i = 0; i < ni; i++){
			cur = Float.parseFloat(freq[i]);
			if(cur == max){
				ll.add(lowerlimits[i]);
				ul.add(upperlimits[i]);
				ctr++;}
		}

		if(ctr == 1 && ctr == ni){
			System.out.print("\"No modal\""  + " -- (" + max + ")\n");	
		}else{
			if(ctr == 1 && ctr != ni){
				System.out.print("\"Unimodal\"" + " -- (" + max + ")\n");		
			}else if(ctr == 2 && ctr != ni){
				System.out.print("\"Bimodal\"" + " -- (" + max + ")\n");
			}else if(ctr >= 3 && ctr != ni){
				System.out.print("\"Multimodal\"" + " -- (" + max + ")\n");
			} 
			dispMode(ll,ul, max);
		}
	}

	public static void dispMode(ArrayList<String> ll, ArrayList<String> ul, int max){
		System.out.print("\n\tClass Limit/s\n");
		for(int i=0; i<ll.size(); i++){
			if(ll.get(i) == ">=" || ul.get(i) == "<=")
				System.out.println("\t    " + ll.get(i) + " " + ul.get(i));
			System.out.println("\t    " + ll.get(i) + " - " + ul.get(i));}
	}

  public static int search(String ll, String ul){
		for (int i = 0; i < ni; i++) {
			if(lowerlimits[i].equalsIgnoreCase(ll) && upperlimits[i].equalsIgnoreCase(ul))
				return i;}
		return -1;
	}

	public static boolean errorIntervals(int i, int limit){
		float val1 = Float.parseFloat(lowerlimits[i]);
		float val2 = Float.parseFloat(upperlimits[i-1]); int w = 0;
		float one = decimalPlace(lowerlimits[i]);
		if(limit == 1)
			w = (int)(val1-(Float.parseFloat(lowerlimits[i-1])));
		else if(limit == 2)
			w = (int)((Float.parseFloat(upperlimits[i])-val2));
	
		if(val1 != (val2+1)){
			System.out.println("\t--> Error: Please re-check your data, next lower limit should be " + (int)(val2+1));
			System.out.println("---------------------------------------------------------------------------\n\n");
			return true;
		}else if(w != width){
			System.out.println("\t--> Error: Please re-check your data, width is " + width);
			System.out.println("---------------------------------------------------------------------------\n\n");
			return true;
		}else {
			return false;
		}
	}

	public static boolean checkVals(String s){
		if(!s.matches("[0-9,.]+")){
			System.out.print("\t--> Error: Only accept numbers\n");
			System.out.println("---------------------------------------------------------------------------\n");
			return true;
		}else{
			int count = 0;
			for(int i = 0; i < s.length(); i++){
				if(s.charAt(i) == '.')
					count++;}
			if(count>1){
				System.out.print("\t--> Error: Only accept numbers\n");
				System.out.println("---------------------------------------------------------------------------\n");
				return true;
			}else{
				return false;}
		}
	}

	public static float getMidpoints(float x, float y){
  	return (x+y)/2;
  }

  public static float getColD(float x, float y){
  	return x*y;
	}

  public static float getColDsqr(float x, float y){
  	return x*(y*y);	
  }

  public static void dispLimits() throws Exception{
		System.out.println("\nCLASS LIMITS\t\tFrequency\t\tMidpoints\t\tColumn D\t\tColumn E");
		System.out.println("\n");
		for(int i = 0; i < ni; i++){

			if(i==0 && lowerlimits[0] == "<="){
				System.out.print(lowerlimits[0] + " " + upperlimits[0]);
			}else if(i==(ni-1) && upperlimits[ni-1] == ">="){
				System.out.print(lowerlimits[ni-1] + " " + upperlimits[ni-1]);
			}else if(i==0){
				System.out.print(lowerlimits[0] + " - " + upperlimits[0]);
			}else if(i==(ni-1)){
				System.out.print(lowerlimits[ni-1] + " - " + upperlimits[ni-1]);
			}else{
				System.out.print(lowerlimits[i] + " - " + upperlimits[i]);
			}

			System.out.print("\t\t\t   " + freq[i]);
			System.out.print("\t\t\t   " + midpoints[i]);
			System.out.print("\t\t\t   " + colD[i]);
			System.out.print("\t\t\t   " + colDsqr[i] + "\n\n");
		}

		DecimalFormat dff = new DecimalFormat("#.#");
		System.out.println("\n\nTotal Frequency \t==\t" + totalfreq);
		System.out.println("Total Class Mark    \t==\t" + dff.format(totalColD));
		System.out.println("Total Class Mark^2  \t==\t" + dff.format(totalCsqr));
		System.out.println("\n");
	}


	public static void clear() throws Exception{
    final String os = System.getProperty("os.name");
    if (os.contains("Windows"))
      new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
    else
      Runtime.getRuntime().exec("clear");
  }

  static float decimalPlace(String text){
  		float x = 1;
		int integerPlaces = text.indexOf('.');
		int decimalPlaces = text.length() - integerPlaces - 1;
		if (decimalPlaces == 1){
			if (text.charAt(integerPlaces+1) == '0')
				x = 1;
			else x = 0.1f;
		}
		else if (decimalPlaces == 2){
			x = 0.01f;
		}
		else if (decimalPlaces == 3){
			x = 0.001f;
		}
	}
}