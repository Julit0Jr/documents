import java.io.*;
import java.util.*;

public class Main {
	public static ArrayList  <String> input = new ArrayList();
	public static String expression = "";
	public File file = new File("umacob3.out");
	public static int cases = 0, operation = 0;
	public static void fileRead(File file){
        try{
            BufferedReader br = new BufferedReader(new FileReader(file));
         	String line;
                int i = 0;
         	while ((line = br.readLine()) != null) {
                    //concat  = concat + line + " ";
                    input.add(line);
                    i++;
                }
      	}catch(Exception e){
         	e.printStackTrace();
      	}
        cases = Integer.parseInt(input.get(0));
        input.remove(0);
    }
    public static ArrayList extract(){
        ArrayList<String> list = new ArrayList();
        operation = Integer.parseInt(input.get(1));
        expression = input.get(0).toString();
        for(int i = 2; i < 2 + operation; i++){ //extraction 
            list.add(input.get(i));
        }
        for(int i = 0; i < 2 + operation; i++){ // deletion of extracted parts from the main inputs
            input.remove(0);
        }
        return list;
    }


    public static void main(String[] args) {
    	File file = new File("mpa3.in");
        int count = 0;
        fileRead(file);
        for(int x = 0; x <input.size(); x++){
            ArrayList extr = extract();
            for(int i = 0; i < extr.size(); i++){
                State startstate = NFA.post2nfa(Postfix.in2post(expression));
                Boolean matches = NFAsimulation.simulateNFA(startstate, extr.get(i).toString());
                if(matches)
                    System.out.println("yes");
                else
                    System.out.println("no");
        }
        }
    }
}
