package io;

import java.io.*;

public class text {
	public static void main(String argv[]) {
		try {
			File inputfile = new File("files\\in.txt");
			File outputfile = new File("files\\out.txt");
			FileInputStream fin = new FileInputStream(inputfile);
			FileOutputStream fout = new FileOutputStream(outputfile);
			BufferedInputStream in = new BufferedInputStream(fin);
			BufferedOutputStream out = new BufferedOutputStream(fout);
			int c;
			while ((c = in.read()) != -1) {
				out.write(c);
			}
			out.flush();
			in.close();
			out.close();
		} catch (FileNotFoundException e) {
			System.err.println("file not found!\nmessage:" + e.getMessage());
		} catch (IOException e) {
			System.err.println("IO exception\nmessage:" + e.getMessage());
		}
	}
}
