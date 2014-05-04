<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>


<% String id=request.getParameter("id");
	String name=request.getParameter("name");
	String pro=request.getParameter("pro");
	String clas=request.getParameter("clas");
	String time=request.getParameter("time");
	
 %>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    
    <title>My JSP 'suc.jsp' starting page</title>
    
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
    学号:<%=id %><BR>
	姓名:<%=name %> <BR>
	专业:<%=pro %><BR>
	班级:<%=clas %><BR>
	入学时间:<%=time %><BR>
  </body>
</html>
