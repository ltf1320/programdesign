
public class PluralText {
	public static void main(String[] args)
	{
		plural a=new plural(5,6);
		plural b=new plural(-2,6);
		System.out.println("a+b is "+a.add(b));
	}
}


class plural
{
	private float pnum,snum;
	plural(float snum,float pnum)
	{
		this.pnum=pnum;
		this.snum=snum;
	}
	plural(plural a)
	{
		pnum=a.pnum;
		snum=a.snum;
	}
	plural(){}
	void setData(float pnum,float snum)
	{
		this.pnum=pnum;
		this.snum=snum;
	}
	plural add(plural a)
	{
		plural res=new plural(a);
		res.pnum+=pnum;
		res.snum+=snum;
		return res;
	}
	plural sub(plural a)
	{
		plural res=new plural(this);
		res.pnum-=a.pnum;
		res.snum-=a.snum;
		return res;
	}
	plural mul(plural a)
	{
		plural res=new plural();
		res.snum=snum*a.snum-pnum*a.pnum;
		res.pnum=snum*a.pnum+pnum*a.snum;
		return res;
	}
	plural mul(int a)
	{
		plural res=new plural(this);
		res.pnum*=a;
		res.snum*=a;
		return res;
	}
	plural div(plural a)
	{
		plural res=new plural(a);
		a.pnum*=-1;
		res=this.mul(a);
		res=res.div(a.pnum*a.pnum+a.snum*a.snum);
		return res;
	}
	plural div(float a)
	{
		plural res=new plural(this);
		res.pnum/=a;
		res.snum/=a;
		return res;
	}
	public String toString()
	{
		String res;
		if(pnum>0)
			res=(snum+"+"+pnum+"i");
		else if(pnum<0)
			res=(snum+"-"+(-pnum)+"i");
		else res=(""+snum);
		return res;
	}
}