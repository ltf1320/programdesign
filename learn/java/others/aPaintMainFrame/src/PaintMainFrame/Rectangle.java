/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package PaintMainFrame;

/**
 *
 * @author Chaos
 */
import java.awt.Color;
import java.awt.Graphics;

public class Rectangle implements Shape {
    private int x;
    private int y;
    private int width;
    private int height;
    private Color color;
    
    public Rectangle (int x, int y, int width, int height, Color color) {
        this.x = x;
        this.y = y;
        this.width = width;
        this.height = height;
        this.color = color;
    }
    
    public void draw(Graphics g) {
        g.setColor(color);
        g.fillRect(x, y, width, height);
    }
    public void add(Shape s){
        
    }
    
//    public void move(MouseEvent e) {
//        
//    }
}
