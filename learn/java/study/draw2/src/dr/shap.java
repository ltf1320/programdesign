package dr;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Point;
import java.io.Serializable;

public interface shap extends Serializable{
    public void draw(Graphics g); 
    public void getshapecolor(Color c);
    public void setPe(Point pe);
    public void getmou(Point sb,Point se);
    public void xzmove(int m,int n);
    public boolean isseclect(int m);
    public void baocunp(int x,Point b,Point e,int m,int n);
    public  boolean ischangcolor(int n);}