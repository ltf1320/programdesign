package netshop;

import java.io.IOException;
import java.sql.*;

import javax.sql.*;

import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class CheckLogin extends HttpServlet {

	/**
	 * Constructor of the object.
	 */
	public CheckLogin() {
		super();
	}

	/**
	 * The doPost method of the servlet. <br>
	 *
	 * This method is called when a form has its tag value method equals to post.
	 * 
	 * @param request the request send by the client to the server
	 * @param response the response send by the server to the client
	 * @throws ServletException if an error occurred
	 * @throws IOException if an error occurred
	 */
	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {

		response.setContentType("text/html;charset=gb2312");
		request.setCharacterEncoding("gb2312");
		PrintWriter out = response.getWriter();
		String userName=request.getParameter("userName");
		String pwd=request.getParameter("password");
		String url = "jdbc:mysql://localhost:3306/netshop_db";
		Connection con;
		try
		{
			con=DriverManager.getConnection(url,"root","abcd");
			String sql="select count(*) from users where userName=? and pwd=?";
			PreparedStatement st=con.prepareStatement(sql);
			st.setString(1, userName);
			st.setString(2, pwd);
			ResultSet rs= st.executeQuery();
			rs.next();
			if(rs.getInt(1)==1)
			{
				HttpSession session=request.getSession();
				session.setAttribute("userName", userName);
				out.println("<script>alert('登录成功！');window.location.href='../goods.jsp'</script>");
			}
			else
			{
				out.println("<script>alert('用户名或密码错误！');window.location.href='../login.jsp'</script>");
			}
			rs.close();
			con.close();
		}catch(SQLException e)
		{
			//out.println("<script>alert(数据库连接错误！"+e.getMessage()+");window.location.href='../login.jsp'</script>");
			out.println("<script>alert('数据库连接错误！');</script>");
			out.println("<script>window.location.href='../login.jsp';</script>");
		}
	}
}
