/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Main;

import java.awt.*;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener; 
import javax.swing.JFrame; 

public class mainFrame extends JFrame implements KeyListener, MouseListener{
    private static final long serialVersionUID = 1L; 
    private mainDraw draw;
    
    public void keyPressed(KeyEvent e) {
            System.out.println("keyPressed");
    }
    public void keyReleased(KeyEvent e) {
            if(e.getKeyCode()== KeyEvent.VK_DOWN)
                draw.moveDown();
            else if(e.getKeyCode()== KeyEvent.VK_UP)
                draw.moveUp();
    }
    public void keyTyped(KeyEvent e) {
            System.out.println("keyTyped");
    }
    public void mouseClicked(MouseEvent e) { 
        int x = e.getX(); 
        int y = e.getY(); 
        //System.out.println("Mouse Clicked at X: " + x + " - Y: " + y); 
    } 
    @Override 

    public void mouseEntered(MouseEvent e) { 
        int x = e.getX();  
        int y = e.getY(); 
        //System.out.println("Mouse Entered frame at X: " + x + " - Y: " + y); 
    } 
    @Override 

    public void mouseExited(MouseEvent e) { 
        int x = e.getX(); 
        int y = e.getY(); 
        //System.out.println("Mouse Exited frame at X: " + x + " - Y: " + y); 
    } 
    @Override 

    public void mousePressed(MouseEvent e) { 
        int x = e.getX(); 
        int y = e.getY();
        draw.moveMouse(x, y);
        System.out.println("Mouse Pressed at X: " + x + " - Y: " + y); 
    }  
    @Override 

    public void mouseReleased(MouseEvent e) { 
        int x = e.getX();  
        int y = e.getY();  
        //System.out.println("Mouse Released at X: " + x + " - Y: " + y); 
    }

    public mainFrame(){
            this.draw=new mainDraw();
            addMouseListener(this); 
            addKeyListener(this);
            setFocusable(true);
            setFocusTraversalKeysEnabled(false);
            setVisible(true); 
            setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); 
    }
    
    public static void main(String[] args) {
            javax.swing.SwingUtilities.invokeLater(new Runnable() {
                public void run() {
                    mainFrame frame = new mainFrame();
                    frame.setTitle("Square Move Practice");
                    frame.setResizable(false);
                    frame.setSize(1300,750);
                    frame.setMinimumSize(new Dimension(1300, 750));
                    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                    frame.getContentPane().add(frame.draw);
                    frame.pack();
                    frame.setVisible(true);
                }
            });
    }
}
