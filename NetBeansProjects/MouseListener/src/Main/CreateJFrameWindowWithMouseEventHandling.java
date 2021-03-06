/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Main;

/**
 *
 * @author Asus-PC
 */


import java.awt.event.MouseEvent; 
import java.awt.event.MouseListener; 
import javax.swing.JFrame; 


public class CreateJFrameWindowWithMouseEventHandling extends JFrame implements MouseListener { 

    private static final long serialVersionUID = 1L; 

    public CreateJFrameWindowWithMouseEventHandling() { 
        setTitle("Simple Frame"); 
        addMouseListener(this); 
    } 
    @Override 

    public void mouseClicked(MouseEvent e) { 
        int x = e.getX(); 
        int y = e.getY(); 
        System.out.println("Mouse Clicked at X: " + x + " - Y: " + y); 
    } 
    @Override 

    public void mouseEntered(MouseEvent e) { 
        int x = e.getX();  
        int y = e.getY(); 
        System.out.println("Mouse Entered frame at X: " + x + " - Y: " + y); 
    } 
    @Override 

    public void mouseExited(MouseEvent e) { 
        int x = e.getX(); 
        int y = e.getY(); 
        System.out.println("Mouse Exited frame at X: " + x + " - Y: " + y); 
    } 
    @Override 

    public void mousePressed(MouseEvent e) { 
        int x = e.getX(); 
        int y = e.getY(); 
        System.out.println("Mouse Pressed at X: " + x + " - Y: " + y); 
    }  
    @Override 

    public void mouseReleased(MouseEvent e) { 
        int x = e.getX();  
        int y = e.getY();  
        System.out.println("Mouse Released at X: " + x + " - Y: " + y); 
    } 

    private static void createAndShowGUI() { 
        JFrame frame = new CreateJFrameWindowWithMouseEventHandling(); 
        frame.setVisible(true); 
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); 
    }  

    public static void main(String[] args) { 

        javax.swing.SwingUtilities.invokeLater(new Runnable() { 

        public void run() { 
            createAndShowGUI();  
        } 

        }); 
    } 
} 
