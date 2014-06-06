<%@ page language="java" import="java.util.*" pageEncoding="GB18030"%>
<%@ taglib prefix="s" uri="/struts-tags"%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
	<head>
		<title>hello</title>
	</head>
	<body>		
	    <s:form action="hello">
			<s:textfield name="account" label="ÕËºÅ"/>	
			<s:textfield name="password" label="ÃÜÂë"/>			
			<s:submit value="Ìá½»"/>
		</s:form>	
	</body>
</html>
