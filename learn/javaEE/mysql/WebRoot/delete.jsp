<%@page import="java.sql.Connection"%>
<%@page import="java.sql.Driver"%>
<%@page import="java.sql.DriverManager"%>
<%@ page language="java" import="java.util.*" import="java.sql.*" pageEncoding="UTF-8"%>
<%
	String path = request.getContextPath();
	String basePath = request.getScheme() + "://"
			+ request.getServerName() + ":" + request.getServerPort()
			+ path + "/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>
<base href="<%=basePath%>">

<title>My JSP 'index.jsp' starting page</title>
<meta http-equiv="pragma" content="no-cache">
<meta http-equiv="cache-control" content="no-cache">
<meta http-equiv="expires" content="0">
<meta http-equiv="keywords" content="keyword1,keyword2,keyword3">
<meta http-equiv="description" content="This is my page">
<!--
	<link rel="stylesheet" type="text/css" href="styles.css">
	-->
</head>
<% request.setCharacterEncoding("UTF-8");
	Class.forName("com.mysql.jdbc.Driver");
	// DriverManager.registerDriver(new Driver());
	String url = "jdbc:mysql://localhost:3306/db_he";
	String user = "root";
	String pwd = "heminjia8";
	Connection con = DriverManager.getConnection(url, user, pwd);
%>
<body>
	<%
		if (con != null) {
	%>
	数据库连接成功！！！
	<%
		} else {
	%>
	数据库连接失败！！！
	<%
		}
	%>
	-------------------------------------------------------------------搜索结果
	<%
	   
		String name = request.getParameter("name");
		String type = request.getParameter("type");
		String price = request.getParameter("price");
		String quantity = request.getParameter("quantity");
		String deleteSQL = "Delete From goods where ";
		int length = deleteSQL.length();
		if (name!=null&&!name.equals("")) {
			deleteSQL += "name='"+name+"' ";
			
		}
		if (type!=null&&!type.equals("")) {
			if (deleteSQL.length() > length) {
				deleteSQL += "And type='"+type+"' ";
			}
			else{
			deleteSQL += "type='"+type+"' ";
			}
			
			
		}
		if (price!=null&&!price.equals("")) {
		if (deleteSQL.length() > length) {
				deleteSQL += "And price="+price+" ";
			}
			else{
			deleteSQL += "price="+price+" ";
			}
		}
		if (quantity!=null&&!quantity.equals("")) {
		if (deleteSQL.length() > length) {
				deleteSQL += "And quantity="+quantity+" ";
			}
			else{
			deleteSQL += "quantity="+quantity+" ";
			}
		}
		out.println("!!!!!!!!^^^^^^^^!!!!!!"+deleteSQL);
if(!deleteSQL.equals("Delete From goods where ")){
        Statement statement = null;
		ResultSet resultSet = null;
		try {
			statement = con.createStatement();
			
			statement.execute(deleteSQL);
	%>
	<table width="413" border="0" cellspacing="0" cellpadding="0">
		<tr>
			<td width="86">名称</td>
			<td width="80">类型</td>
			<td width="82">价格</td>
			<td width="82">数量</td>
		</tr>
		<%
			for (int i = 0; i < 10; i++) {
					resultSet.next();
		%>
		<tr>
			<td><%=resultSet.getString("name")%></td>
			<td><%=resultSet.getString("type")%></td>
			<td><%=resultSet.getString("price")%></td>
			<td><%=resultSet.getString("quantity")%></td>

		</tr>
		<%
			}//end for
			} catch (Exception e) {
				e.printStackTrace();
			} finally {//关闭结果集、连接 
				try {
					if (resultSet != null)
						resultSet.close();
					if (statement != null)
						statement.close();
					con.close();
				} catch (Exception e) {
				}
			}}
		%>
	</table>

 
	--------------------------------------------------------------------------------搜索
	<form action="delete.jsp" method="post">
	名称：<input type="text" name="name"> <br/>
	类型：<input type="text" name="type">  <br/>
	价格：<input type="text" name="price">  <br/>
	数量：<input type="text" name="quantity"> <br/>
	<input type="submit" value="删除">
	</form>
<a href="index.jsp">查看结果</a><br/>


</body>
</html>
