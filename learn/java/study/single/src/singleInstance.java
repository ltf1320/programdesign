
public class singleInstance {
	static final singleInstance instance=new singleInstance();
	protected singleInstance(){}
	public singleInstance getInstance()
	{
		return instance;
	}
}
