/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package otherkeypress;

import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import javax.swing.JFrame;
/**
 *
 * @author Asus-PC
 */
public class mainFrame extends JFrame implements KeyListener{

mainDraw Draw = new mainDraw();

public void keyPressed(KeyEvent e) {

    int key = e.getKeyCode();

    if(key == KeyEvent.VK_D){

        Draw.moveRight();
    }
}

public void keyReleased(KeyEvent e) {


}
public void keyTyped(KeyEvent e) {}

public mainFrame()
{
    addKeyListener(this);
    setFocusable(true);
    setFocusTraversalKeysEnabled(false);
}

public static void main(String[] args) {

    mainFrame M1 = new mainFrame();

    mainDraw Draw = new mainDraw();

    JFrame frame = new JFrame("Square Move Practice");


    //frame
    frame.setVisible(true);
    frame.setResizable(false);
    frame.setSize(600, 600);
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    frame.getContentPane().add(Draw);

}
}