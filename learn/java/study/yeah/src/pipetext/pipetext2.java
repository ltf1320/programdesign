package pipetext;

import java.io.*;

public class pipetext2 {
	public static void main(String argv[]) throws IOException {
		FileReader nums = new FileReader("nums.txt");
		BufferedReader buffin = new BufferedReader(nums);
		PipedInputStream pipedIn = new PipedInputStream();
		PipedOutputStream pipedOut = new PipedOutputStream(pipedIn);
		DataOutputStream out = new DataOutputStream(pipedOut);
		new Sort(out, buffin).start();
		BufferedInputStream pribuf = new BufferedInputStream(pipedIn);
		DataInputStream pri = new DataInputStream(pribuf);
		int output;
		while (true) {
			try {
				output = pri.readInt();
				System.out.println(output);
			} catch (EOFException e) {
				break;
			}
		}
	}
}

class Sort extends Thread {
	private BufferedReader in = null;
	private DataOutputStream out = null;
	static final int maxn = 100;

	Sort(DataOutputStream out, BufferedReader in) {
		this.in = in;
		this.out = out;
	}

	public void run() {
		if (in != null && out != null) {
			int tmp[] = new int[maxn];
			String input = null;
			int n = 0;
			try {
				while ((input = in.readLine()) != null) {
					tmp[n++] = Integer.parseInt(input);
				}
			} catch (IOException e) {
				System.err.println("sort read error " + e);
			}catch(NumberFormatException e)
			{
				System.err.println("sort change error " + e);
				System.err.println(input);
			}
			int tem;
			for (int i = n-1; i >= 0; i--) {
				for (int j = 0; j < i; j++) {
					if (tmp[j] > tmp[j + 1]) {
						tem = tmp[j];
						tmp[j] = tmp[j + 1];
						tmp[j + 1] = tem;
					}
				}
			}

			try {
				for (int i = 0; i < n; i++) {
					out.writeInt(tmp[i]);
				}
				out.flush();
				out.close();
			} catch (IOException err) {
				System.err.println("sort write error " + err);
			}
		}
	}
}
