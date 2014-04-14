package d;
import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Point;
import java.awt.Stroke;
import java.io.Serializable;
public class shapoval implements shap,Serializable{
	Point pb=new Point();
	Point pe=new Point();
	Point mpb=new Point();
	Point mpe=new Point();
	Point b=new Point();
	Point e=new Point();
	boolean sec=false;
	boolean col=false;
	Color c=Color.BLACK;
    public shapoval(Point pb,Point pe){
    	this.pb=pb;
    	this.pe=pe;
    }
	public void draw(Graphics g) {	
		if(sec&&!col)
		{
			Stroke st = new BasicStroke(3.0f);
			Graphics2D g2d = (Graphics2D)g;
			Stroke temp = g2d.getStroke();
			g2d.setStroke(st);
		    g2d.setColor(Color.BLACK);
			g2d.drawOval(pb.x,pb.y, pe.x-pb.x, pe.y-pb.y);
			g2d.setStroke(temp);
		}
		else{
			  g.setColor(c);
			  g.fillOval(pb.x, pb.y,pe.x-pb.x, pe.y-pb.y);
			  g.drawOval(pb.x,pb.y, pe.x-pb.x, pe.y-pb.y);
		  	}
	}
	public void getshapecolor(Color c) {		
		this.c=c;
	}
	public void setPe(Point pe) {
		this.pe=pe;
	}
	public void getmou(Point sb, Point se) {
		this.mpb=sb;
		this.mpe=se;
	}
	public boolean isseclect(int m) {
		if(m==0)
		{
		    if(pb.x>mpb.x&&pb.y>mpb.y&&pe.x<mpe.x&&pe.y<mpe.y)
			sec=true;
		}
		if(m==1)
		{
			sec=false;
		}
		   return sec;
	}
	public void xzmove(int m, int n) {
		this.pb.x=this.b.x+m;
		this.pb.y=this.b.y+n;
		this.pe.x=this.e.x+m;
		this.pe.y=this.e.y+n;
		
	}
	public void baocunp(int x,Point b, Point e,int m,int n) {
		if(x==0)
		{
			this.b=b;
			this.e=e;
		}
		if(x==1)
		{
			this.b.x+=m;
			this.b.y+=n;
			this.e.x+=m;
			this.e.y+=n;
		}
	}
	public boolean ischangcolor(int n) {
		if(n==0)
      	  col=true;
       if(n==1)
    	   col=false;
        return col;
	}
}
