package deals;

public class StringCalException extends Exception {
	private static final long serialVersionUID = 7448871955248755264L;
	private String reason;
	private int id;
	public StringCalException(int id,String s)
	{
		this.id=id;
		setReason(s);
	}
	public StringCalException(String s)
	{
		setReason(s);
		id=-1;
	}
	public int getId()
	{
		return id;
	}
	public String getReason() {
		return ""+id+":"+reason;
	}
	public void setReason(String reason) {
		this.reason = reason;
	}
}
