<%@ page language="java" import="java.util.*" pageEncoding="GB18030"%>
<%@ taglib uri="/struts-tags" prefix="s" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <title>login</title>
    
	<meta http-equiv="pragma" content="no-cache">
	<meta http-equiv="cache-control" content="no-cache">
	<meta http-equiv="expires" content="0">    
	<meta http-equiv="keywords" content="keyword1,keyword2,keyword3">
	<meta http-equiv="description" content="This is my page">
	<!--
	<link rel="stylesheet" type="text/css" href="styles.css">
	-->

  </head>
  
  <body>
    <s:form action="/login" method="post">
    	<s:label value="ÏµÍ³µÇÂ¼"></s:label>
    	<s:textfield name="userName" label="ÕËºÅ"></s:textfield>
    	<s:password name="password" label="ÃÜÂë"></s:password>
    	<s:submit value="µÇÂ¼"/>
    </s:form>
  </body>
</html>
