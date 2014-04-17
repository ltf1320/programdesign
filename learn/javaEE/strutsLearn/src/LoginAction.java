import com.opensymphony.xwork2.ActionSupport;

public class LoginAction extends ActionSupport {
	private static final long serialVersionUID=1L;
	private String userName;
	private String password;
	
	public String getUserName()
	{
		return userName;
	}
	
	public void setUserName(String userName)
	{
		this.userName=userName;
	}
	
	public String getPassword()
	{
		return password;
	}
	
	public void setPassword(String password)
	{
		this.password=password;
	}
	
	@Override
	public String execute() throws Exception
	{
		if("ltf".equals(userName)&&"hahaha".equals(password))
			return SUCCESS;
		return LOGIN;
	}
}
