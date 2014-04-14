import java.sql.Array;
import java.util.*;

public class TryCatchFinally
{
	static void Proc(int sel)
	{
		try{
			if(sel==0){System.out.println("noException");
			return ;}
			else if(sel==1){int i=0;int j=4/i;}
			}catch(ArithmeticException e)
			{
				System.out.println("Catch");
			}
			catch(Exception e)
			{
				System.out.println("Will not be excuted");
			}finally
			{
				System.out.println("finally");
			}
	}
	public static void main(String[] args)
	{
		int[] a=new int[10];
		ArrayUtil	 b=new Array(a);
		
		for(int i=0;i<10;i++)
			a[i]=i;
		a[1]=a[10];
	}
}