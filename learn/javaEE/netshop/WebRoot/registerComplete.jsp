<%@ page language="java" import="java.util.*" pageEncoding="GB2312"%>
<%@ page contentType="text/html;charset=gb2312" %>
<%@ page import="javax.sql.*"%>
<%@ page import="java.sql.*"%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>
<title>���ע��</title>
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
			out.println("<script >alert(\"���ݿ����Ӵ���" + e.getMessage()
					+ "\");</script>");
			out.println("<script>window.location.href='/register.jsp';</script>");
		}
	%>
	�û�����<%=userName%><BR /> ���룺<%=pwd%><BR /> �Ա�<%=sex%><BR /> ְҵ��<%=pro%><BR />
	<BR /> ��Ȥ���ã�
	<%=intres%>
	<BR /> ���ҽ���:
	<BR />
	<textarea rows="5" cols="40" name="selfIntro" readonly="true"><%=selfIntro%></textarea>
	<BR />
	<a href="login.jsp">���ص�½</a>
</body>
</html>
