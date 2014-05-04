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
		String url = "jdbc:mysql://localhost:3306/netshop_db";
		Connection con=null;
		ResultSet rs=null;
		boolean suc=false;
		HttpServletResponse response = (HttpServletResponse)
				ActionContext.getContext().get(org.apache.struts2.StrutsStatics.HTTP_RESPONSE);
		PrintWriter out= response.getWriter();
		try
		{
			con=DriverManager.getConnection(url,"root","abcd");
			String sql="select count(*) from users where userName=? and pwd=?";
			PreparedStatement st=con.prepareStatement(sql);
			st.setString(1, userName);
			st.setString(2, password);
			rs= st.executeQuery();
			rs.next();
			if(rs.getInt(1)==1)
			{
				HttpSession session=(HttpSession) ActionContext.getContext().getSession();
				session.setAttribute("userName", userName);
				suc=true;
				out.println("<script>alert('登陆成功！');</script>");
			}
			else
			{
				out.println("<script>alert('用户名或密码错误！');</script>");
			}
		}catch(SQLException e)
		{
			out.println("<script>alert('数据库连接错误！');</script>");
		}
		if(rs!=null)
			rs.close();
		if(con!=null)
			con.close();
		if(suc)
			return SUCCESS;
		return LOGIN;
	}
}
