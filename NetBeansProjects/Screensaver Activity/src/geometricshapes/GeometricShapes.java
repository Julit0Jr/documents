/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package geometricshapes;

import java.awt.Color;
import java.awt.Graphics;
import javax.swing.JFrame;

/**
 *
 * @author Asus-PC
 */
public class GeometricShapes extends JFrame implements GeometricSHape{
    public GeometricShapes(){
        super("Geometric Shapes");//Set JFrame title
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);//Set default close operation for JFrame 
        setSize(1300,750); //Set JFrame size
        setVisible(true);//Make JFrame visible  
    }  
    public void draw(Graphics g){
       paint(g);
    }
    public Color getRandomColor(){
        int r = (int)(Math.random()*256),g = (int)(Math.random()*256),b = (int)(Math.random()*256);
		return new Color(r,g,b);
    }

    public void paint(Graphics g){
        super.paint(g);
        int uuu=0;
        
        while(uuu<=1){
            int cx = 657, cy = 382, d1 = 10, d2 = 10;
            int ax = cx/4 + cx/2, bx = cx/4 + cx;
            int ay = cy/2 + cy/16 , by = (cy/2-cy/16) + cy;
            int redo = 25;
            int h = 160,j = 290,k = 225,l = 350,m = 350,n = 175; //triangle dimension
            int ah = h,aj =j,ak =k,al =l,am =m,an =n; //triangle dimension
            int hh = 160 +cx+cx/4+cx/16+cx/64,jj = 290+cx+cx/4+cx/16+cx/64,kk = 225+cx+cx/4+cx/16+cx/64; //triangle dimension
            int bh = hh,bj = jj,bk = kk; //triangle dimension
            int aaa= 650, bbb= 375, xxx=25;
            int ccc=aaa, qqq=aaa,ddd=bbb, fff=bbb, jjj=aaa, hhh=bbb;
            int kkk=aaa, lll=bbb;
            int mmm=aaa;
            int nnn=bbb;
            int ooo=aaa,ppp=bbb;
            int ccx = 307,ccy = 32,dd1= 710,dd2=710;
            
            for(int i = 0; i<=70 ; i++,cx-=5,ax-=5,bx-=5,cy-=5,ay-=5,by-=5,d1+=10,d2+=10){
                if(uuu%2 == 0){
                    g.setColor(Color.BLACK); 
                    System.out.println("black");
                }
                if(uuu%2 != 0){
                    g.setColor(Color.WHITE); 
                    System.out.println("white");
                }
                //else
                 //   g.setColor(Color.BLUE);
                g.drawOval(cx,cy,d1,d2);
                g.drawOval(ccx,ccy,dd1,dd2);
                ccx-=5;
                ccy-=5;
                dd1+=10;
                dd2+=10;
                
                if(i<=50){
                    if(i<40){
                        /*if(uuu%2 != 0){
                            g.setColor(Color.WHITE); 
                            System.out.println("white");
                        }
                        else
                            g.setColor(Color.GREEN);*/
                        //Triangles
                        int a[] = {h,j,k};
                        int b[] = {l,m,n};
                        g.drawPolygon(a, b, 3);
                        h+=5;
                        k+=5;
                        j-=5;
                        int c[] = {ah,aj,ak};
                        int d[] = {al,am,an};
                        g.drawPolygon(c, d, 3);
                        ah+=5;
                        ak-=5;
                        aj-=5;           

                        //2nd Triangle
                            
                        int aa[] = {hh,jj,kk};
                        int bb[] = {l,m,n};
                        g.drawPolygon(aa, bb, 3);
                        hh+=5;
                        kk+=5;
                        jj-=5;
                        int cc[] = {bh,bj,bk};
                        int dd[] = {al,am,an};
                        g.drawPolygon(cc, dd, 3);
                        bh+=5;
                        bk-=5;
                        bj-=5;
                    
                        l-=5;
                        m+=5;
                        n+=5;
                        al+=5;
                        am-=5;
                        an+=5;
                    }
                }
                /*if(uuu%2 != 0){
                            g.setColor(Color.WHITE); 
                            System.out.println("white");
                        }
                else
                    g.setColor(Color.RED);*/
               g.drawRect(aaa,bbb,xxx,xxx);  
               bbb-=5;
               g.drawRect(ccc,ddd,xxx,xxx);  
               ccc-=10;
               ddd-=5;
               g.drawRect(qqq,fff,xxx,xxx);  
               qqq-=5;
               fff-=10;
               g.drawRect(jjj,hhh,xxx,xxx);  
               jjj-=5;
               g.drawRect(kkk,lll,xxx,xxx);  
               g.drawRect(mmm,lll,xxx,xxx);
               mmm-=10;
               g.drawRect(kkk,nnn,xxx,xxx);
               nnn-=10;
               g.drawRect(ooo,ppp,xxx,xxx);
               ppp-=10;
               ooo-=10;
               xxx+=10;
               
               
               if(uuu%2 != 0){
                     g.setColor(Color.BLACK);
                    //Circles
                    g.drawOval(cx,cy,d1,d2);//center
                    g.drawOval(ax,cy,d1,d2);//left
                    g.drawOval(bx,cy,d1,d2);//right
                    g.drawOval(cx,ay,d1,d2);//top
                    g.drawOval(cx,by,d1,d2);//bottom
                    g.drawOval(ax,ay,d1,d2);//northwest
                    g.drawOval(bx,ay,d1,d2);//northeast
                    g.drawOval(ax,by,d1,d2);//southwest
                    g.drawOval(bx,by,d1,d2);//southeast
                    g.drawOval(bx,by,d1,d2);
                }
               
                try{
                        Thread.sleep(50);
                }
                catch(InterruptedException e){}
            }
            uuu++;
        }
        int cx = 657, cy = 382, d1 = 10, d2 = 10;
        int ax = cx/4 + cx/2, bx = cx/4 + cx;
        int ay = cy/2 + cy/16 , by = (cy/2-cy/16) + cy;
        
        for(int i = 0; i<=70 ; i++,cx-=10,cy-=10,d1+=20,d2+=20){
            g.setColor(Color.BLACK);
            g.fillOval(cx,cy,d1,d2);   
        }
    }
    public void redo(int redo){
        while(redo!=0){
            repaint();
        }
    }
    public static void main(String[]args){
        int re = 25;
        String junk;
        GeometricShapes gs = new GeometricShapes(); 
        gs.redo(re);
    }
}