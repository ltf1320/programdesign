<%@ page language="java" import="java.util.*" pageEncoding="gb2312"%>
<%@ taglib prefix="s" uri="/struts-tags"%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>
    
	<title>一个简单的Struts 2应用</title>
    <link rel="stylesheet" type="text/css" href="Style.css">

</head>
  
<body>
	<center>
		<h3>一个简单的Struts 2应用</h3>
		<br/><hr/>	
		 
		<s:form name="myForm" action="test/showWords.action" method="post">
			<s:textfield name="name" label="请输入您的姓名"/>
			<s:submit value="提交"/>
		</s:form>
		
		<!-- 
		<form name="myForm" action="test/showWords.action" method="post">
			请输入您的姓名：<input name="name" type="text"/><br/>
			<input type="submit" name="mySubmit" value="提交"/>
		</form>
		 -->
		
	</center>
</body>
</html>
