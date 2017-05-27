/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package drawhouse;

/**
 *
 * @author Asus-PC
 */
import java.util.Scanner;
import javax.swing.JFrame;
import java.awt.Graphics;
import java.awt.Color;

public class DrawHouse extends JFrame {

    public int num;

    public DrawHouse() {
        //Set JFrame title  
        super("Draw A House In JFrame");
        //Set default close operation for JFrame  
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        //Set JFrame size  
        setSize(400, 400);
        //Make JFrame visible   
        setVisible(true);
    }

    public DrawHouse(int n) {
        //Set JFrame title  
        super("Draw A House In JFrame");
        //Set default close operation for JFrame  
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        //Set JFrame size  
        setSize(400, 400);
        //Make JFrame visible   
        setVisible(true);
        num = n;
    }

    public void paint(Graphics g) {
        super.paint(g);
        int x = 50, y = 200;
        
        //Draw the Body of the House
        g.drawRect(x, y, 280, 150);   //draw Rectangle outline  
        g.setColor(Color.RED);       //set color to RED
        g.fillRect(x, y, 280, 150);  //fill Rectangle with RED
        
        //Draw the Window of the House
       g.drawRect(x, y, 280, 150);   //draw Rectangle outline  
       g.setColor(Color.GREEN);       //set color to GREEN
       g.fillRect(x, y, 280, 150);  //fill Rectangle with GREEN
        
        //Draw the Roof of the House
        int a[] = {50, 330, 190};
        int b[] = {200, 200, 100};
        g.drawPolygon(a, b, 3);  //draw Rectangle outline
        g.setColor(Color.BLUE);  //set color to RED
        g.fillPolygon(a, b, 3);  //fill Rectangle with RED
    }

    public static void main(String[] args) {
     //DrawCircleInJFrame dlijf = new DrawCircleInJFrame();

     //int inp; 
     //System.out.println("Enter number of inputs:  ");
        //Scanner sc= new Scanner(System.in);
        //inp = sc.nextInt();
        DrawHouse dlijf = new DrawHouse();
    }
}
