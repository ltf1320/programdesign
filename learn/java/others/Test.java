import javax.swing.*;
import java.awt.event.*;
import java.awt.*;
import java.io.*;
import java.util.*;
import java.awt.Graphics;
import java.io.Serializable;
import java.awt.BasicStroke;
import java.awt.Graphics2D;
import java.math.*;

class Point{
	int x,y;
	public Point(int a,int b){x=a;y=b;}
	}

interface shap extends Serializable{
    public void draw(Graphics g); 
    public void move1(Point m,Point n);
    public void change1(Point m,Point n);
    public void change2(int a,int b);
    public int cat(Point a);
    public int getp1x();
    public int getp1y();
    public int getp2x();
    public int getp2y();
    public int getpart();
    public void change1part();
    public void change0part(); 
    public int kioli();
}

class aFrame extends JFrame implements ActionListener,MouseMotionListener,MouseListener,Serializable{
	Factory factory=new Factory();
	Iterator iterator=factory.CreateIterator(); 
	Panel p=factory.CreatePanel();
	Point q,w,e,r1,r2;
	int find=0;
	int toolflag=0;
	int x,y;
	shap I,O;
	int iteratorsize;
	
	Button BR;
	Button BL;
	Button BS;
	Button M;
	Button C;
	Button Z;
	Button F;
	Button D;
	
	public aFrame(){
	
		    BR=factory.CreateButton("ellipse");//1
	    BL=factory.CreateButton("line");//2
	    BS=factory.CreateButton("rectangle");//3
	    M=factory.CreateButton("move");//4
	    C=factory.CreateButton("change size");//5
	    Z=factory.CreateButton("combination");//6
	    F=factory.CreateButton("seperate");//7
        D=factory.CreateButton("clear");//8
        p.add(BR);
	    p.add(BL);
	    p.add(BS);
	    p.add(M);
	    p.add(C);
	    p.add(Z);
	    p.add(F);
	    p.add(D);
	    
	    
	    this.add(p,BorderLayout.NORTH);
	    BR.addActionListener(this);
	    BL.addActionListener(this);
	    BS.addActionListener(this);
	    M.addActionListener(this);
	    C.addActionListener(this);
	    Z.addActionListener(this);
	    F.addActionListener(this);
	    D.addActionListener(this);
	       
	    addMouseListener(this);
	    addMouseMotionListener(this);
	    this.addWindowListener(new WindowAdapter(){
	    	public void windowClosing(WindowEvent e)
	    	{ System.exit(0);}
	    	  });
	    	  
	    	  this.setSize(1000,700);
	    	  this.setVisible(true);
	     }
	     
	public void actionPerformed(ActionEvent e){
	       if(e.getSource()==BR)
              {toolflag = 1;find=0;System.out.println(toolflag);} 
           if(e.getSource()==BL) 
              {toolflag = 2;find=0;System.out.println(toolflag);} 
           if(e.getSource()==BS) 
              {toolflag = 3;find=0;System.out.println(toolflag);}
           if(e.getSource()==M)
              {toolflag=4;System.out.println(toolflag);}
           if(e.getSource()==C)
              {toolflag=5;System.out.println(toolflag);}
           if(e.getSource()==Z)
              {toolflag=6;find=1;System.out.println(toolflag);}
           if(e.getSource()==F)
              {toolflag=7;find=0;
              for(int i=0;i<iterator.getsize();i++){
			      O=iterator.elementAt(i);
		       	  O.change0part();
		       	  }System.out.println(toolflag);} 
           if(e.getSource()==D)
              {toolflag=8;find=0;iterator.removeAllElements();repaint();System.out.println(toolflag);} 
             }
             
	public void mousePressed(MouseEvent e){
		x=(int)e.getX();
        y=(int)e.getY();
        q=factory.CreatePoint(x,y);
		}
	public void mouseReleased(MouseEvent e){
		x=(int)e.getX();
        y=(int)e.getY();
        w=factory.CreatePoint(x,y);
        
        int i;int j;
		switch(toolflag){
		case 1:I=factory.CreateRound(q,w);System.out.println(q.x+q.y+w.x+w.y);
		       iterator.addElement(I);repaint();
		       break;
		case 2:I=factory.CreateLine(q,w);System.out.println(q.x+q.y+w.x+w.y);
		       iterator.addElement(I);repaint();
		       break;
		case 3:I=factory.CreateSquare(q,w);System.out.println(q.x+q.y+w.x+w.y);
		       iterator.addElement(I);repaint();
		       break;
		case 4:
		       if(find==0){iteratorsize=iterator.getsize();
		                   for(i=0;i<iteratorsize;i++){
			                         j=iterator.get(i).cat(q);
			                         if(j==1) break;    
			                         }//end for
			                O=iterator.elementAt(i);
			                O.move1(q,w);
			              }//end if
		       else{iteratorsize=iterator.getsize();
		       	    for(i=0;i<iteratorsize;i++){
		       	    	O=iterator.elementAt(i);
		       	    	if(O.getpart()==1){
			                     O.move1(q,w);
		       	    		     }    	    	
		       	    	}//end for
		       	}
		       repaint();
		       break;
		case 5:iteratorsize=iterator.getsize();
		       if(find==0){
		                   for(i=0;i<iteratorsize;i++){
			                         j=iterator.get(i).cat(q);
			                         if(j==1) break;    
			                         }//end for
			                O=iterator.elementAt(i);
			                O.change1(q,w);
			              }//end if
		       else{int chax,chay,k;
		  
		            for(i=0;i<iteratorsize;i++){
		            	O=iterator.elementAt(i);
		            	if(O.getpart()==1) break;
		            	}
		            
		       	    for(i=0;i<iteratorsize;i++){
		       	    	I=iterator.elementAt(i);k=I.kioli();
		       	    	if(I.getpart()==1){
		       	    		if(O.kioli()>k) O=I;	
		       	    		}
		       	    	}
		       	    chax=(w.x-q.x)-(O.getp2x()-O.getp1x());
                    chay=(w.y-q.y)-(O.getp2y()-O.getp1y());
		       	    for(i=0;i<iteratorsize;i++){
		       	    	O=iterator.elementAt(i);
		       	    	if(O.getpart()==1){
			                O.change2(chax,chay);
			                
		       	    		}    	    	
		       	    	}//end for
		       	   }
		       repaint();
		       break;
		case 6:iteratorsize=iterator.getsize();
		       for(i=0;i<iteratorsize;i++){
			         j=iterator.get(i).cat(q);
			         if(j==1) break;    
			         }//end for
			   O=iterator.elementAt(i);
			   O.change1part();
		       break;
		default: 
		}//end switch
	}
	public void update(Graphics g) { 
                    paint(g); 
                    } 
	public void paint(Graphics g){
		Graphics2D g2d = (Graphics2D)g;
		g2d.clearRect(0,0,getSize().width,getSize().height);
		iteratorsize=iterator.getsize();
        for(int i=0;i<iteratorsize;i++){
        	           g2d.setColor(Color.black);
      		           iterator.get(i).draw(g);}
      		       
	}
	public void mouseDragged(MouseEvent e){}
	public void mouseMoved(MouseEvent e){}
	public void mouseEntered(MouseEvent e){}
	public void mouseExited(MouseEvent e){}
	public void mouseClicked(MouseEvent e){}
	}
	
    class Line implements shap,Serializable{
    	public Point p1,p2;public int type=2;int part=0;int chax,chay;
    	public Line(Point a,Point b){
    		this.p1=a;
    		this.p2=b;
    		}
        public void draw(Graphics g){	
			Graphics2D g2d = (Graphics2D)g;
			g2d.setColor(Color.BLACK);
			g2d.drawLine(p1.x, p1.y, p2.x, p2.y);
		}
		public int cat(Point a){
			                 if(Math.abs(a.x-p1.x)<=20&&Math.abs(a.y-p1.y)<=20) return 1;
			                 else return 0;
			                 }
        public void move1(Point m,Point n){
                                           this.p1.x=this.p1.x+n.x-m.x; 
                                           this.p2.x=this.p2.x+n.x-m.x;
                                           this.p1.y=this.p1.y+n.y-m.y;
                                           this.p2.y=this.p2.y+n.y-m.y;
                                          }
        public void change1(Point m,Point n){
                                             this.chax=(n.x-m.x)-(this.p2.x-this.p1.x);
                                             this.chay=(n.y-m.y)-(this.p2.y-this.p1.y);
                                             this.p2.x=this.p2.x+this.chax;
                                             this.p2.y=this.p2.y+this.chay;}
        public void change2(int a,int b){
        	                             this.p2.x=this.p2.x+a;
                                         this.p2.y=this.p2.y+b;}
        public int getp1x(){return p1.x;}
        public int getp1y(){return p1.y;}
        public int getp2x(){return p2.x;}
        public int getp2y(){return p2.y;}
        public int getpart(){return this.part;}
        public void change1part(){this.part=1;}
        public void change0part(){this.part=0;} 
        public int kioli(){return (int)Math.sqrt((this.p2.x-this.p1.x)*(this.p2.x-this.p1.x)+(this.p2.y-this.p1.y)*(this.p2.y-this.p1.y));}
     }
  
    class Round implements shap,Serializable{
    	public Point p1,p2;public int type=1;int part=0;int chax,chay;
    	public Round(Point a,Point b){
    		this.p1=a;
    		this.p2=b;
    		}
    	public void draw(Graphics g){	
			Graphics2D g2d = (Graphics2D)g;
			g2d.setColor(Color.BLACK);
			g2d.drawOval(p1.x,p1.y, p2.x-p1.x, p2.y-p1.y);
		}
		public int cat(Point a){
			                 if(Math.abs(a.x-p1.x)<=20&&Math.abs(a.y-p1.y)<=20) return 1;
			                 else return 0;
			               }
        public void move1(Point m,Point n){
                                           this.p1.x=this.p1.x+n.x-m.x; 
                                           this.p2.x=this.p2.x+n.x-m.x;
                                           this.p1.y=this.p1.y+n.y-m.y;
                                           this.p2.y=this.p2.y+n.y-m.y;
                                          }
        public void change1(Point m,Point n){
                                             this.chax=(n.x-m.x)-(this.p2.x-this.p1.x);
                                             this.chay=(n.y-m.y)-(this.p2.y-this.p1.y);
                                             this.p2.x=this.p2.x+this.chax;
                                             this.p2.y=this.p2.y+this.chay;}
        public void change2(int a,int b){
        	                             this.p2.x=this.p2.x+a;
                                         this.p2.y=this.p2.y+b;}
    	public int getp1x(){return p1.x;}
        public int getp1y(){return p1.y;}
        public int getp2x(){return p2.x;}
        public int getp2y(){return p2.y;}
        public int getpart(){return this.part;}
        public void change1part(){this.part=1;}
        public void change0part(){this.part=0;}
        public int kioli(){return (int)Math.sqrt((this.p2.x-this.p1.x)*(this.p2.x-this.p1.x)+(this.p2.y-this.p1.y)*(this.p2.y-this.p1.y));} 
    	}
    
    class Square implements shap,Serializable{
    	public Point p1,p2;public int type=3;int part=0;int chax=0,chay=0;
    	public Square(Point a,Point b){
    		this.p1=a;
    		this.p2=b;
    		}
    	public void draw(Graphics g){
    		Graphics2D g2d = (Graphics2D)g;
			g2d.setColor(Color.BLACK);
			g2d.drawRect(p1.x,p1.y, p2.x-p1.x, p2.y-p1.y);
			} 
		public int cat(Point a){
			                 if(Math.abs(a.x-p1.x)<=20&&Math.abs(a.y-p1.y)<=20) return 1;
			                 else return 0;
			               }
        public void move1(Point m,Point n){
                                           this.p1.x=this.p1.x+n.x-m.x; 
                                           this.p2.x=this.p2.x+n.x-m.x;
                                           this.p1.y=this.p1.y+n.y-m.y;
                                           this.p2.y=this.p2.y+n.y-m.y;
                                          }
        public void change1(Point m,Point n){
                                             this.chax=(n.x-m.x)-(this.p2.x-this.p1.x);
                                             this.chay=(n.y-m.y)-(this.p2.y-this.p1.y);
                                             this.p2.x=this.p2.x+this.chax;
                                             this.p2.y=this.p2.y+this.chay;}
        public void change2(int a,int b){
        	                             this.p2.x=this.p2.x+a;
                                         this.p2.y=this.p2.y+b;}
    	public int getp1x(){return p1.x;}
        public int getp1y(){return p1.y;}
        public int getp2x(){return p2.x;}
        public int getp2y(){return p2.y;}
        public int getpart(){return this.part;}
        public void change1part(){this.part=1;}
        public void change0part(){this.part=0;} 
        public int kioli(){return (int)Math.sqrt((this.p2.x-this.p1.x)*(this.p2.x-this.p1.x)+(this.p2.y-this.p1.y)*(this.p2.y-this.p1.y));}
    	}
	
	class Factory{
		public Panel CreatePanel(){return new Panel();}
		public Button CreateButton(String s){return new Button(s);}
		public Point CreatePoint(int x,int y){return new Point(x,y);}
		public Round CreateRound(Point q,Point w){return new Round(q,w);}
		public Line CreateLine(Point q,Point w){return new Line(q,w);}
		public Square CreateSquare(Point q,Point w){return new Square(q,w);}
		public Iterator CreateIterator(){return new Iterator();}
		}
		
	class Iterator{
		Vector<shap> LB=new Vector<shap>();
		public int getsize(){return LB.size();}
		public void removeAllElements(){LB.removeAllElements();}
		public void addElement(shap I){LB.addElement(I);}
		public shap get(int i){return LB.get(i);}
		public shap elementAt(int i){return LB.elementAt(i);}
	//	public shap first(){}
	//	public shap next(){}
	//	public shap last(){}
		
		}
	public class Test{
	public static void main(String args[]){
		new aFrame();
		     }
		}