
public class Rectangle implements Shape {
	int a,b;

	@Override
	public double getArea() {
		return a*b;
	}
	public Rectangle(int a,int b)
	{
		this.a=a;
		this.b=b;
	}
	public static void main(String args[])
	{
		Shape sp=new Rectangle(10,2);
		System.out.println(sp.getArea());
		sp=new Circle(10);
		System.out.println(sp.getArea());
	}
}
