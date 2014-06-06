<%@ page contentType="text/html; charset=gb2312" language="java"  errorPage="" %>
<%@ page import="java.sql.*"%>
<%@ page import="javax.sql.*"%>
<%@ page import="javax.naming.*"%>
	<html>
	<head>
	<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
	<title>通过Tomcat连接池连接SQL Server数据库</title>
	<style type="text/css">
	<!--
	.style1 {color: #0000FF}
	-->
	</style>
	</head>
	
	<body>
	<%
	System.out.println("*******");
	%>
	<div align="center">
	<span class="style1">
	<%
	System.out.println("*******");
	DataSource ds = null;
	Connection conn=null;
	Statement stmt=null;
	ResultSet rs=null;
	
	try{
		InitialContext ctx=new InitialContext();//准备JNDI的访问环境
		ds=(DataSource)ctx.lookup("java:comp/env/jdbc/connectionPool");//jdbc/connectionPool为连接池名
		  //java:comp/env是环境命名上下文（environment naming context）
		  //JDBC数据源引用在java:comp/env/jdbc子上下文中声明
		conn = ds.getConnection();		
	}
	catch(Exception e){
		e.printStackTrace();
	}
	%>
	<%if(conn!=null){
	try{
		stmt=conn.createStatement();
		rs=stmt.executeQuery("select * from authors");
	%>
	取得数据库连接成功！！！</span>
	<table width="220" border="1">
	  <tr align="center">
	    <td><span class="style1">姓名</span></td>
	    <td><span class="style1">地址</span></td>
	    <td><span class="style1">城市</span></td>
	  </tr>
	  <%while(rs.next()){
	%>
	  <tr align="center">
	    <td><%=rs.getString("au_lname")%></td>
	    <td><%=rs.getString("address")%></td>
	    <td><%=rs.getString("city")%></td>
	  </tr>
	  <%}%>
	</table>
	<%
	}catch(Exception e){
	  e.printStackTrace();
	}finally{//关闭结果集、连接 
		try{
			if(rs!=null) rs.close();
			conn.close();
			System.out.println("关闭连接^^^^");
		}catch(Exception e){}
	}
	
	%>
	<%}%>
    </div>
	</body>
	</html>
