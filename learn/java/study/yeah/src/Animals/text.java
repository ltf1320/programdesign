package Animals;

import java.util.LinkedList;

public class text {
	public static void main(String args[])
	{
		LinkedList<Lion> lionList=new LinkedList<Lion>();
		lionList.add(new Lion());
		lionList.add(new Lion());
		feedA.feed(lionList);
		
		LinkedList<Animals> anList=new LinkedList<Animals>();
		anList.add(new Cat());
		anList.add(new Lion());
		feedA.feed(anList);
		
		feedA.print(new Lion());
	}
}

class feedA
{
	public static void feed(LinkedList<? extends Animals> animals)
	{
		for(Animals i:animals)
		{
			i.feed();
		}
	}
	public static <T extends Animals> void print(T t)
	{
		System.out.println(t.getClass().getName());
	}
}
