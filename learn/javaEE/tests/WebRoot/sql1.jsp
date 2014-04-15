<%@ page language="java" import="java.util.*" pageEncoding="GB18030"%>
<%@ page import="javax.sql.*" %>
<%@ page import="java.sql.*" %>

<%
//	Class.forName("com.mysql.jdbc.Driver");
	String url="jdbc:mysql://localhost:3306/netshop_db";
	Connection con=DriverManager.getConnection(url,"root","abcd");
	String query="select * from users";
	Statement st=con.createStatement();
	ResultSet rs=st.executeQuery(query);
	if(rs.next())
	{
		out.println(rs.getString(1));
		out.println(rs.getString("pwd"));
	}
	
	%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>

    <title>SQL</title>

  </head>
  
  <body>
  </body>
</html>
