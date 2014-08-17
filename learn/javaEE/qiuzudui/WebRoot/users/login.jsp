<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>
<%@ taglib uri="/struts-tags" prefix="s" %>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>My JSP 'login.jsp' starting page</title>
    
	<meta http-equiv="pragma" content="no-cache">
	<meta http-equiv="cache-control" content="no-cache">
	<meta http-equiv="expires" content="0">    
	<meta http-equiv="keywords" content="keyword1,keyword2,keyword3">
	<meta http-equiv="description" content="This is my page">
	<link rel="stylesheet" type="text/css" href="<%=basePath %>ext-all.css">

  </head>
  
  <body>
    <%@include file="../template.jsp" %>
    <div class="login">
    <div style="height:50px;width:100%;background-color:#F1E1FF;text-align:left;padding-top:10px;">
    	<img src="<%=basePath %>/img/login.png">
    </div>
    <div style="background-color:#F1E1FF;padding-top:10px;">
    <s:form action="login" method="post" theme="simple" >
    	<s:textfield name="userName" value="用户名" cssStyle="height:40px;width:300px;font-size:16;"></s:textfield><BR>
    	<s:password name="pwd" cssStyle="height:40px;width:300px;margin-top:10px;"></s:password><BR>
    	<s:submit value="登陆" cssStyle="height:40px;width:300px;margin-top:20px;background-color:#4400B3;color:#FFF;"></s:submit>
    	</s:form>
    	<br>
    	<a href="<%=basePath %>/users/register.jsp" style="margin-left:200px;text-align:left;">注册</a>
    </div>
    </div>
    
  </body>
</html>
