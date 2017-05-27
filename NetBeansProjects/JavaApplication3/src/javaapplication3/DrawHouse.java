/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication3;

/**
 *
 * @author Asus-PC
 */

    import java.util.Scanner;
    import javax.swing.JFrame;  
    import java.awt.Graphics;  
    import java.awt.Color; 

public class DrawHouse extends JFrame  {  
    public int num;
    public DrawHouse(){
        //Set JFrame title  
        super("Draw A House In JFrame");   
        //Set default close operation for JFrame  
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);   
        //Set JFrame size  
        setSize(400,400);  
        //Make JFrame visible   
        setVisible(true);
        num  = 1;
    }  
    public DrawHouse(int n)  {  
     //Set JFrame title  
     super("Draw A House In JFrame");   
     //Set default close operation for JFrame  
     setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);   
     //Set JFrame size  
     setSize(400,400);  
     //Make JFrame visible   
     setVisible(true);  
     num = n;
    }  
    public void paint(Graphics g)  
    {
        int x = 50, y= 200;
         super.paint(g);  
        //draw circle outline  
        g.drawRect(x,y,280,150);
        int a[]= {200,300,250};
        int b[]= {200,200,100};
        g.drawPolygon(a,b,3);
        //set color to RED
        //So after this, if you draw anything, all of it's result will be RED 
        g.setColor(Color.RED);  
        //fill circle with RED
        g.fillRect(x,y,280,150);
    } 
    public static void main(String[]args)  
    {
     //DrawCircleInJFrame dlijf = new DrawCircleInJFrame();
     
     //int inp; 
     
     //System.out.println("Enter number of inputs:  ");
     //Scanner sc= new Scanner(System.in);
     //inp = sc.nextInt();
     DrawHouse dlijf = new DrawHouse(); 
    }  
    }  