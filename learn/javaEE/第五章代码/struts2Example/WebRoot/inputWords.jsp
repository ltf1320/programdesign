<%@ page language="java" import="java.util.*" pageEncoding="gb2312"%>
<%@ taglib prefix="s" uri="/struts-tags"%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>
    
	<title>һ���򵥵�Struts 2Ӧ��</title>
    <link rel="stylesheet" type="text/css" href="Style.css">

</head>
  
<body>
	<center>
		<h3>һ���򵥵�Struts 2Ӧ��</h3>
		<br/><hr/>	
		 
		<s:form name="myForm" action="test/showWords.action" method="post">
			<s:textfield name="name" label="��������������"/>
			<s:submit value="�ύ"/>
		</s:form>
		
		<!-- 
		<form name="myForm" action="test/showWords.action" method="post">
			����������������<input name="name" type="text"/><br/>
			<input type="submit" name="mySubmit" value="�ύ"/>
		</form>
		 -->
		
	</center>
</body>
</html>
