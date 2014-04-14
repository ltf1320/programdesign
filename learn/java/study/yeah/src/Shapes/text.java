package Shapes;
import java.util.*;

public class text
{
	public static void main(String args[])
	{
		cal();
	}
	public static void cal()
	{
		Shape[] s=new Shape[9];
		Random rand=new Random();
		for(int i=0;i<s.length;++i)
		{
			switch(rand.nextInt(3))
			{
			case 0:s[i]=new Circle();break;
			case 1:s[i]=new Square();break;
			case 2:s[i]=new Triangle();break;
			}
		}
		for(int i=0;i<s.length;++i)
		{
			s[i].draw();
			if(s[i] instanceof Square)
			{
				Square a=(Square)s[i];
				System.out.println(a.area());
			}
		}
		
	}
}
