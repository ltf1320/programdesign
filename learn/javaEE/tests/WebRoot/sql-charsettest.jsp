<%@ page language="java" import="java.util.*" pageEncoding="GB2312"%>
<%@ page import="javax.sql.*"%>
<%@ page import="java.sql.*"%>
<%
	String url = "jdbc:mysql://localhost:3306/test";
	Connection con;
	try {
		con = DriverManager.getConnection(url, "root", "abcd");
		String sql="update tt set dd='ÎûÎû' where cc='aa'";
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
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>
</head>

<body>
	This is my JSP page.
	<br>
</body>
</html>
