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
    	<p>��ǰ�û�Ϊ��<%=name %></p>
    	<a href="login.jsp">��½</a>&nbsp;&nbsp;&nbsp;<a href="logout.jsp">ע��</a>
  </body>
</html>
