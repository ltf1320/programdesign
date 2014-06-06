<%@ page language="java" import="java.util.*" pageEncoding="gb2312"%>
<%@ taglib prefix="s" uri="/struts-tags"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>
    
	<title>Struts 2应用</title>
    
	<link rel="stylesheet" type="text/css" href="Style.css">

</head>
  
<body>
	<center>		
		<h3>Struts 2应用</h3>
		<br/><hr/>
		<s:fielderror/>
		<s:form action="showPerson">		   
			<s:textfield name="name" label="姓名"/>	
			<s:textfield name="sex" label="性别"/>
			<s:textfield name="age" label="年龄"/>
			<s:textfield name="address" label="住址"/>
			<s:submit value="提交"/>
		</s:form>
	</center>
</body>
</html>
