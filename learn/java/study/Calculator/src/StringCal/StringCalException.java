package StringCal;

public class StringCalException extends Exception {
	private static final long serialVersionUID = 7448871955248755264L;
	private String reason;
	public StringCalException(String s)
	{
		setReason(s);
	}
	public String getReason() {
		return reason;
	}
	public void setReason(String reason) {
		this.reason = reason;
	}
}
