<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<%@ page contentType="text/html; charset=UTF-8"%> 
<%@ page import="javax.sql.*"%>
<%@ page import="java.sql.*"%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>
<title>input.jsp</title>
</head>

<body>
 	<form action="suc.jsp" method="post">
	学号:<input type="text" name="id"/><BR>
	姓名:<input type="text" name="name"/><BR>
	专业:<input type="text" name="pro"/><BR>
	班级:<input type="text" name="clas"/><BR>
	入学时间:<input type="text" name="time"/><BR>
	<input type="submit" value="提交"/>
	</form>
</body>
</html>
