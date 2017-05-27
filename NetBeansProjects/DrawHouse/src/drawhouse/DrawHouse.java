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

    public int q;
    public int x=50, y=200; //Body of the House
    public int e = 200 + x, f = 40 + y;//Window
    public int h = 60 + x, i = 70 + y;//Door
    public int j = 220 + x, k = y - 140; //Sun

    public DrawHouse() {
       DrawHouse dlijf = new DrawHouse(1);
    }

    public DrawHouse(int n) {
        //Set JFrame title  
        super("Draw A House In JFrame");
        //Set default close operation for JFrame  
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        //Set JFrame size  
        setSize(1300, 750);
        //Make JFrame visible   
        setVisible(true);
        q = n;
    }

    public void paint(Graphics g) {
        super.paint(g);
        
        if(q==1){ //QUADRANT 1 
            x = 650 + x;
            e = 650 + e;
            h = 650 + h;
            j = 650 + j;          
        }
        if(q==3){ //QUADRANT 3 
            y = 375 + y;
            f = 375 + f;
            i = 375 + i;
            k = 375 + k;
        }
        if(q==4){ //QUADRANT 4
            x = 650 + x; y = 375 + y;
            e = 650 + e; f = 375 + f;
            h = 650 + h; i = 375 + i;
            j = 650 + j; k = 375 + k;
        }
        
        //Draw the Body of the House
        //g.drawRect(x, y, 280, 150);   //draw Rectangle outline  
        g.setColor(Color.BLACK);       //set color to RED
        g.fillRect(x, y, 280, 150);  //fill Rectangle with RED
        
        //Draw the Window of the House
       //g.drawRect(e,f, 50, 50);   //draw Rectangle outline  
       g.setColor(Color.GREEN);       //set color to GREEN
       g.fillRect(e, f, 50, 50);  //fill Rectangle with GREEN
       
       //Draw the Door of the House
       //g.drawRect(h, i, 60, 80);   //draw Rectangle outline  
       g.setColor(Color.BLUE);       //set color to MAGENTA
       g.fillRect(h, i, 60, 80);  //fill Rectangle with MAGENTA
        
        //Draw the Roof of the House
        int a[] = {x, 280 + x, (280+x+x)/2};
        int b[] = {y, y, y-100};
        //g.drawPolygon(a, b, 3);  //draw Polygon outline
        g.setColor(Color.RED);  //set color to BLUE
        g.fillPolygon(a, b, 3);  //fill Polygon with BLUE
        
        //Draw the RAYS of the Sun
        int c[] = {x+x+x+x+x+40, x+x+x+x+x+x, x+x+x+x+x+x+10, x+x+x+x+x+x+45, x+x+x+x+x+x+10, x+x+x+x+x+x, x+x+x+x+x+40, x+x+x+x+x+5};
        int d[] = { y-120,  y-155,  y-120,  y-110, y-100, y-65, y-100,  y-110};
        g.setColor(Color.YELLOW);  //set color to BLUE
        g.fillPolygon(c, d, 8);  //fill Polygon with BLUE
        //2nd
        int l[] = {x+x+x+x+x+15, x+x+x+x+x+x, x+x+x+x+x+x+35, x+x+x+x+x+x+15, x+x+x+x+x+x+35, x+x+x+x+x+x, x+x+x+x+x+15, x+x+x+x+x+35};
        int m[] = { y-140,  y-125,  y-140,  y-110, y-80, y-95, y-80,  y-110};
        g.setColor(Color.YELLOW);  //set color to BLUE
        g.fillPolygon(l, m, 8);  //fill Polygon with BLUE
        
        /*int c[] = {290, 300, 310, 345, 310, 300, 290, 255};
        int d[] = { 80,  45,  80,  90, 100, 135, 100,  90};
        g.setColor(Color.YELLOW);  //set color to BLUE
        g.fillPolygon(c, d, 8);  //fill Polygon with BLUE
        //2nd
        int l[] = {265, 300, 335, 315, 335, 300, 265, 285};
        int m[] = { 60,  75,  60,  90, 120, 105, 120,  90};
        g.setColor(Color.YELLOW);  //set color to BLUE
        g.fillPolygon(l, m, 8);  //fill Polygon with BLUE */
        
        //Draw the SUN
        //g.drawOval(j, k, 60, 60);   //draw Circle outline  
        g.setColor(Color.YELLOW);       //set color to YELLOW
        g.fillOval(j, k, 60, 60);  //fill Circle with YELLOW
    }

    public static void main(String[] args) {
     int inp=0;
        while(inp<1 || inp>4){
        System.out.println("In what quadrant to print[1,2,3,4]):  ");
        Scanner ss= new Scanner(System.in);
        inp = ss.nextInt();
        }
        DrawHouse dlijf = new DrawHouse(inp);
    }
}
