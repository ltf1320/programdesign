<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>

<%@ taglib prefix="s" uri="/struts-tags"%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <title>My JSP 'index.jsp' starting page</title>
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
    <s:form action="smit" method="post">
    	<s:textfield name="userName" label="用户名"/>	
    	<s:password name="pwd" label="密码"/>
    	<s:password name="rpwd" label="验证密码"/>
    	<s:textfield name="birthday" label="出生日期">
    	<s:param name="value">
                            <s:date name="birthday" format="yyyy-MM-dd"/>
        </s:param>
        </s:textfield>
		<s:textfield name="height" label="身高"/>
		<s:textfield name="phone" label="电话"/>
		<s:textfield name="email" label="电子邮箱"/>
		<s:textfield name="blog" label="博客"/>
		<s:textfield name="address" label="地址"/>
	    <s:submit label="提交"></s:submit>
    </s:form>
  </body>
</html>