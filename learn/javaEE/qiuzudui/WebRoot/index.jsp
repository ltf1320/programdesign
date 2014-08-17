<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<%@page import="connect.*" %>
<%@ taglib uri="/struts-tags" prefix="s" %>
<%@page import="org.hibernate.*" %>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
Session ses=HibernateSessionFactory.getSession();
SQLQuery qu=ses.createSQLQuery("select * from message order by createTime desc").addEntity(Message.class);
List<Message> msgli=(List<Message>)qu.list();
request.setAttribute("msgli", msgli);	
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
  <link rel="stylesheet" type="text/css" href="<%=basePath %>ext-all.css">
    <base href="<%=basePath%>">
    
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
    <%@include file="template.jsp" %>
    <div style="margin-left:20px;margin-top:30px;">
  				<s:iterator value="#request.msgli" status="st" >
  				<div style="border:1px solid #96c2f1;background:#eff7ff;width:30%;float:left;margin-left:1%;height:130px;margin-top:2px;">
  				<div>
  					<label><s:property value="title"/></label>
  					</div><div>
  					<label><s:property value="createTime"/></label>
  					<a href="<%=basePath %>showUser.jsp?userName=<s:property value='users.userName'/>"><s:property value="users.userName"/></a>
  				</div>
  				<div>
  					<label><s:property value="cl1"/>/<s:property value="cl2"/></label>
  				</div>
  				<div>
  					时间：<s:property value="time"/>
  				</div>
  				<div>
  					<s:property value="text"/>
  				</div>
  				<div>
  					<HR style="FILTER: progid:DXImageTransform.Microsoft.Shadow(color:#987cb9,direction:145,strength:15)" width="90%" color=#987cb9 SIZE=1>
  					<s:property value="opt1"/>&nbsp;
  					<s:property value="opt2"/>&nbsp;
  					<s:property value="opt3"/>&nbsp;
  				</div>
  				</div>
  				</s:iterator>
  			</div>
  </body>
</html>
