
public class TCSRunningException extends Exception {
	private static final long serialVersionUID = 6080787721265232598L;
	public static final int HitWall=1;
	public static final int HitSelf=2;
	private int errorNum;
	public TCSRunningException(int errorNumber)
	{
		errorNum=errorNumber;
	}
	public int  getErrorNum()
	{
		return errorNum;
	}
}