import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import com.opensymphony.xwork2.ActionContext;
import com.opensymphony.xwork2.ActionSupport;

public class loginAction extends ActionSupport {
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
		if(userName.equals("ltf")&&password.equals("hahaha"))
		{
			return SUCCESS;
		}
		return LOGIN;
	}
}
