package Animals;
public class Animals {
	void feed(){};
}

class Lion extends Animals
{
	void feed()
	{
		System.out.println("Lion feeded");
	}
}

class Cat extends Animals
{
	void feed()
	{
		System.out.println("cat feeded");
	}
}

