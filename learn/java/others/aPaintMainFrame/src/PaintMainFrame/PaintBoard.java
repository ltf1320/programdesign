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
import java.awt.Canvas;
import java.awt.Dimension;
import java.awt.event.MouseEvent;
import java.awt.Point;
import java.util.*;


public class PaintBoard extends Canvas implements java.awt.event.MouseListener, java.awt.event.MouseMotionListener {
    int beginX = 0;
    int beginY = 0;
    int currentX = 0;
    int currentY = 0;
    
    boolean bMousePressing = false;
    
    Stack vShapes = new Stack();
    
    private int command = 0;
    private Color color;
    
    private int colorCommand;
    
    Stack compositeShapes = new Stack();
    
    ArrayList<ImageArea> pointSet = new ArrayList<ImageArea>();
    ArrayList<ImageArea> selectedArea = new ArrayList<ImageArea>();
    
    public PaintBoard() {
        this.addMouseListener(this);
        this.addMouseMotionListener(this);
    }
    
    public int getCommand() {
        return command;
    }
    
    public void setColorCommand(int colorCommand) {
        this.colorCommand = colorCommand;
    }
    
    public void setCommand(int command) {
        this.command = command;
    }
    
    public void setColor(Color color) {
        this.color = color;
    }
    
    public void update(Graphics g) {
        paint(g);
        
    }
    
    public void paint(Graphics g) {
        Dimension size = getSize();
        int width = size.width;
        int height = size.height;
        g.setColor(Color.white);
        g.fillRect(0, 0, width, height);
        
        Shape shape = null;
        
        Enumeration shapes = vShapes.elements();
        while (shapes.hasMoreElements()) {
            shape = (Shape) shapes.nextElement();
            shape.draw(g);
        }
        
        if (bMousePressing) {
            g.setColor(color);
            switch (command) {
                case Command.LINE:
                    g.drawLine(beginX, beginY, currentX, currentY);
                    break;
                case Command.RECTANGLE:
                    if (currentX < beginX) {
                        if (currentY < beginY) {
                            g.fillRect(currentX, currentY, beginX - currentX, beginY - currentY);
                        } else {
                            g.fillRect(currentX, beginY, beginX - currentX, currentY - beginY);
                        } 
                    } else {
                        if (currentY < beginY) {
                            g.fillRect(beginX, currentY, currentX - beginX, beginX - currentY);
                        } else {
                            g.fillRect(beginX, beginY, currentX - beginX, currentY - beginY);
                        }
                    }
                    
                    break;
                case Command.CIRCLE:
                    int radius = (int) java.lang.Math.sqrt((beginX - currentX) * (beginX - currentY) + (beginY - currentY) * (beginY - currentY));
                    g.fillArc(beginX - radius / 2, beginY - radius / 2, radius, radius, 0, 360);
                    break;
            }
        }
        if (colorCommand == 100||colorCommand == 200) {
            System.out.println("GREEN");
            Iterator it = selectedArea.iterator();
            while (it.hasNext()) {
                ImageArea sa = (ImageArea) it.next();
                switch (sa.command) {
                    case Command.LINE:
                        g.drawLine(sa.startPoint.x, sa.startPoint.y, sa.endPoint.x, sa.endPoint.y);
                        break;
                    case Command.RECTANGLE:
                        g.fillRect(sa.startPoint.x, sa.startPoint.y, sa.width, sa.height);
                        break;
                    case Command.CIRCLE:
                        break;
                }
                
            }
        }
    }

    public void mouseClicked(MouseEvent e) {
    }
    public void mousePressed(MouseEvent e) {
        if (command == 0) {
            Iterator it = pointSet.iterator();
            while (it.hasNext()) {
                ImageArea ia = (ImageArea) it.next();
                switch (ia.command) {
                    case Command.LINE:
                        if ( Math.abs((Math.sqrt((e.getX()-ia.startPoint.x)*(e.getX()-ia.startPoint.x)+(e.getY()-ia.startPoint.y)*(e.getY()-ia.startPoint.y))+
                            Math.sqrt((ia.endPoint.x-e.getX())*(ia.endPoint.x-e.getX())+(ia.endPoint.y-e.getY())*(e.getY()-ia.endPoint.y))) -
                                    Math.sqrt((ia.endPoint.x-ia.startPoint.x)*(ia.endPoint.x-ia.startPoint.x)+(ia.endPoint.y-ia.startPoint.y)*(ia.endPoint.y-ia.startPoint.y))) < 5)
                        {
                            System.out.println("LINE");
                            selectedArea.add(ia);
                        }
                        
                     
                        break;
                    case Command.RECTANGLE:
                        if (((e.getX()<ia.startPoint.x+ia.width)&&(e.getX()>ia.startPoint.x)) &&
                                    ((e.getY()<ia.startPoint.y+ia.height)&&(e.getY()>ia.startPoint.y)))
                        {
                            System.out.println("RECTANGLE");
                            selectedArea.add(ia);
                        }
                        break;
                    case Command.CIRCLE:

                        break;
                }
            }
            
        }
        beginX = e.getX();
        beginY = e.getY();
        bMousePressing = true;
        if (command == 0) {
            repaint();
        }      
    }

    public void mouseReleased(MouseEvent e) {
        currentX = e.getX();
        currentY = e.getY();
        bMousePressing = false;

        switch (command) {
            case Command.LINE:
                Line line = new Line(beginX, beginY, currentX, currentY, color);
                vShapes.add(line);
                ImageArea lineArea = new ImageArea();
                lineArea.command = command;
                lineArea.startPoint = new Point(beginX, beginY);
                lineArea.endPoint = new Point(currentX, currentY);
                pointSet.add(lineArea);
                break;
            case Command.RECTANGLE:
                Rectangle rectangle = null;
                if (currentX < beginX) {
                    if (currentY < beginY) {
                        rectangle = new Rectangle(currentX, currentY, beginX - currentX, beginY - currentY, color);   
                    } else {
                        rectangle = new Rectangle(currentX, beginY, beginX - currentX, currentY - beginY, color);
                    } 
                } else {
                    if (currentY < beginY) {
                        rectangle = new Rectangle(beginX, currentY, currentX - beginX, beginY - currentY, color);
                    } else {
                        rectangle = new Rectangle(beginX, beginY, currentX - beginX, currentY - beginY, color);
                    }
                }
                vShapes.add(rectangle);
                ImageArea rectangleArea = new ImageArea();
                rectangleArea.command = command;
                rectangleArea.startPoint = new Point(beginX, beginY);
                rectangleArea.width = Math.abs(beginX - currentX);
                rectangleArea.height = Math.abs(currentY - beginY);
                pointSet.add(rectangleArea);
                break;
            case Command.CIRCLE:
                int radius = (int) java.lang.Math.sqrt((beginX - currentX) * (beginX - currentY) + (beginY - currentY) * (beginY - currentY));
                Circle circle = new Circle(beginX - radius / 2, beginY - radius / 2, radius, color);
                vShapes.add(circle);
                ImageArea circleArea = new ImageArea();
                circleArea.startPoint = new Point(beginX, beginY);
                circleArea.radius = radius;
                pointSet.add(circleArea);
                break;
        }
    }

    public void mouseEntered(MouseEvent e) {

    }

    public void mouseExited(MouseEvent e) {

    }

    public void mouseDragged(MouseEvent e) {
        currentX = e.getX();
        currentY = e.getY();
        repaint();
    }

    public void mouseMoved(MouseEvent e) {

    }
}

class ImageArea {
    int command;
    public Point startPoint;
    public Point endPoint;
    public int width;
    public int height;
    public int radius;
}


