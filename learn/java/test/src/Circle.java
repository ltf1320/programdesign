
public class Circle implements Shape{
	double r;
	public Circle(double r)
	{
		this.r=r;
	}
	@Override
	public double getArea() {
		return r*r;
	}
	
}
