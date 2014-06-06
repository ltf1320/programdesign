<%@ page language="java" import="java.util.*" pageEncoding="GB18030"%>
<%@ taglib prefix="s" uri="/struts-tags" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
	<head>
		<title>计算结果</title>

	</head>

	<body>
		number1：<s:property value="num1"/>
		<br>
		number2：<s:property value="num2"/>
		<br>
		结果：<s:property value="#request.resu"/><br>或
		    <s:property value="#session.addresult"/><br><br>
		
		resu_Attribute: <%=request.getAttribute("resu") %><br/>
		
	</body>
</html>
