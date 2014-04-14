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

public class Line implements Shape {
    public int x1;
    public int y1;
    
    public int x2;
    public int y2;
    private Color color;
    
    public Line (int x1, int y1, int x2, int y2, Color color) {
        this.x1 = x1;
        this.x2 = x2;
        this.y1 = y1;
        this.y2 = y2;
        this.color = color;
    }
    public void draw(Graphics g) {
        g.setColor(color);
        g.drawLine(x1, y1, x2, y2);
    }
    public void add(Shape s){
        
    }
    
//    public void move(MouseEvent e) {
//        if ((Math.sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))) == (Math.sqrt((e.getX()-x1)*(e.getX()-x1)+(e.getY()-y1)*(e.getY()-y1))+Math.sqrt((e.getX()-x2)*(e.getX()-x2)+(e.getY()-y2)*(e.getY()-y2)))) {
//            System.out.println("Chosen");
//        }
//    }
}
