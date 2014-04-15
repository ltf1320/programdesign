package my.servlets;

import java.io.IOException;
import java.sql.*;
import javax.sql.*;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class mysqlCharset extends HttpServlet {

	/**
	 * Constructor of the object.
	 */
	public mysqlCharset() {
		super();
	}

	/**
	 * The doGet method of the servlet. <br>
	 *
	 * This method is called when a form has its tag value method equals to get.
	 * 
	 * @param request the request send by the client to the server
	 * @param response the response send by the server to the client
	 * @throws ServletException if an error occurred
	 * @throws IOException if an error occurred
	 */
	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {

		response.setContentType("text/html;charset=gb2312");
		PrintWriter out=response.getWriter();
		String url = "jdbc:mysql://localhost:3306/test";
		Connection con;
		try {
			
			con = DriverManager.getConnection(url, "root", "abcd");
			String sql=new String("update tt set dd='°¢µÏ°¢ÈøµÂ' where cc='aa'");
			Statement st=con.createStatement();
			st.execute(sql);
			
			sql="select * from tt where cc='aa'";
			ResultSet rs= st.executeQuery(sql);
			if(rs.next())
			{
				out.println(rs.getString(2));
			}
			
		} catch (SQLException e) {
			out.println(e.getMessage());
		}
	}
	public void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doPost(request,response);
	}
	

}
