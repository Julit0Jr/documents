/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package otherkeypress;

import java.awt.Color;
import java.awt.Graphics;
import javax.swing.JComponent;
/**
 *
 * @author Asus-PC
 */
class mainDraw extends JComponent{

public int x = 50;
public int y = 50;

public void paint(Graphics g){

    g.drawRect(x, y, 50, 50);
    g.fillRect(x, y, 50, 50);
    g.setColor(Color.BLACK);
}

public void moveRight()
{
    x = x + 5;
    y = y + 0;
    repaint();
}

}
