<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<%@page import="connect.*" %>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";

%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>My JSP 'searchShow.jsp' starting page</title>
    
	<meta http-equiv="pragma" content="no-cache">
	<meta http-equiv="cache-control" content="no-cache">
	<meta http-equiv="expires" content="0">    
	<meta http-equiv="keywords" content="keyword1,keyword2,keyword3">
	<meta http-equiv="description" content="This is my page">
	<link rel="stylesheet" type="text/css" href="<%=basePath %>ext-all.css">

  </head>
  
  <body>
  		<%@include file="template.jsp"%>
  		<div class="show">
  		<s:if test="msgli.size==0">
  		<div class="unfinded">
  			<label >未找到任何相关信息</label>
  			</div>
  		</s:if>
  		<s:else>
  			<div class="msgs">
  				<s:iterator value="msgli" >
  				<div style="border:1px solid #96c2f1;background:#eff7ff;width:30%;float:left;margin-left:1%;height:130px;margin-top:2px;">
  				<div>
  					<label><s:property value="title"/></label>
  					</div><div>
  					<label><s:property value="createTime"/></label>
  					<a href="<%=basePath %>showUser.jsp?userName=<s:property value='users.userName'/>"><s:property value="users.userName"/></a>
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
  		</s:else>
  		
  		</div>
  </body>
</html>
