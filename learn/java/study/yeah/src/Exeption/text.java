package Exeption;
import java.io.*;
import java.util.*;

class listOfNumbers
{
	private final int size=10;
	private ArrayList<Integer> List;
	public listOfNumbers()
	{
		List=new ArrayList<Integer>(size);
		for(int i=0;i<size;++i)
		{
			List.add(i);
		}
	}
	public void write()
	{
		PrintWriter out=null;
		try
		{
			out=new PrintWriter(new FileWriter("out.txt"));
			for(int i=0;i<size;++i)
			{
				out.println(List.get(i));
			}
		}catch(IOException e)
		{
			System.err.println("Caught IOException:"+e.getMessage());
		}
		catch(IndexOutOfBoundsException e)
		{
			System.err.println("Caught ArrayIndexOutOfBoundsException:"+e.getMessage());
		}
		finally
		{
			if(out==null)
				System.out.println("PrintWriter Not open");
			else
			{
				out.flush();
				out.close();
				out=null;
				System.out.println("file closed");
			}
		}
	}
}


public class text {
	public static void main(String argv[]){
		listOfNumbers list=new listOfNumbers();
		list.write();
	}
	
}
