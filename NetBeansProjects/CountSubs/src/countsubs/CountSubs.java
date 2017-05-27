/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package countsubs;

import java.io.FileReader;
import java.util.Scanner;

/**
 *
 * @author Asus-PC
 */

public class CountSubs {
   public static void main(String[] args) throws Exception{
       int count = 0;
       String str, str2;
       FileReader file = new FileReader("day.txt");
       Scanner read = new Scanner(file);
       
       System.out.println("Enter String: ");
       Scanner sc = new Scanner(System.in);
       str = sc.next();
       
       while (read.hasNextLine() || read.hasNext()){
           str2 = read.nextLine();
           for(int i= 0; i<= str2.length()- str.length(); i++){
               if (str.equals(str2.substring(i, str.length()+i)))
                   count++;
           }
       }
       System.out.println("The string existed " +count + " times.");
   }
}
