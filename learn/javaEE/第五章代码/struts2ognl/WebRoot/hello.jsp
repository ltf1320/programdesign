<%@ page language="java" import="java.util.*" pageEncoding="GB18030"%>
<%@ taglib prefix="s" uri="/struts-tags"%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
	<head>
		<title>hello</title>
	</head>
	<body>		
	    <s:form action="hello">
			<s:textfield name="account" label="�˺�"/>	
			<s:textfield name="password" label="����"/>			
			<s:submit value="�ύ"/>
		</s:form>	
	</body>
</html>
