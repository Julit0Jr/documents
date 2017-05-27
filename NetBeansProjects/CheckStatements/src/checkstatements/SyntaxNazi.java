/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package checkstatements;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.Collections;

/**
 *
 * @author Asus-PC
 */
public class SyntaxNazi {
    public static String[] dType = {"int", "char", "double", "float"};
    public static String invalidvar = "Invalid variable declaration!";
    public static String invalidfunc = "Invalid function declaration!";
    public static String invaliddef = "Invalid function definition!";
    public static String validvar = "Valid variable declaration!";
    public static String validfunc = "Valid function declaration!";
    public static String validdef = "Valid function definition!";
    public static String sym = ";{}()[]+-*/=,";
    public static String rtrn = "return";

    public static String Tokenizer(File file){
        String concat = "";
        try{
            BufferedReader br = new BufferedReader(new FileReader(file));
         	String line;

         	while ((line = br.readLine()) != null) {
                    concat  = concat + line + " ";
                }
      	}catch(Exception e){
         	e.printStackTrace();
      	}
        return concat;
    }
    public static ArrayList eConcat(String s){
        ArrayList <String> str = new ArrayList();
        String con = "";
        Character c;
        boolean flag = true; 
        
        for(int i = 0; i < s.length(); i++){
            if(s.charAt(i) == ';'&& !(con.contains("{"))){
                con = con + s.charAt(i);
                str.add(con);
                //System.out.println(con);
                con = "";
            }
            else if(s.charAt(i) == '}' && con.contains("{")){
                con = con + s.charAt(i);
                str.add(con);
                //System.out.println(con);
                con = "";
            }
            else{
                con = con + s.charAt(i);
            }
        }
//        System.out.println(str.size());        
//        for(int i = 0; i<str.size(); i++){
//            System.out.println(str.get(i));
//        }
        return str;
    }
    public static ArrayList eArray(String s){
        ArrayList <String> str = new ArrayList();
        String con = "";
        Character c;
        boolean flag = true; 
//        System.out.println(s);
        
        for(int i = 0; i < s.length(); i++){
            if(s.charAt(i) == ' '){
                if(flag == false){
                    if(!(con == "")){
                        str.add(con);
                        con = "";
                    }
                    flag = true;
                }
            }
            else if(sym.indexOf(s.charAt(i)) >= 0){
                if(!(con == "")){
                    str.add(con);
                    con = "";
                }
                c = s.charAt(i);
                str.add(c.toString());
                flag = false;
            }
            else{
                con = con + s.charAt(i);
                flag = false;
                if(i+1 == s.length() && con!= "")
                    str.add(con);
            } 
        }
//        System.out.println(str.size());        
//        for(int i = 0; i<str.size(); i++){
//            System.out.println(str.get(i));
//        }
        return str;
    }   
    public static int checkString(ArrayList <String> s){ 
//        System.out.println(s.size());
        if(s.size() > 2){
            if(!(s.get(2).charAt(0) == '(')){
                //System.out.println("It is a variable declaration!");
                return 0;
            }else{
                //System.out.println("It is a function!");
                if(s.get(s.size() - 1).charAt(0) == ';'){
                    return 1;
                }else{
                    return 2;
                }
            }
        }
        else return 0;
    }
    public static String checkVarDec(ArrayList <String> s){
//        System.out.println(s.size());
        if((!(Arrays.stream(dType).parallel().anyMatch(s.get(0)::contains)))){
            return invalidvar;
        }
        for(int i = 1; i < s.size(); i++){
            if(s.get(i-1).charAt(0) == ';'){
                return invalidvar;
            }
            if(Arrays.stream(dType).parallel().anyMatch(s.get(i)::contains)){
                return invalidvar;    
            }
            else{
                int num = 0, let = 0;
                for(int j = 0; j < s.get(i).length(); j++){
                    if(!((s.get(i).charAt(j) >= 'A' && s.get(i).charAt(j) <= 'Z') || (s.get(i).charAt(j) >= 'a' && s.get(i).charAt(j) <= 'z') || (s.get(i).charAt(j) >= '0' && s.get(i).charAt(j) <= '9') || s.get(i).charAt(j) == '_' || s.get(i).charAt(j) == 39) && s.get(i).length() != 1){
                        return invalidvar;    
                    }
                    else if(s.get(i).charAt(j) == ',' || s.get(i).charAt(j) == '=' || s.get(i).charAt(j) == ';'){
                        if(Arrays.stream(dType).parallel().anyMatch(s.get(i-1)::contains) || s.get(i-1).charAt(0) == ',' || s.get(i-1).charAt(j) == '=' || s.get(i-1).charAt(j) == ';')
                            return invalidvar;
                    }
                    else if(s.get(i).charAt(j) >= '0' && s.get(i).charAt(j) <= '9'){
                        num++;
                    }
                    else if(s.get(i).charAt(j) >= 'A' && s.get(i).charAt(j) <= 'Z' || s.get(i).charAt(j) >= 'a' && s.get(i).charAt(j) <= 'z' || s.get(i).charAt(j) >= '_'){
                        let++;
                    }
                }
                if(num == s.get(i).length() && (Arrays.stream(dType).parallel().anyMatch(s.get(i-1)::contains) || s.get(i-1).charAt(0) != '=' || s.get(i-1).length() > 1)){
                    return invalidvar;
                }
                else if(!(s.get(i-1).charAt(0) == ',' || s.get(i-1).charAt(0) == '=') && let > 0 && i!=1){
                    //System.out.print(let);
                    return invalidvar;
                }
            }
        }
       return validvar;
    }
    public static String checkFuncDec(ArrayList <String> s){
        if((!(Arrays.stream(dType).parallel().anyMatch(s.get(0)::contains))) || s.get(s.size()-1).charAt(0) != ';'){
            return invalidfunc;
        }
        else if((s.get(2).charAt(0) == '(' && s.get(s.size()-2).charAt(0) == ')' && !(Arrays.asList(dType).contains(s.get(3))))){
            return invalidfunc;
        }
        else if(!(s.get(2).charAt(0) == '(' && s.get(s.size()-2).charAt(0) == ')')){
            return invalidfunc;
        }else{ 
            int type = 0;
            for(int i = 1; i < s.size(); i++){
                if(Arrays.stream(dType).parallel().anyMatch(s.get(i)::contains)){
                    type++;
                }
                else if((Arrays.asList(dType).contains(s.get(i)))){
                    if(s.get(i-1).charAt(0) == '(' || s.get(i-1).charAt(0) == ','){
                        return invalidfunc;
                    }
                }
            }
//            System.out.println(type - 1 +"  "+Collections.frequency(s, ","));
            if(Collections.frequency(s, ",") != 0){
                if(type - 1 != Collections.frequency(s, ",")){
                    return invalidfunc;
                }
            } else if(Collections.frequency(s, ",") == 0){
                if(type - 1 != Collections.frequency(s, ",")){
                    return invalidfunc;
                }
            }
        }
        return validfunc;
    }
    public static String checkFuncDef(ArrayList <String> s){
        ArrayList r = new ArrayList();
        
        if((!(Arrays.stream(dType).parallel().anyMatch(s.get(0)::contains))) || s.get(s.size()-1).charAt(0) != '}')
            return invaliddef;
        for(int i = 1; i < s.size(); i++){
            if(s.get(i).charAt(0) == ')' && (Arrays.asList(dType).contains(s.get(i-1)))){
             return invaliddef;
            } 
          
            r.add(s.get(i));
        }
        return validdef;
    }
    public static void writeFile(String s, String fname){
        BufferedWriter bw = null;
        FileWriter fw = null;

        try {

                fw = new FileWriter(fname);
                bw = new BufferedWriter(fw);
                bw.write(s);

                bw.close();
                fw.close();

        } catch (IOException e) {

                e.printStackTrace();

        }
    }
    
    public static void FileWriter(File file, String s){
    	PrintWriter out = null;
		try 
		{
		    out = new PrintWriter(new BufferedWriter(new FileWriter(file, true)));
		    out.println(s);
		}
		catch (IOException e) 
		{
		    System.err.println(e);
		}
		finally
		{
		    if(out != null)
		    {
		        out.close();
		    }
		} 
    }
    
    public static void main(String[] args) {
        int n;
        File file = new File("mpa1.in"), out = new File("mpa1.out");
      	String tokenized = Tokenizer(file), fname = "mpa1.out";
        ArrayList <String> str = eConcat(tokenized);
        ArrayList <String> substr = new ArrayList();
        for(int i = 0; i<str.size(); i++){
            substr = eArray(str.get(i));
//          System.out.println(substr.size());
            n = checkString(substr);
            if(n == 0){
                FileWriter(out, checkVarDec(substr));
                System.out.println(checkVarDec(substr));
            }
            else if(n == 1){
                FileWriter(out, checkVarDec(substr));
                System.out.println(checkFuncDec(substr));
            }
            else{
                FileWriter(out, checkVarDec(substr));
                System.out.println(checkFuncDef(substr));
            }
        }
//        System.out.println(tokenized);
//        System.out.println(checkString(eArray("int function ( int i );")));
//        System.out.println(checkString(eArray("int a , y , b = 3;")));s
    }
    
}
