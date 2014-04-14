package pipetext;
import java.io.*;
public class pipetext {
	public static void main(String argv[]) throws IOException
	{
		FileReader words = new FileReader("words.txt");
		PipedReader pipedIn=new PipedReader();
		PipedWriter pipedOut=new PipedWriter(pipedIn);
		PrintWriter out=new PrintWriter(pipedOut);
		BufferedReader in=new BufferedReader(words);
		new ReverseThread(out,in).start();
		BufferedReader print=new BufferedReader(pipedIn);
		String output;
		while((output=print.readLine())!=null)
			System.out.println(output);
	}
}


class ReverseThread extends Thread
{
	private BufferedReader in=null;
	private PrintWriter out=null;
	ReverseThread(PrintWriter out,BufferedReader in)
	{
		this.out=out;
		this.in=in;
	}
	public void run()
	{
		if(in!=null && out!=null)
		{
			try{
				String input;
				while((input=in.readLine())!=null)
				{
					out.println(reverse(input));
					out.flush();
				}
			}catch(IOException e)
			{
				System.err.println("ReverseThread error:"+e);
			}
			out.close();  //一定注意要关闭管道，否则会出错
		}
	}
	private String reverse(String source)
	{
		int len=source.length();
		StringBuffer out=new StringBuffer(len);
		for(int i=0;i<len;++i)
		{
			out.append(source.charAt(len-i-1));
		}
		return out.toString();
	}
}