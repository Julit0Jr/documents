import java.util.*;
import java.lang.*;
class UngroupedData{
	Double[] data;
	Double mean;
	Double median;
	Double[] mode;
	Integer[] mode_i;
	String modeType;
	Double variance;
	Double sd;
	Double range;


	UngroupedData(Double[] d){
		data = new Double[d.length];
		for (int i=0; i<d.length; i++){
			data[i] = (Double)d[i];
		}
		Arrays.sort(data);
	}

	public void setAll(){
		this.setMean();
		this.setMedian();
		this.setMode();
		this.displayMean();
		System.out.print("\n");
		this.displayMedian();
		System.out.print("\n");
		this.displayMode2();
		System.out.print("\n");

	}

	public void displayMean(){
		//System.out.println("\n\n\t\tSummation of inputs\n_____________\n");
		System.out.println("\n\n\t\tMean\t\t\tVariance\t\tStandard Deviation");
		System.out.println("\t\t" + Main.df.format(this.mean) + "\t\t\t" + Main.df.format(this.variance) + "\t\t\t" + Main.df.format(this.sd));
	}

	public void displayMedian(){
		System.out.print("\n\n\t\tData (sorted):\t");
		displaySorted();
		System.out.println("\n\n\t\tMedian\t\t\tRange (max - min)");
		System.out.println("\t\t" + Main.df.format(this.median) + "\t\t\t" + Main.df.format(this.range));
	}

	public void displayMode2(){
		System.out.print("\n\n\t\tData (sorted):\t");
		displaySorted();
		if (mode!=null)
		System.out.print("\n\n\t\tMode(s):\t");
		this.displayMode();
		if (mode!=null)
		System.out.print("\n\t\tMode Type:\t" + this.modeType);
	}


	public void displayMode(){
		if (modeType.equals("Unimodal")){
			System.out.print(Main.df.format(mode[0]));
		}
		else{
			if (mode!=null){
				for (int i=0; mode[i]!=null; i++){
					System.out.print(Main.df.format(mode[i]) + "\t");
				}}
			else if (mode==null){
				System.out.println("\n\n\t\tNo mode.");
			}
	}
	}

	public void setMean(){
		int n = data.length;
		Double sum = 0D;
		for (int i=0; i<data.length; i++){
			sum = sum + data[i];
		}
		mean = (Double)sum/(float)n;

		Double sum2 = 0D;
		for (int i=0; i<data.length; i++){
			sum2 = sum2 + Math.pow(((Double)data[i] - mean),2);
		}
		variance = sum2/(float)data.length-1;
		sd = Math.sqrt(variance);
	}

	public void displaySorted(){
		for (int i=0; i<data.length; i++){
			System.out.print(Main.df.format(data[i]) + "\t");
			if ((i+1)%5==0)
				System.out.print("\n\t\t              \t");
		}
	}

	public void setMedian(){
		int n = data.length;
		int x;
		if (n>1){
		if (n%2!=0){
			x = n/2;
			median = data[x-1];
		}
		else {
			x = n/2;
			median = ((Double)data[x-1] + (Double)data[(x-1) + 1])/2f;
		}
		range = max(data) - min(data);
	}
	else{
		median = data[0];
		range = 0D;
	}
	}

	public void setMode(){
		Double[][] freq = new Double[data.length][data.length];
	    freq[0][0] = data[0];
	    int a=0, b=1, j=1, freqlen = 1;
	    for (int i=0; j<data.length; i++,j++){
	      if (data[i].equals(data[j])==false){
	        a++;
	        b=0;
	      }
	      freq[a][b] = data[j];
	      b++;
	    }
	    a++;
	    Double[] length = new Double[a];
	    for (int i=0; i<a; i++){
	    	length[i] = length(freq[i]);
	    }

	    Double max = max(length);
	    mode = new Double[a];
	    int ctr = 0;
	    for (int i=0; i<a; i++){
	    	if (max.equals(length[i])){
	    		mode[ctr] = freq[i][0];
	    		ctr++;
	    	}
	    }
	    if (ctr == a && a>1){
	    	modeType = "No mode";
	    	mode = null;
	    }
	    else if (ctr == 1){
	    	modeType = "Unimodal";
	    }
	    else if (ctr == 2){
	    	modeType = "Bimodal";
	    }
	    else if (ctr >= 3)
	    	modeType = "Multimodal";

	  }

	  public static Double length(Double[] o){
	  	Double length = 0D;
	  	try{
		  	for (int i=0; o[i]!=null; i++){
		  		length++;
		  	}
	  	}
	  	catch(Exception e){}
	  	return length;
	  }

	  public static Double max(Double[] o){
	  	Double temp = o[0];
	  	try{
		  	for (int i=0; o[i]!=null; i++){
		  		if (o[i] > temp)
		  			temp = o[i];
		  	}
	  	}catch(Exception e){}
	  	return temp;
	  }

	  public static Double min(Double[] o){
	  	Double temp = o[0];
	  	try{
		  	for (int i=0; o[i]!=null; i++){
		  		if (o[i] < temp)
		  			temp = o[i];
		  	}
	  	}catch(Exception e){}
	  	return temp;
	  }

	public static void clear() throws Exception{
	    final String os = System.getProperty("os.name");
	    if (os.contains("Windows"))
	      new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
	    else Runtime.getRuntime().exec("clear");
  	}	
	


	
}