import java.util.InputMismatchException;
import java.util.Scanner;
import java.io.*;
public class caler {
	static final int maxn=500;
	static final int errPri=-1;
	static final int addPri=1;
	static final int subPri=1;
	static final int mulPri=2;
	static final int divPri=2;
	static final int powPri=3;
	static final int braPri=0;
	String calString=null;
	public static void main(String[] args)
	{
		Scanner in=new Scanner(System.in);
		double tmp = 0;
		caler cer=new caler();
		while(in.hasNext())
		{
			try{
			cer.setString(in.nextLine());
			tmp=cer.calculate();
			}catch(RuntimeException e)
			{
				System.err.println(e.getMessage());
				continue;
			}
			System.out.println(tmp);
		}
		
	}
	public void setString(String arg)
	{
		calString=arg;
		return;
	}
	
	public double calculate() throws RuntimeException
	{
		if(calString==null) throw new RuntimeException("calString is not set");
		String arg=deal(calString);
		double[] numStack=new double[maxn];
		int numTop=0;
		char[] chStack=new char[maxn];
		int chTop=0;
		BufferedReader BuffIn=new BufferedReader(new StringReader(arg));
		Scanner in=new Scanner(BuffIn);
		char chtmp = 0;
		double detmp;
		int nowPri,lastPri;
		lastPri=errPri;
		while(in.hasNext())
		{
			try{
			numStack[numTop++]=in.nextDouble();
			}catch(InputMismatchException e)
			{
				numTop--;
				boolean ss=false;
				while(in.hasNext())
				{
					chtmp=in.next().charAt(0);
					if(chtmp==' ') continue;
					if(chtmp=='(')
					{
						ss=true;
						break;
					}
				}
				if(ss)
				{
					lastPri=getPri(chtmp);
					chStack[chTop++]=chtmp;
					continue;
				}
			}
			if(!in.hasNext()) break;
			chtmp=in.next().charAt(0);
			if(chtmp==' ') continue;
			if(chtmp=='(')
			{
				chStack[chTop++]=chtmp;
				lastPri=getPri(chtmp);
				continue;
			}
			
			if(chtmp==')')
			{
				while(true)
				{
					chtmp=chStack[--chTop];
					if(chtmp=='(')
						break;
					if(chTop<0) throw new RuntimeException("expretion is incorrect");
					if(numTop<2) throw new RuntimeException("expretion is incorrect");
					detmp=numStack[--numTop];
					numStack[numTop-1]=calculate(numStack[numTop-1],detmp,chtmp);
				}
				while(in.hasNext())
				{
					chtmp=in.next().charAt(0);
					if(chtmp==' ') continue;
					else break;
				}
				if(!in.hasNext()) break;
				lastPri=getPri(chStack[chTop-1]);
			}
			nowPri=getPri(chtmp);
			if(nowPri<lastPri)
			{
				while(nowPri<lastPri)
				{
					if(chTop==0 || numTop<2) throw new RuntimeException("expretion is incorrect");
					detmp=numStack[--numTop];
					numStack[numTop-1]=calculate(numStack[numTop-1],detmp,chStack[--chTop]);
					if(chTop==0) break;
					lastPri=chStack[chTop-1];
				}
				lastPri=getPri(chtmp);
				chStack[chTop++]=chtmp;
			}
			else
			{
				chStack[chTop++]=chtmp;
				lastPri=nowPri;
			}
		}
		while(true)
		{
			if(chTop==0 && numTop==1)
			{
				return numStack[0];
			}
			if(chTop==0) throw new RuntimeException("expretion is incorrect");
			if(numTop==1 || numTop==0) throw new RuntimeException("expretion is incorrect");
			chtmp=chStack[--chTop];
			detmp=numStack[--numTop];
			numStack[numTop-1]=calculate(numStack[numTop-1],detmp,chtmp);
		}
	}
	int getPri(char s) throws RuntimeException
	{
		switch(s)
		{
			case '+':return addPri;
			case '-':return subPri;
			case '*':return mulPri;
			case '/':return divPri;
			case '^':return powPri;
			case '(':return braPri;
			default: throw new RuntimeException("symbol "+s+" is unknown");
		}
	}
	double calculate(double a,double b,char s) throws RuntimeException
	{
		switch(s)
		{
			case '+':return a+b;
			case '-':return a-b;
			case '*':return a*b;
			case '/':return a/b;
			case '^':
				return Math.pow(a,b);
			default: throw new RuntimeException("symbol "+s+" is unknown");
		}
	}
	
	String deal(String arg) throws RuntimeException
	{
		StringBuffer res=new StringBuffer("");
		char tmp;
		for(int i=0;i<arg.length();++i)
		{
			tmp=arg.charAt(i);
			if((tmp>='0' && tmp<='9')|| tmp=='.')
			{
				res.append(tmp);
			}
			else if(tmp=='+' || tmp=='-' || tmp=='*' || tmp=='/' || tmp=='^')
			{
				res.append(" "+tmp+" ");
			}
			else if( tmp=='(' || tmp==')')
			{
				res.append(" "+tmp+" ");
			}
			else if (tmp==' ')continue;
			else throw new RuntimeException("symbol "+tmp+" is unknown");
		}
		return res.toString();
	}
}