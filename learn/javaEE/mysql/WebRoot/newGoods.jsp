<%@ page language="java" import="java.util.*" import="java.sql.*" pageEncoding="UTF-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>My JSP 'newGoods.jsp' starting page</title>
    
	<meta http-equiv="pragma" content="no-cache">
	<meta http-equiv="cache-control" content="no-cache">
	<meta http-equiv="expires" content="0">    
	<meta http-equiv="keywords" content="keyword1,keyword2,keyword3">
	<meta http-equiv="description" content="This is my page">
	<!--
	<link rel="stylesheet" type="text/css" href="styles.css">
	-->

  </head>
  
  
  <body>
  <% request.setCharacterEncoding("utf-8");
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
	<%!
	String name ;
	String type;
	String price ;
	String quantity ;
	private boolean validate(){
		if(name==null||name.equals("")||type==null||type.equals("")||price==null||price.equals("")||quantity==null||quantity.equals("")){
			return false;
		}
		return true;
	}
	%>
	-------------------------------------------------------------------搜索结果
	<% 
		 name = request.getParameter("name");
		 type = request.getParameter("type");
		 price = request.getParameter("price");
		 quantity = request.getParameter("quantity");
		String  insertSQL = "Insert into goods(name,type,quantity,price) values('"+name+"','"+type+"','"+quantity+"','"+price+"')";
		
		out.println("!!!!!!!!^^^^^^^^!!!!!!"+insertSQL);
if(validate()){
        Statement statement = null;
		ResultSet resultSet = null;
		try {
			statement = con.createStatement();
			statement.execute(insertSQL);
	
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
    <form action="newGoods.jsp" method="post">
	名称：<input type="text" name="name"> <br/>
	类型：<input type="text" name="type">  <br/>
	价格：<input type="text" name="price">  <br/>
	数量：<input type="text" name="quantity"> <br/>
	<input type="submit" value="插入">
	</form>
  </body>
  <a href="index.jsp">查看结构</a>
</html>
