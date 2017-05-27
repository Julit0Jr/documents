/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Main;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import javax.swing.JComponent;
import javax.swing.JFrame;

/*
 *
 * @author Asus-PC
 */
class mainDraw extends JComponent{
    public int q;
    public int x=200, y=200; //Body of the House
    public int e = x/4, f = y/4;//Window
    //public int h = x/4+(x/20*3), i = y/2;//Door
    public int o = x, p = y;
    
@Override
public void paintComponent(Graphics g) {
        super.paintComponent(g);
        int h =650,j=200+650,k =100+650,l =375,m =375,n =100+375;
        int ah = h,aj =j,ak =k,al =l,am =m,an =n;
        int x = 350, y = 350, d1=75,d2=5;
        int o= 200,p= 400,q= 400,r= 200;
	int oo= 500,pp= 500,qq= 300,rr= 300; 
           
        g.drawOval(x,y,d1,d2);
           d1+=10;
           d2+=10;
           x-=2;  
           y+=5;
           int c[] = { o, p, q, r};
           int d[] = {oo,pp,qq,rr};
           g.drawPolygon(c,d,4);
           oo-=5;
           pp+=5;
           qq+=5;
           rr-=5;
//        for(int i = 0; i<=25 ; i++){
//	int a[] = {h,j,k};
//	int b[] = {l,m,n};
//	g.drawPolygon(a, b, 3);
//	h+=5;
//	k+=5;
//	j-=5;
//	int cc[] = {ah,aj,ak};
//	int dd[] = {al,am,an};
//	g.drawPolygon(cc, dd, 3);
//	ah+=5;
//	ak-=5;
//	aj-=5;
//
//	l-=5;
//	m+=5;
//	n+=5;
//        al+=5;
//        am-=5;
//        an+=5;
//        } 
        
        //Draw the Body of the House
        g.drawRect(o, p, x, y);
        g.fillRect(o, p, x, y);
        g.setColor(Color.BLACK);
        
       //Draw the Window of the House
       g.setColor(Color.GREEN);       //set color to GREEN
       g.fillRect(o+(x/2)+(x/10),p+y/4,e, f);  //fill Rectangle with GREEN
       
       //Draw the Door of the House  
       g.setColor(Color.BLUE);       //set color to MAGENTA
       g.fillRect(o+(x/10),(y/2)+p,h, i);  //fill Rectangle with MAGENTA
        
        //Draw the Roof of the House
        int a[] = {o, o + x, (o+o+x)/2};
        int b[] = {p, p, p-(y/2)};
        //g.drawPolygon(a, b, 3);  //draw Polygon outline
        g.setColor(Color.RED);  //set color to BLUE
        g.fillPolygon(a, b, 3);  //fill Polygon with BLUE
        
    }
public void moveDown() {
        y = y - 5;
        x = x - 5;
        e = x/4; 
        f = y/4;
        //h = x/4+(x/20*3); 
        //i = y/2;
        repaint();
    }
public void moveUp() {
        y = y + 5;
        x = x + 5;
        e = x/4; 
        f = y/4;
        //h = x/4+(x/20*3); 
        //i = y/2;
        repaint();
    }
public void moveMouse(int c, int d) {
        o = c;
        p = d;
        repaint(); 
    }
}
