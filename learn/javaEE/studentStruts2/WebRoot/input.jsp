<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<%@ page contentType="text/html; charset=UTF-8"%> 
<%@ page import="javax.sql.*"%>
<%@ page import="java.sql.*"%>
<%@ taglib uri="/struts-tags" prefix="s" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>
<title>input.jsp</title>
</head>

<body>
 	<s:form action="/sub" method="post">
	<s:textfield name="id" label="学号"></s:textfield>
	<s:textfield name="name" label="姓名"></s:textfield>
	<s:textfield name="pro" label="专业"></s:textfield>
	<s:textfield name="clas" label="班级"></s:textfield>
	<s:textfield name="time" label="入学时间"></s:textfield>
	<s:submit value="提交" />
	</s:form>
</body>
</html>
