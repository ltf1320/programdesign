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
    	
    	rec=new Button("������");
    	lin=new Button("��ֱ��");
    	ov=new Button("��Բ");
    	
    	qk=new Button("���");
    	sz=new Button("ѡ�п�");
    	xz=new Button("ѡ��");
    	zh=new Button("���");
    	fj=new Button("�ֽ�");
    	
    	bz=new Button("����˵��");
    	tc=new Button("�˳�");
    	sc=new Button("ɾ��");
    	
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
    		g.clearRect(0,0,this.getSize().width,this.getSize().height);//���
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
					"1.��λ�ͼ��" +
					"\n" +
					"        �����Ҫ����ͼ�εİ�ť��������������" +
					"\n"+
					"�϶����ɻ���ͼ�Σ��������������ͼ�Σ�ֻ�л�" +
					"\n" +
					"ͼʱ�����ʮ���εġ�"+
		     		"\n"+
					"2.���ѡ�У�" +
					"\n" +
					"        ������ѡ�С���ť����������϶���껭��" +
					"\n"+
					"һ�����ο���ѡ������Ҫѡ�е�ͼ�Σ�ֻ��ͼ����" +
					"\n"+
					"ȫ�����ο��Χס����ѡ�С�ѡ���ͷ�����ͼ��" +
					"\n"+
					"������Ӵ֣���ʱ����������϶�ͼ�Σ�Ҳ���Ը�" +
					"\n"+
					"��ͼ�ε���ɫ����ɾ��ѡ�е�ͼ�Ρ�������Ϻ�"+
					"\n"+
					"����壬ͼ��������ϸ����ʱ�ſ����ٴ�ִ������"+
					"\n"+
					"������"+
					"\n"+
					"3.�����ֽ�"+
					"\n"+
					"        ѡ�ж��ͼ�κ󣬵����ϰ�ť����ʱ�⼸��"+
					"\n"+
					"ͼ�ξ���һ�����壬�Ժ�ֻ�а��������ȫ��ѡ��"+
					"\n"+
					"����ѡ�С���Ҫ������ϣ���ѡ��ͼ����ϣ��ٵ�"+
					"\n"+
					"���ֽⰴť���ɡ�"
					,"����˵��", JOptionPane.INFORMATION_MESSAGE); 

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
			Color newcolor = JColorChooser.showDialog(this,"��ɫ��",Color.BLACK);
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
	