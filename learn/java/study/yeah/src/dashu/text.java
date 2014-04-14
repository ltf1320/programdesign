package dashu;
import java.util.Scanner;
import java.math.BigInteger;
public class text {
	public static void main(String[] argv)
	{
		Scanner read=new Scanner(System.in);
		BigInteger a1,a2,res;
		while(read.hasNext())
		{
			a1=read.nextBigInteger();
			a2=read.nextBigInteger();
			res=a1.add(a2);
			System.out.println(res);
		}
	}
}
