<%@ page language="java" import="java.util.*" pageEncoding="GB18030"%>
<%@page contentType="text/html;charset=gbk" %>
<%=session.getId() %><br>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
  </head>
  
  <body>
    <%String name=request.getParameter("userName");
    if(name!=null)
    	session.setAttribute("userName", name); %>
    	<p>当前用户为：<%=name %></p>
    	<a href="login.jsp">登陆</a>&nbsp;&nbsp;&nbsp;<a href="logout.jsp">注销</a>
  </body>
</html>
