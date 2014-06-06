<%@ page language="java" import="java.util.*" pageEncoding="GB18030"%>
<%@ taglib prefix="s" uri="/struts-tags"%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
	<head>
		<title>Struts2计算器</title>
	</head>

	<body>
	<%request.setAttribute("aaa","11111111"); %>
		<form id="caclForm" method="post" action="add1.action">
			number1:
			<input type="text" name="num1" />
			<br>
			number2:
			<input type="text" name="num2" />
			<br>
			<input type="submit" value="加法">
		</form>
		
		<%-- 
		<s:form action="add1">
			<s:textfield name="num1" label="number1"/>
			<s:textfield name="num2" label="number2"/>
			
			<s:submit value="加法"/>
		</s:form>
		--%>
		
		
	</body>
</html>
