/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package mypublicclasses;

/**
 *
 * @author Asus-PC
 */
public class Customer {
    private String name, email;
    private char gender;
    
    public Customer(){
        name = null;
        email = null;
        gender = '\0';
    }
    
    public String getName(){
        return name;
    }
    public String getEmail(){
        return email;
    }
    public char getGender(){
        return gender;
    }
    
    public void setName(String n){
        name = n;
    }
    public void setEmail(String em){
        email = em;
    }
    public void setGender(char g){
        gender = g;
    }
    
    public String displayCustomerInfo(){
        String info;
        return info = getName() +" ("+ getGender() +") "+" at "+ getEmail();
    }   
    
    public String formatLetterGreeting(){
        String greet;
        
        if(getGender()== 'm')
            return greet = "Dear Mr. " + getName();
        else
            return greet = "Dear Ms. " + getName();
    }  
}
