<%@ page language="java" import="java.util.*" pageEncoding="GB18030"%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">

<% String name="";
if(!session.isNew())
{
name=(String)session.getAttribute("userName");
if(name==null) name="";} %>

<html>
  <head>
    
    <title>My JSP 'login.jsp'</title>
  </head>
  <p>��ӭ����</p>
  <p>session id:<%=session.getId() %></p>
  <body>
  	<form name="loginForm" method="post" action="check.jsp">
  		�û�����<input type="text" name="userName" value=<%=name %>>
  		<input type="submit" name="submit" value="�ύ">
   	</form>
  </body>
</html>
