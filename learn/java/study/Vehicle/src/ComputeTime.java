import java.util.*;
public class ComputeTime {
	public static void main(String args[])
	{
		Common vehicles[]=new Common[5];
		Random rd=new Random();
		for(int i=0;i<vehicles.length;++i)
		{
			if((rd.nextInt()&1)==1)
				vehicles[i]=new Car007();
			else vehicles[i]=new Plane();
			 vehicles[i].setNum(rd.nextInt()%100,rd.nextInt()%100,rd.nextInt()%100);
		}
		for(int i=0;i<vehicles.length;++i)
		{
			System.out.println("vehicles["+i+"]"+"is a "+vehicles[i].getClass().getName()+"  and it casts "+1000/(float)vehicles[i].calVelocity()+" hour(s) to past 1000km");
		}
	}
}
