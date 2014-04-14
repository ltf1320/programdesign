import java.math.*;
import java.util.Scanner;

public class apb {
	public static void main(String argv[])
	{
		BigDecimal a,b;
		int T;
		Scanner cin=new Scanner(System.in);
		T=cin.nextInt();
		while(T!=0)
		{
			T--;
			a=cin.nextBigDecimal();
			b=cin.nextBigDecimal();
			a=a.add(b);
			System.out.println(a);
		}
	}
}
