
public class Car007 implements Common {
	int A=0;
	int B=0;
	int C=0;
	public void setNum(int a,int b,int c)
	{
		A=a;
		B=b;
		C=c;
	}
	public float calVelocity() {
		return (float)A*B/C;
	}

}
