/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package bufferedreader;

/**
 *
 * @author Asus-PC
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
 
/**
 *
 * @author www.javadb.com 
 */
public class Main {
 
    public static void main(String[] args) {
 
        try {
            
            System.out.println("Input a number :  ");

            try (BufferedReader reader = new BufferedReader(new InputStreamReader(System.in))) {
                String input = reader.readLine();
                
                double number = Double.parseDouble(input);
                
                System.out.println("Square root of input number " +  input + " is: " + Math.sqrt(number));
                
                //Not really necessary in this case but since we want to
                //write clean code...
            }
            
        } catch (IOException e) {
            e.printStackTrace();
        } catch (NumberFormatException e) {
            System.out.println("Input by user was not a number.");
            e.printStackTrace();
        }
    }
}
