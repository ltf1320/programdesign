<%@ page language="java" import="java.util.*" pageEncoding="gb2312"%>
<%@ taglib prefix="s" uri="/struts-tags"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>
    
	<title>Struts 2Ӧ��</title>
    
	<link rel="stylesheet" type="text/css" href="Style.css">

</head>
  
<body>
	<center>		
		<h3>Struts 2Ӧ��</h3>
		<br/><hr/>
		<s:fielderror/>
		<s:form action="showPerson">		   
			<s:textfield name="name" label="����"/>	
			<s:textfield name="sex" label="�Ա�"/>
			<s:textfield name="age" label="����"/>
			<s:textfield name="address" label="סַ"/>
			<s:submit value="�ύ"/>
		</s:form>
	</center>
</body>
</html>
