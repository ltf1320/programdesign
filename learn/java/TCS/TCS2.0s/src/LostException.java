
public class LostException extends TCSRunningException {
	private static final long serialVersionUID = 5671172124122163142L;
	public static final int HeadCrash=3;
	int lostOne;
	public LostException(int errorNumber) {
		super(errorNumber);
		// TODO Auto-generated constructor stub
	}
	public LostException(int errorNumber,int LOne)
	{
		super(errorNumber);
		lostOne=LOne;
	}
	public int getLostOne()
	{
		return lostOne;
	}

}
