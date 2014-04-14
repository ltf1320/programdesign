package deals;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigDecimal;

import operations.calculateOne;

class dealBase
{
	StringBuffer dString;
	dealBase(String s)
	{
		dString =new StringBuffer(s);
	}
	void setString(String s)
	{
		dString=new StringBuffer(s);
	}
	void replace(int start,int end,BigDecimal num)
	{
		dString.delete(start, end);
		dString.insert(start, num.toString());
	}
}



public class dealString extends dealBase{
	dealString(String s) {
		super(s);
	}
	public static void main(String args[])
	{
		String tmp=null;
		dealString cal=new dealString("");
		BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
		while(true)
		{
			try{
				cal.setString(in.readLine());
				System.out.println(cal.getResult());
			}catch(IOException e)
			{
				System.err.println(e.getMessage());
			}catch(StringCalException e)
			{
				System.err.println(e.getReason());
			}
		}
	}
	BigDecimal getResult() throws StringCalException
	{
		int fb=dString.toString().indexOf('(');
		int lb=dString.toString().lastIndexOf(')');
		BigDecimal res=null;
		if(fb!=-1 && lb!=-1)
		{
			BigDecimal tmp=new dealString(dString.substring(fb,lb+1)).getResult();
			replace(fb,lb+1,tmp);
			fb=dString.toString().indexOf('(');
			lb=dString.toString().lastIndexOf(')');
		}
		if(fb==-1 && lb==-1)
		{
			String tmp=new dealAddOrSub(new dealMulOrDiv(new dealPow(dString.toString()).getResult()).getResult()).getResult();
//			String tmp2=new dealAddOrSub(dString.toString()).getResult();
			res=new BigDecimal(tmp);
		}
		else throw new StringCalException("expretion is incorrect!");
		return res;
	}
}

class dealOperation extends dealBase{
	int opindex;
	int index1;
	int index2;
	dealOperation(String s) {
		super(s);
	}
	String getResult() throws StringCalException
	{
		return null;
	}
	BigDecimal findNum1(int opindex) throws StringCalException
	{
		int k;
		for(k=opindex-1;k>=0;k--)
			if(dString.charAt(k)!=' '&&(dString.charAt(k)<'0' || dString.charAt(k)>'9') && dString.charAt(k)!='.')
				break;
		if(k==opindex-1)
			throw new StringCalException(1001,"expretion is incorrect!");
		index1=k+1;
		return new BigDecimal(dString.substring(k+1,opindex));
	}
	BigDecimal findNum2(int opindex) throws StringCalException
	{
		int k;
		for(k=opindex+1;k<dString.length();k++)
			if(dString.charAt(k)!=' '&&(dString.charAt(k)<'0' || dString.charAt(k)>'9')&& dString.charAt(k)!='.')
				break;
		if(k==opindex+1) throw new StringCalException(1002,"expretion is incorrect!");
		index2=k;
		return new BigDecimal(dString.substring(opindex+1,k));
	}
	int findIndex(char op)
	{
		return dString.toString().indexOf(op);
	}
	void deal(char op) throws StringCalException
	{
		opindex=findIndex(op);
		while(opindex!=-1)
		{
			BigDecimal tmp=new calculateOne(findNum1(opindex),findNum2(opindex),op).getResult();
			replace(index1,index2,tmp);
			findIndex(op);
		}
	}
	void deal2(char op1,char op2) throws StringCalException
	{
		char op=op1;
		opindex=findIndex(op1);
		int intmp=findIndex(op2);
		if((intmp<opindex && intmp!=-1)||opindex==-1)
		{
			op=op2;
			opindex=intmp;
		}
		while(opindex!=-1)
		{
			BigDecimal tmp=new calculateOne(findNum1(opindex),findNum2(opindex),op).getResult();
			replace(index1,index2,tmp);
			op=op1;
			opindex=findIndex(op1);
			intmp=findIndex(op2);
			if((intmp<opindex && intmp!=-1)||opindex==-1)
			{
				op=op2;
				opindex=intmp;
			}
		}
	}
}

class dealPow extends dealOperation
{
	dealPow(String s)
	{
		super(s);
	}
	String getResult() throws StringCalException
	{
		deal('^');
		return dString.toString();
	}
}

class dealMulOrDiv extends dealOperation
{
	dealMulOrDiv(String s)
	{
		super(s);
	}
	String getResult() throws StringCalException
	{
		deal2('*','/');
		return dString.toString();
	}
}

class dealAddOrSub extends dealOperation
{
	dealAddOrSub(String s)
	{
		super(s);
	}
	String getResult() throws StringCalException
	{
		deal2('+','-');
		return dString.toString();
	}
}

//各种bug，如负数的处理，2*2/4之类的

