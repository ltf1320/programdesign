package netshop;

import java.io.IOException;
import java.sql.*;

import javax.sql.*;

import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class CheckRegister extends HttpServlet {

	/**
	 * Constructor of the object.
	 */
	public CheckRegister() {
		super();
	}

	/**
	 * The doGet method of the servlet. <br>
	 * 
	 * This method is called when a form has its tag value method equals to get.
	 * 
	 * @param request
	 *            the request send by the client to the server
	 * @param response
	 *            the response send by the server to the client
	 * @throws ServletException
	 *             if an error occurred
	 * @throws IOException
	 *             if an error occurred
	 */
	public void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doPost(request, response);
	}

	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		response.setContentType("text/html;charset=gb2312");
		PrintWriter out = response.getWriter();
		request.setCharacterEncoding("gb2312");
		String userName = request.getParameter("userName");
		String pwd = request.getParameter("password");
		String sex = request.getParameter("sex");
		String pro = request.getParameter("pro");
		String[] intres = request.getParameterValues("intres");
		String selfIntro = request.getParameter("selfIntro");
		String url = "jdbc:mysql://localhost:3306/netshop_db";
		Connection con;
		try {
			con = DriverManager.getConnection(url, "root", "abcd");
			String sql = "select count(*) from users where userName=? ";
			PreparedStatement st = con.prepareStatement(sql);
			st.setString(1, userName);
			ResultSet rs = st.executeQuery();
			rs.next();
			int cnt = rs.getInt(1);
			rs.close();
			if (cnt == 1) {
				out.println("<script >alert(\"用户已存在！\");</script>");
				out.println("<script>window.location.href='../register.jsp';</script>");
			} else {
				sql = "insert into users values(?,?,?,?,?,?)";
				st = con.prepareStatement(sql);
				st.setString(1, userName);
				st.setString(2, pwd);
				st.setString(3, sex);
				st.setString(4, pro);
				StringBuilder intreses = new StringBuilder();
				for (int i = 0; i < intres.length; i++) {
					if (i > 0)
						intreses.append(',');
					intreses.append(intres[i]);
				}
				st.setString(5, intreses.toString());
				st.setString(6, selfIntro);
				st.execute();
				out.println("<script >alert(\"注册成功！\");</script>");
				HttpSession session = request.getSession();
				session.setAttribute("userName", userName);
				out.println("<script>window.location.href='../registerComplete.jsp';</script>");
				con.close();
			}
		} catch (SQLException e) {
			out.println("<script >alert(\"数据库连接错误！" + e.getMessage()
					+ "\");</script>");
			out.println("<script>window.location.href='../register.jsp';</script>");
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
		}

	}

}
