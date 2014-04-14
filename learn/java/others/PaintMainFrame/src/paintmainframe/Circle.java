/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package paintmainframe;

/**
 *
 * @author Chaos
 */
import java.awt.Color;
import java.awt.Graphics;

public class Circle implements Shape {
    private Color color;
    private int x;
    private int y;
    private int radius;
    
    public Circle (int x, int y, int radius, Color color) {
        this.x = x;
        this.y = y;
        this.radius = radius;
        this.color = color;
    }
    public void draw(Graphics g) {
        g.setColor(color);
        g.fillArc(x, y, radius, radius, 0, 360);
    }
    public void add(Shape s){
        
    }
    
//    public void move(MouseEvent e) {
//        
//    }
}
