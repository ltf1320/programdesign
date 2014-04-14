package dr;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Point;
import java.awt.Shape;


import java.util.ArrayList;

public class mComposite implements shap {
	private static final long serialVersionUID = 1L;
	private ConcreteAggregate ca;
	private ConcreteIterator i;
	private int ii;
	protected mComposite(double d, double e, double f, double g, drawbord drawbord){
		super();
		ca=new ConcreteAggregate();
		i=(ConcreteIterator) ca.CreateIterator();

	}
	public void move(shap p){
		String name=new String("com.jkzqw.painter.shaprec");
		String name1=new String("com.jkzqw.painter.shapeline");
		String name3=new String("com.jkzqw.painter.shapoval");
		String name4=new String("com.jkzqw.painter.mComposite");

		i.initcurrent(0);
		ii=0;
		while(!i.IsDone()){
			
			Shape shape=(Shape) i.CurrentItem();
			if(shape.getClass().getName().equals(name)) {
				 shaprec rec=(shaprec)shape;
				 
			}
			if(shape.getClass().getName().equals(name1)){
			    shapeline line=(shapeline)shape;	
			   
			}
			
			if(shape.getClass().getName().equals(name3)){
				shapoval circle=(shapoval)shape;
				
			}
			if(shape.getClass().getName().equals(name4)){
				mComposite com=(mComposite)shape;
				com.move(p);
			}
			
			setbound();
			i.initcurrent(ii++);
			i.Next();
		}
	}
	public void draw(Graphics   g1){
		String name=new String("com.jkzqw.painter.shaprec");
		String name1=new String("com.jkzqw.painter.shapeline");
		String name3=new String("com.jkzqw.painter.shapoval");
		String name4=new String("com.jkzqw.painter.mComposite");

		i.initcurrent(0);
		while(!i.IsDone()){
			Shape shape=(Shape) i.CurrentItem();
			if(shape.getClass().getName().equals(name)) {
				 shaprec rec=(shaprec)shape;
				 rec.draw(g1);
			}
			if(shape.getClass().getName().equals(name1)){
			    shapeline line=(shapeline)shape;	
			    line.draw(g1);
			}
			
			if(shape.getClass().getName().equals(name3)){
				shapoval circle=(shapoval)shape;
				circle.draw(g1);
			}
			if(shape.getClass().getName().equals(name4)){
				mComposite com=(mComposite)shape;
				com.draw(g1);
			}
			i.Next();
		}
		
		
	}
	public void setbound(){
		double minx=1960,miny=1080;
		double maxx=0,maxy=0;
		double x=0,y=0;
		double xx = 0,yy=0;

		i.initcurrent(0);
		while(!i.IsDone()){
			Shape shape=(Shape) i.CurrentItem();
			if(shape.getClass().getName().equals("com.jkzqw.painter.mLine"))
			{
				x=((Shape)shape).getBounds2D().getX();
				y=((Shape)shape).getBounds2D().getY();
				xx=x+((Shape)shape).getBounds2D().getWidth();
				yy=y+((Shape)shape).getBounds2D().getHeight();
			}
			if(shape.getClass().getName().equals("com.jkzqw.painter.mRectangle")){
				
				x=((shaprec)shape).getX();
				y=((shaprec)shape).getY();
				xx=x+((shaprec)shape).getWidth();
				yy=y+((shaprec)shape).getHeight();
			}
			
			if(shape.getClass().getName().equals("com.jkzqw.painter.mCircle")){
				
				x=((shapoval)shape).getX();
				y=((shapoval)shape).getY();
				xx=x+((shapoval)shape).getWidth();
				yy=y+((shapoval)shape).getHeight();
				
			}
			if(shape.getClass().getName().equals("com.jkzqw.painter.mComposite")){
				x=((mComposite)shape).getX();
				y=((mComposite)shape).getY();
				xx=x+((mComposite)shape).getWidth();
				yy=y+((mComposite)shape).getHeight();
			}
			if(x<minx)
				minx=x;
			if(y<miny)
				miny=y;
			if(xx>maxx)
				maxx=xx;
			if(yy>maxy)
				maxy=yy;
			i.Next();
		}
	}
	private double getHeight() {
		// TODO Auto-generated method stub
		return 0;
	}
	private double getWidth() {
		// TODO Auto-generated method stub
		return 0;
	}
	private double getY() {
		// TODO Auto-generated method stub
		return 0;
	}
	private double getX() {
		// TODO Auto-generated method stub
		return 0;
	}
	public void addshape(ArrayList <Shape> shape){//composite
		for(Shape s:shape){
     		i.setCurrentItem(s);
			
			
		}
	}
	public void setA(Point p) {
		String name=new String("com.jkzqw.painter.shaprec");
		String name1=new String("com.jkzqw.painter.shapline");
		@SuppressWarnings("unused")
		String name3=new String("com.jkzqw.painter.shapoval");
		@SuppressWarnings("unused")
		String name4=new String("com.jkzqw.painter.mComposite");

		i.initcurrent(0);
		while(!i.IsDone()){
			Shape shape=(Shape) i.CurrentItem();
			if(shape.getClass().getName().equals(name)) {
				 shaprec rec=(shaprec)shape;
				 rec.setPe(p);
				 
			}
			if(shape.getClass().getName().equals(name1)){
			   shapeline line=(shapeline)shape;	
			    line.setPe(p);
			}
			
			}
			
			i.Next();
		}

	public void setB(Point p) {
		String name=new String("com.jkzqw.painter.shaprec");
		String name1=new String("com.jkzqw.painter.shapeline");
		@SuppressWarnings("unused")
		String name3=new String("com.jkzqw.painter.shapoval");
		@SuppressWarnings("unused")
		String name4=new String("com.jkzqw.painter.mComposite");
		
		i.initcurrent(0);
		while(!i.IsDone()){
			Shape shape=(Shape) i.CurrentItem();
			if(shape.getClass().getName().equals(name)) {
				shaprec rec=(shaprec)shape;
				 rec.setPe(p);
			}
			if(shape.getClass().getName().equals(name1)){
			    shapeline line=(shapeline)shape;	
			    line.setPe(p);
			}
			
			}
			i.Next();
			
		}
		
	
	public void removeshape(){//unpack
		i.initcurrent(0);
		while(!i.IsDone()){
			Shape s=(Shape) i.CurrentItem();
			
			s=null;
			i.Next();
		}
		

		i.clearaggregate();
		
	}
	
	
	
	@Override
	public void getmou(Point sb, Point se) {
		// TODO Auto-generated method stub
		
	}
	@Override
	public void getshapecolor(Color c) {
		// TODO Auto-generated method stub
		
	}
	
	
	@Override
	public boolean isseclect(int m) {
		// TODO Auto-generated method stub
		return false;
	}
	@Override
	public void setPe(Point pe) {
		// TODO Auto-generated method stub
		
	}
	@Override
	public void xzmove(int m, int n) {
		// TODO Auto-generated method stub
		
	}
	@Override
	public void baocunp(int x, Point b, Point e, int m, int n) {
		// TODO Auto-generated method stub
		
	}
	@Override
	public boolean ischangcolor(int n) {
		// TODO Auto-generated method stub
		return false;
	}
	
}



