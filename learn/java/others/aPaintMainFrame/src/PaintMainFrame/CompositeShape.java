/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package PaintMainFrame;

/**
 *
 * @author Chaos
 */
import java.awt.Graphics;
import java.awt.Color;
import java.util.*;
import java.awt.event.MouseEvent;

public class CompositeShape implements Shape { 
    private ArrayList<Shape> shapeList = new ArrayList<Shape>();
    private int x1;
    private int x2;
    private int y1;
    private int y2;
    private Color color;
    
    public CompositeShape (int x1, int y1, int x2, int y2, Color color) {
        this.x1 = x1;
        this.x2 = x2;
        this.y1 = y1;
        this.y2 = y2;
        this.color = color;
    }
    
    private int x;
    private int y;
    private int width;
    private int height;
    
    
    private int radius;
    public CompositeShape (int x, int y, int radius, Color color) {
        this.x = x;
        this.y = y;
        this.radius = radius;
        this.color = color;
    }
    
    public void add(Shape shape) {
        this.shapeList.add(shape);
    }
    
    public void remove(Shape shape) {
        this.shapeList.remove(shape);
    }
    
    public ArrayList<Shape> getChild() {
        return this.shapeList;
    }
    
    public void draw(Graphics g) {
        g.setColor(color);
        g.drawLine(x1, y1, x2, y2);
    }
    public void move(MouseEvent e) {
        
    }
}
