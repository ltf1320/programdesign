package d;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Point;
import java.io.Serializable;
import java.util.Vector;
public class zhushap implements shap,Serializable{
    private Vector<shap> zh=new Vector<shap>();
	public void draw(Graphics g)
	{
		for(int i=0;i<zh.size();i++)
		{
			zh.get(i).draw(g);
		}
	}
	public void getmou(Point sb, Point se)
	{
		 for(int i=0;i<zh.size();i++)
		 {
			 zh.get(i).getmou(sb, se);
		 }
	}
	public void getshapecolor(Color c) 
	{
		for(int i=0;i<zh.size();i++)
		{
			zh.get(i).getshapecolor(c);
		}
		
	}
	public boolean ischangcolor(int n)
	{
		boolean col=false;
	    if(n==0)
	    {
	    	for(int i=0;i<zh.size();i++)
	    	{
	    		zh.get(i).ischangcolor(0);
	    	}
	    	col=true;
	    }
	    if(n==1)
	    {
	    	for(int j=0;j<zh.size();j++)
	    	{
	    		zh.get(j).ischangcolor(1);
	    	}
	    	col=false;
	    }
	    return col;
	}
	public boolean isseclect(int m)
	{
		boolean hyp=true;
		if(m==0)
	   {			
		    for(int i=0;i<zh.size();i++)
		    {
		    	hyp=hyp&&zh.get(i).isseclect(0);
		    }
		   if(!hyp)
		   {
			   for(int h=0;h<zh.size();h++)
			   {
				   zh.get(h).isseclect(1);
			   }
			   hyp=false;
		   }
	   }
		if(m==1)
		{
			 for(int h=0;h<zh.size();h++)
			  zh.get(h).isseclect(1);
			 hyp=false;
		}
			
		return hyp;
	}
	public void setPe(Point pe)
	{
	}
	public void xzmove(int m, int n) 
	{
		for(int i=0;i<zh.size();i++)
		{
			zh.get(i).xzmove(m, n);
		}
	}
	public void addshap(shap s)
	{
		 zh.add(s);
	}
	public int getsize()
	{
		return zh.size();
	}
	public shap remove(int i)
	{
		return zh.remove(i);
	}
	public void baocunp(int x, Point b, Point e, int m, int n)
	{
		if(x==0)
		{
			for(int k=0;k<zh.size();k++)
				zh.get(k).baocunp(x, b, e, m, n);
		}
		if(x==1)
		{
			for(int a=0;a<zh.size();a++)
				zh.get(a).baocunp(x, b, e, m, n);
		}
	}
}
