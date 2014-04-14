package d;
import java.awt.event.*;
import java.awt.*;
import java.io.*;
import java.util.Vector;
import javax.swing.JColorChooser;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
public class drawbord extends Frame implements ActionListener,MouseMotionListener,MouseListener,Serializable
{
    private Button rec,lin,ov,qk,sz,bz,gs,tc,zh,fj,sc,xz;
   
    int flag=-1;
    shap sh;
    shap s;
    Point m=new Point();
    Point sbb=new Point();
    Point n=new Point();
    Point tsbb=new Point();
    Point xzd=new Point();
    Panel bord,bord1;
    Vector<shap> al=new Vector<shap>();
    Vector<shap> a=new Vector<shap>();
    FileInputStream picin = null;
    FileOutputStream picout = null;
    
    ObjectInputStream vin = null;
    ObjectOutputStream vout = null;
    FileDialog openpicture,savepicture;
    public drawbord(String s)
    {
    	super(s);
    	bord=new Panel();
    	bord1=new Panel();
    	
    	rec=new Button("画矩形");
    	lin=new Button("画直线");
    	ov=new Button("画圆");
    	
    	qk=new Button("清空");
    	sz=new Button("选中框");
    	xz=new Button("选中");
    	zh=new Button("组合");
    	fj=new Button("分解");
    	
    	bz=new Button("操作说明");
    	tc=new Button("退出");
    	sc=new Button("删除");
    	
    	bord.add(rec);
    	bord.add(ov);
    	bord.add(lin);
    	
    	bord.add(bz);
    	bord.add(tc);
    	
    	bord1.add(sz);
    	bord1.add(zh);
    	bord1.add(fj);
    	
    	bord1.add(sc);
    	bord1.add(qk);
    	this.add(bord,BorderLayout.NORTH);
    	this.add(bord1,BorderLayout.SOUTH);
    	rec.addActionListener(this);
    	lin.addActionListener(this);
    	ov.addActionListener(this);
    	qk.addActionListener(this);
    	
    	sz.addActionListener(this);
    	
    	bz.addActionListener(this);
    	tc.addActionListener(this);
    	zh.addActionListener(this);
    	fj.addActionListener(this);
    	sc.addActionListener(this);
    	addMouseListener(this);
    	addMouseMotionListener(this);
    	
    	 
    	 
    	this.addWindowListener(new WindowAdapter()
    	  {
    	    public void windowClosing(WindowEvent e)
    	   {  System.exit(0);
    	    }
    	  });
        this.validate();
        this.setSize(900,600);
    	this.setLocation(60, 60);
    	this.setVisible(true);   	
    }
    
    public void paint(Graphics g){
    	if(flag==0)
    	 {
    		g.clearRect(0,0,this.getSize().width,this.getSize().height);//清除
    		al.removeAllElements();
    	 }
        if(flag==4){
        	for(int i=0;i<a.size();i++)
      		    a.get(i).draw(g);
           }
    	   
    	for(int j=0;j<al.size();j++)
      		    al.get(j).draw(g);
    	  
    }
	//@SuppressWarnings("unchecked")
	public void actionPerformed(ActionEvent e) {
		if(e.getSource()==sc)
		{
			for(int i=0;i<al.size();i++)
			{
				if(al.get(i).isseclect(0))
					{
					al.removeElementAt(i);
					i--;
					}
				
			}
			this.repaint();
			flag=4;
		}
		if(e.getSource()==zh)
		{
			zhushap zs=new zhushap();
			shap zh;
			for(int i=0;i<al.size();i++)
			{     
				if(al.get(i).isseclect(0))
					{
						zh=al.remove(i);
						i--;
						zs.addshap(zh);
					}
			}
			if(zs.getsize()!=0){
				al.add(zs);
				this.repaint();
			}
		}
		if(e.getSource()==fj)
		{
			shap sa;
			zhushap zhp=new zhushap();
			int hyp=al.size();
			for(int i=0;i<hyp;i++)
			{
				sa=al.get(i);
				if(sa.isseclect(0))
				{
					if(sa instanceof zhushap)
					{
						zhp=(zhushap) al.remove(i);
						int p=zhp.getsize();
						for(int j=0;j<p;j++)
						{	
							al.add(zhp.remove(0));
							
						}
						i--;
						hyp--;
					}
				}
			}
			this.repaint();
		}
		if(e.getSource()==tc)
		{
			 System.exit(0);
		}
		if(e.getSource()==bz)
		{
			JOptionPane.showMessageDialog(null,
					"1.如何画图：" +
					"\n" +
					"        点击所要画的图形的按钮后，用鼠标在面板上" +
					"\n"+
					"拖动即可画出图形，可连续画出多个图形，只有画" +
					"\n" +
					"图时鼠标是十字形的。"+
		     		"\n"+
					"2.如何选中：" +
					"\n" +
					"        单击“选中”按钮后，在面板上拖动鼠标画出" +
					"\n"+
					"一个矩形框来选中你所要选中的图形，只有图形完" +
					"\n"+
					"全被矩形框包围住才算选中。选中释放鼠标后图形" +
					"\n"+
					"线条会加粗，此时你可以任意拖动图形，也可以改" +
					"\n"+
					"变图形的颜色或是删除选中的图形。操作完毕后单"+
					"\n"+
					"击面板，图形线条变细，此时才可以再次执行其他"+
					"\n"+
					"操作。"+
					"\n"+
					"3.组合与分解"+
					"\n"+
					"        选中多个图形后，点击组合按钮，此时这几个"+
					"\n"+
					"图形就是一个整体，以后只有把这个整体全部选中"+
					"\n"+
					"才算选中。若要撤销组合，先选中图形组合，再点"+
					"\n"+
					"击分解按钮即可。"
					,"操作说明", JOptionPane.INFORMATION_MESSAGE); 

		}
		if(e.getSource()==rec){
			flag=1;
		}
		if(e.getSource()==lin){
			flag=2;
		}
		if(e.getSource()==ov){
			flag=3;
		}
		if(e.getSource()==qk){
			flag=0;
			repaint();
		}
		if(e.getSource()==sz){
			flag=4;
		}
		if(e.getSource()==xz)
		{ flag=7;}
		if(e.getSource()==gs){
			flag=-1;
			Color newcolor = JColorChooser.showDialog(this,"调色板",Color.BLACK);
			if(newcolor==null)
				{
				  newcolor=Color.BLACK;
				}
		}
	}

	public void mouseDragged(MouseEvent e) {
		if(flag!=-1&&flag!=4&&flag!=5&&flag!=6)
		{ 
			sh.setPe(e.getPoint());
		    this.repaint();
		}
		if(flag==4){
			s.setPe(e.getPoint());
		    this.repaint();
		}
		if(flag==6){
			for(int k=0;k<al.size();k++)
			{ 
				if(al.get(k).isseclect(0))
					{ 
		             al.get(k).xzmove(e.getPoint().x-tsbb.x,e.getPoint().y-tsbb.y);}
			        }
			this.repaint();
		}
	}

	public void mousePressed(MouseEvent e) {
		  switch(flag){
			case 1: this.setCursor(Frame.CROSSHAIR_CURSOR);
				    sh=new shaprec(e.getPoint(),e.getPoint());
					sh.setPe(e.getPoint());
					al.add(sh);
				    m=e.getPoint();
		            break;
		    case 2: this.setCursor(Frame.CROSSHAIR_CURSOR);
		    	    sh=new shapline(e.getPoint(),e.getPoint());
		            sh.setPe(e.getPoint());
		            al.add(sh);
		            m=e.getPoint();
	        		break;
		    case 3:this.setCursor(Frame.CROSSHAIR_CURSOR);
		    	   sh=new shapoval(e.getPoint(),e.getPoint());
		           sh.setPe(e.getPoint());
                   al.add(sh);
                   m=e.getPoint();
                   break;
		    case 4: s=new shaprec(e.getPoint(),e.getPoint());
		           s.setPe(e.getPoint());
		           a.add(s);
		           this.sbb=e.getPoint();
		           break;
		    case 6:this.tsbb=e.getPoint();
		           break;
		    case 7: xzd=e.getPoint();
		    default :
				}	
		    
	}
	
	public void mouseReleased(MouseEvent e) {	
		if(flag!=-1&&flag!=4&&flag!=5&&flag!=6)
		 {  this.setCursor(Frame.DEFAULT_CURSOR);
			n=e.getPoint();
		    int len=al.size();
		    al.get(len-1).setPe(e.getPoint());
		    al.get(len-1).baocunp(0,m,n,0,0);
		    this.repaint();
		    
		  }
		if(flag==4){
			a.removeAllElements();
			flag=5;
			for(int js=0;js<al.size();js++)
			   {
				al.get(js).getmou(this.sbb,e.getPoint());
				al.get(js).isseclect(0);
			   }			   
			this.repaint();
			int jj=0;
			for(int jk=0;jk<al.size();jk++)
			{
				if(al.get(jk).isseclect(0))
					jj++;
			}
			if(jj==0)
				flag=4;
			else 
				flag=6;
			return;
		    }
		if(flag==6){
			for(int k=0;k<al.size();k++)
			 {  
				Point m1=new Point();
				Point n1=new Point();
				if(al.get(k).isseclect(0))
		         {
					al.get(k).xzmove(e.getPoint().x-tsbb.x,e.getPoint().y-tsbb.y);
					al.get(k).baocunp(1,m1, n1,e.getPoint().x-tsbb.x,e.getPoint().y-tsbb.y);
				 }
			 }
			flag=-1;
			this.repaint();			
		    }
		
		}
	public void mouseMoved(MouseEvent e) {			
	}
	public void mouseClicked(MouseEvent e) {
		for(int jg=0;jg<al.size();jg++)
		 {
           if(al.get(jg).isseclect(0))
           {
              al.get(jg).isseclect(1);   
           }
 		 }
		  this.repaint();
		  flag=4;
	}
	public void mouseEntered(MouseEvent e) {				
	}
	public void mouseExited(MouseEvent e) {				
	}		
}
	