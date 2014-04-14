package io;
import java.io.*;
public class sys {
	public static void main(String argv[])
	{
		String tmp;
		BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
		try{
			tmp=in.readLine();
			while(!tmp.equals("quit"))
			{
				System.out.println(tmp);
				tmp=in.readLine();
			}
			System.out.println("End");
			in.close();
		}catch(IOException e)
		{
			System.err.println("input error "+e);
		}
	}
}
