package Shapes;

public interface Shape
{
	abstract void draw();
	void erase();
}

class Circle implements Shape
{
	public void draw()
	{
		System.out.println("draw circle");
	}
	public void erase()
	{
		System.out.println("erase circle");
	}
}

class Triangle implements Shape
{
	public void draw()
	{
		System.out.println("draw triangle");
	}
	public void erase()
	{
		System.out.println("erase triangle");
	}
}

class Square implements Shape
{
	public void draw()
	{
		System.out.println("draw square");
	}
	public void erase()
	{
		System.out.println("erase square");
	}
	String area()
	{
		return ("Square area");
	}
}
