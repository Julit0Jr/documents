/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package regexp;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;

/**
 *
 * @author Asus-PC
 */
public class RegExp {
    public static ArrayList <String> input = new ArrayList();
    public static ArrayList expression = new ArrayList();
    public static File file = new File("umacob3.out");
    public static int cases = 0, operation = 0;
    public static ArrayList fileRead(File file){
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
//        for(int i=0; i<input.size(); i++){
//            System.out.println(input.get(i).toString());
//        }
        cases = Integer.parseInt(input.get(0));
        input.remove(0);
        return input;
    }
    public static ArrayList extract(){
        ArrayList<String> list = new ArrayList();
        operation = Integer.parseInt(input.get(1));
        for(int i =0; i < input.get(0).toString().length(); i++){
            expression.add(input.get(0).charAt(i));
        }
        for(int i = 2; i < 2 + operation; i++){ //extraction 
            list.add(input.get(i));
        }
        for(int i = 0; i < 2 + operation; i++){ // deletion of extracted parts from the main inputs
            input.remove(0);
        }
        System.out.println("Extracted: ");
        for(int i=0; i<list.size(); i++){
            System.out.println(list.get(i).toString());
        }     
//        System.out.println("Expression: " + expression);
//        System.out.println("\nInputs Left: ");
//        for(int i=0; i<input.size(); i++){
//            System.out.println(input.get(i).toString());
//        }
        return list;
    }
    public static void solveExp(ArrayList a){
        for(int i = 0; i < a.size(); i++){
            if(expression.contains("(") && expression.contains(")")){
                
            }else if(expression.contains("U")){
                
            }else{
                if(a.contains("*")){
                    if(Collections.frequency(expression, "*")){
                    
                    }
                }else{
                    if(expression.equals(a.get(i).toString())){
                        fileWriter("yes");
                    }else{
                        fileWriter("no");
                    }
                }
            }
        }
    }
    public static void fileWriter(String s){
    	PrintWriter out = null;
	try{
            out = new PrintWriter(new BufferedWriter(new FileWriter(file, true)));
            out.println(s);
	}catch (IOException e) {
            System.err.println(e);
	}finally{
            if(out != null){
                out.close();
            }
        } 
    }
    public static void main(String[] args) {
        File file = new File("mpa3.in");
        int count = 0;
        ArrayList input = fileRead(file);
        ArrayList extr = extract();
//        identifyInput(extract());
//        while(input.size() != 0){
//            l = extract();
//        }
//        while(count < cases-1){
//            //identifyInput(extract());
//            count++;
//        }
    }
    
}
