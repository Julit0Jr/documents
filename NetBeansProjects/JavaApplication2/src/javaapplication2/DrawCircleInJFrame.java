/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication2;

/**
 *
 * @author Asus-PC
 */
    import java.util.Scanner;
    import javax.swing.JFrame;  
    import java.awt.Graphics;  
    import java.awt.Color;  
      
    public class DrawCircleInJFrame extends JFrame  {  
    public DrawCircleInJFrame(){
        //Set JFrame title  
        super("Draw A Circle In JFrame");   
        //Set default close operation for JFrame  
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);   
        //Set JFrame size  
        setSize(400,400);  
        //Make JFrame visible   
        setVisible(true);
    }  
    public DrawCircleInJFrame(int n)  {  
     //Set JFrame title  
     super("Draw A Circle In JFrame");   
     //Set default close operation for JFrame  
     setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);   
     //Set JFrame size  
     setSize(400,400);  
     //Make JFrame visible   
     setVisible(true);
    }  
    public void paint(Graphics g)  
    {
    int x = 20, y= 40, h= 50, w=50;
     super.paint(g);  
               //draw Figure outline  
               g.drawOval(x,y,75,75);
               //set color to BLUE 
               //So after this, if you draw anything, all of it's result will be BLUE  
               g.setColor(Color.BLUE);  
               //fill circle with BLUE 
               g.fillOval(x,y,75,75);
    } 
    public static void main(String[]args)  
    {
     //DrawCircleInJFrame dlijf = new DrawCircleInJFrame();
     
     //int inp; 
     
     //System.out.println("Enter number of inputs:  ");
     //Scanner sc= new Scanner(System.in);
     //inp = sc.nextInt();
     DrawCircleInJFrame dlijf = new DrawCircleInJFrame();  
    }  
    }  