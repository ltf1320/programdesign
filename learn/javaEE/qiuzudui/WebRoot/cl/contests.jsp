<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<%@page import="connect.*" %>
<%@ taglib uri="/struts-tags" prefix="s" %>
<%@page import="org.hibernate.*" %>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
Session ses=HibernateSessionFactory.getSession();
SQLQuery qu=ses.createSQLQuery("select * from message where cl1='学科竞赛' order by createTime desc").addEntity(Message.class);
List<Message> msgli=(List<Message>)qu.list();
request.setAttribute("msgli", msgli);
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>My JSP 'contests.jsp' starting page</title>
    <link rel="stylesheet" type="text/css" href="<%=basePath %>ext-all.css">
	<meta http-equiv="pragma" content="no-cache">
	<meta http-equiv="cache-control" content="no-cache">
	<meta http-equiv="expires" content="0">    
	<meta http-equiv="keywords" content="keyword1,keyword2,keyword3">
	<meta http-equiv="description" content="This is my page">
	<!--
	<link rel="stylesheet" type="text/css" href="styles.css">
	-->
<link rel="stylesheet" type="text/css" href="<%=basePath %>ext-all.css">
  </head>
  
  <body>
  	<%@include file="../template.jsp" %>
  	<div style="margin-left:20px;margin-top:30px">
    <%@include file="showtemplate.jsp" %>
    </div>
  </body>
</html>
