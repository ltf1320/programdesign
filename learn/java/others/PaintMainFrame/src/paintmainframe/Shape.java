/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package paintmainframe;

/**
 *
 * @author Chaos
 */
import java.awt.Graphics;

public interface Shape {
    public void draw(Graphics g);
    public void add(Shape s);
//    public void move(MouseEvent e);
}
