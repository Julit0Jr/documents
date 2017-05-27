/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package TestCLasses;

import mypublicclasses.Customer;

/**
 *
 * @author Asus-PC
 */
public class TestCustomer {
    public static void main(String[] args){
        Customer s,c;
        
        s = new Customer(); //creates a customer s
        s.setName("Julius Morgan A. Umacob");
        s.setEmail("jm@yahoo.com");
        s.setGender('m');
        
        System.out.println(s.getName()); //displays the name of customer 
        System.out.println(s.displayCustomerInfo()); //displays the customer's info
        
        s.setEmail("jmau@yahoo.com"); //changes the customer's email
        System.out.println(s.getEmail()); //displays the new email
        
        System.out.println(s.formatLetterGreeting()); //displays the letter greeting
        
        c = new Customer(); //creates a customer c
        c.setName("Julie Mirzi A. Umacob");
        c.setEmail("jum@yahoo.com");
        c.setGender('f');
        
        System.out.println(c.getName()); //displays the name of the new customer
    }
}