<%@ page language="java" import="java.util.*" pageEncoding="GB18030"%>
<%@ taglib prefix="s" uri="/struts-tags"%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
	<head>
		<title>Struts2������</title>
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
			<input type="submit" value="�ӷ�">
		</form>
		
		<%-- 
		<s:form action="add1">
			<s:textfield name="num1" label="number1"/>
			<s:textfield name="num2" label="number2"/>
			
			<s:submit value="�ӷ�"/>
		</s:form>
		--%>
		
		
	</body>
</html>
