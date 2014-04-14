package StringCal;
import java.math.*;
import java.util.InputMismatchException;
import java.util.Scanner;
import java.io.*;
public class StringCal {
	static final int maxn=500;
	static final int errPri=-1;
	static final int addPri=1;
	static final int subPri=1;
	static final int mulPri=2;
	static final int divPri=2;
	static final int powPri=3;
	static final int braPri=0;
	
	public static void main(String[] args)
	{
		Scanner in=new Scanner(System.in);
		BigDecimal tmp = null;
		while(in.hasNext())
		{
			try{
			tmp=calculate(in.nextLine());
			}catch(StringCalException e)
			{
				System.err.println(e.getReason());
				continue;
			}
			System.out.println(tmp);
		}
		
	}
	
	
	public static BigDecimal calculate(String arg) throws StringCalException
	{
		if(arg.equals("")) return new BigDecimal(0);
		arg=dispose(arg);
		BigDecimal[] numStack=new BigDecimal[maxn];
		int numTop=0;
		char[] chStack=new char[maxn];
		int chTop=0;
		BufferedReader BuffIn=new BufferedReader(new StringReader(arg));
		Scanner in=new Scanner(BuffIn);
		char chtmp = 0;
		BigDecimal detmp;
		int nowPri,lastPri;
		lastPri=errPri;
		while(in.hasNext())
		{
			try{
			numStack[numTop++]=in.nextBigDecimal();
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
			//括号另外处理：
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
					if(chTop<0) throw new StringCalException("Error 0002:Expect '('");
					if(numTop<2) throw new StringCalException("Error 0005:expretion is incorrect");
					detmp=numStack[--numTop];
					numStack[numTop-1]=calculate(numStack[numTop-1],detmp,chtmp);
				}
				while(in.hasNext())
				{
					chtmp=in.next().charAt(0);
					if(chtmp==' ') continue;
					else break;
				}
//				chStack[chTop++]=chtmp;
				if(!in.hasNext()) break;
				if(chTop>0)
					lastPri=getPri(chStack[chTop-1]);
				else lastPri=braPri;
			}
			//对优先级进行判断，更新栈的信息
			nowPri=getPri(chtmp);
			if(nowPri<=lastPri)
			{
				while(nowPri<=lastPri)
				{
					if(chTop==0 || numTop<2) throw new StringCalException("Error 0011:expretion is incorrect");
					detmp=numStack[--numTop];
					numStack[numTop-1]=calculate(numStack[numTop-1],detmp,chStack[--chTop]);
					if(chTop==0) break;
					lastPri=getPri(chStack[chTop-1]);
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
		//对剩下的表达式进行计算
		while(true)
		{
			if(chTop==0 && numTop==1)
			{
				return numStack[0];
			}
			if(chTop==0) throw new StringCalException("Error 0006:expretion is incorrect");
			if(numTop==1 || numTop==0) throw new StringCalException("Error 0007:expretion is incorrect");
			chtmp=chStack[--chTop];
			detmp=numStack[--numTop];
			numStack[numTop-1]=calculate(numStack[numTop-1],detmp,chtmp);
		}
	}
	public static int getPri(char s) throws StringCalException
	{
		switch(s)
		{
			case '+':return addPri;
			case '-':return subPri;
			case '*':return mulPri;
			case '/':return divPri;
			case '^':return powPri;
			case '(':return braPri;
			default: throw new StringCalException("Error 0003:symbol "+s+" is unknown");
		}
	}
	public static BigDecimal calculate(BigDecimal a,BigDecimal b,char s) throws StringCalException
	{
		switch(s)
		{
			case '+':return a.add(b);
			case '-':return a.subtract(b);
			case '*':return a.multiply(b);
			case '/':return a.divide(b,20,BigDecimal.ROUND_HALF_DOWN);
			case '^':
				return a.pow(b.intValue());
			default: throw new StringCalException("Error 0004:symbol "+s+" is unknown");
		}
	}
	
	static String dispose(String arg) throws StringCalException
	{
		StringBuffer res=new StringBuffer("");
		char tmp;
		boolean ss=true;
		for(int i=0;i<arg.length();++i)
		{
			tmp=arg.charAt(i);
			if((tmp>='0' && tmp<='9')|| tmp=='.')
			{
				res.append(tmp);
				ss=false;
			}
			else if(tmp=='+' || tmp=='-')
			{
				if(ss) res.append(" "+tmp);
				else res.append(" "+tmp+" ");
				ss=false;
			}
			else if(tmp=='*' || tmp=='/' || tmp=='^')
			{
				res.append(" "+tmp+" ");
				ss=false;
			}
			else if( tmp=='(' || tmp==')')
			{
				res.append(" "+tmp+" ");
				ss=true;
			}
			else if (tmp==' ')continue;
			else throw new StringCalException("Error 0008:symbol "+tmp+" is unknown");
		}
		return res.toString();
	}
}