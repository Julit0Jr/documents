mainFrame.java
import java.awt.*;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import javax.swing.JFrame;

public class mainFrame extends JFrame implements KeyListener{
    private mainDraw draw;
public void keyPressed(KeyEvent e) {
        System.out.println("keyPressed");
    }
public void keyReleased(KeyEvent e) {
        if(e.getKeyCode()== KeyEvent.VK_RIGHT)
            draw.moveRight();
        else if(e.getKeyCode()== KeyEvent.VK_LEFT)
            draw.moveLeft();
        else if(e.getKeyCode()== KeyEvent.VK_DOWN)
            draw.moveDown();
        else if(e.getKeyCode()== KeyEvent.VK_UP)
            draw.moveUp();
}
    public void keyTyped(KeyEvent e) {
        System.out.println("keyTyped");
    }
public mainFrame(){
        this.draw=new mainDraw();
        addKeyListener(this);
        setFocusable(true);
        setFocusTraversalKeysEnabled(false);
    }
public static void main(String[] args) {
        javax.swing.SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                mainFrame frame = new mainFrame();
                frame.setTitle("Square Move Practice");
                frame.setResizable(false);
                frame.setSize(600, 600);
                frame.setMinimumSize(new Dimension(600, 600));
                frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                frame.getContentPane().add(frame.draw);
                frame.pack();
                frame.setVisible(true);
            }
        });
    }
}
mainDraw.java
import java.awt.Color;
import java.awt.Graphics;
import javax.swing.JComponent;
public class mainDraw extends JComponent {
public int x = 50;
    public int y = 50;
public void paintComponent(Graphics g) {
        super.paintComponent(g);
        g.drawRect(x, y, 50, 50);
        g.fillRect(x, y, 50, 50);
        g.setColor(Color.BLACK);
    }
public void moveRight() {
        x = x + 5;
        repaint();
    }
public void moveLeft() {
        x = x - 5;
        repaint();
    }
public void moveDown() {
        y = y + 5;
        repaint();
    }
public void moveUp() {
        y = y - 5;
        repaint();
    }

