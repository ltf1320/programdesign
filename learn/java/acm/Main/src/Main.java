import java.math.*;


import java.util.Scanner;
import java.io.*;
public class Main {
	static Scanner cin;
	static BigInteger p2[];
	static BigInteger B2;
	static final int maxn=65;
	static BigInteger inf;
	public static void main(String[] arg)
	{
		cin=new Scanner(System.in);
		p2=new BigInteger[maxn];
		p2[0]=new BigInteger("1");
		B2=new BigInteger("2");
		inf=B2.pow(100);
		for(int i=1;i<=64;i++)
			p2[i]=p2[i-1].multiply(B2);
		int T=cin.nextInt();
		while(T!=0)
		{
			T--;
			Main m=new Main();
		}
	}
	int N;
	BigInteger num[];
	BigInteger dp[];
	Main()
	{
		N=cin.nextInt();
		num=new BigInteger[maxn];
		dp=new BigInteger[maxn];
		dp[0]=new BigInteger("0");
		for(int i=1;i<=N;i++)
		{
			num[i]=cin.nextBigInteger();
			dp[i]=inf;
			int end=max(0,i-20);
			for(int j=end;j<i;j++)
				dp[i]=dp[i].min(dp[j].add(num[j+1].multiply(p2[i-j])));
		}
		System.out.println(dp[N]);
	}
	int max(int i, int j) {
		return i>j?i:j;
	}
}
