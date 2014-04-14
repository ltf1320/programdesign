package enumtext;

public class enums {
	public static void main(String argv[])
	{
		for(Week w:Week.values())
		{
			System.out.print(w.name()+",");
		}
		
	}
}


enum Week
{
	Mon(1),Tue(2),Wed(3),Thu(4),Fri(5),Sat(6),Sun(7);
	private final int value;
	Week(int v){this.value=v;}
	public int value(){return value;}
}