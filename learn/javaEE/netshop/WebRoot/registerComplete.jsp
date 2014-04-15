<%@ page language="java" import="java.util.*" pageEncoding="GB2312"%>
<%@ page contentType="text/html;charset=gb2312" %>
<%@ page import="javax.sql.*"%>
<%@ page import="java.sql.*"%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>
<title>完成注册</title>
</head>

<body>
	<%
		String userName = (String) session.getAttribute("userName");
		if (userName == null)
			response.sendRedirect("../login.jsp");
		String pwd=null;
		String sex=null;
		String pro=null;
		String intres=null;
		String selfIntro=null;

		String url = "jdbc:mysql://localhost:3306/netshop_db";
		Connection con = DriverManager.getConnection(url, "root", "abcd");
		String query = "select * from netshop_db.users where userName='"
				+ userName+"'";
		Statement st = con.createStatement();
		ResultSet rs = st.executeQuery(query);
		try {
			if (rs.next()) {
				pwd = rs.getString("pwd");
				sex = rs.getString("sex");
				pro = rs.getString("pro");
				intres = rs.getString("intres");
				selfIntro = rs.getString("selfIntro");
			}
		} catch (SQLException e) {
			out.println("<script >alert(\"数据库连接错误！" + e.getMessage()
					+ "\");</script>");
			out.println("<script>window.location.href='/register.jsp';</script>");
		}
	%>
	用户名：<%=userName%><BR /> 密码：<%=pwd%><BR /> 性别：<%=sex%><BR /> 职业：<%=pro%><BR />
	<BR /> 兴趣爱好：
	<%=intres%>
	<BR /> 自我介绍:
	<BR />
	<textarea rows="5" cols="40" name="selfIntro" readonly="true"><%=selfIntro%></textarea>
	<BR />
	<a href="login.jsp">返回登陆</a>
</body>
</html>
