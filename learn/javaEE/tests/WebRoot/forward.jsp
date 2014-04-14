<%@ page language="java" import="java.util.*" pageEncoding="GB18030"%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">

<% 
	String to=request.getParameter("to");
 %>


<html>
  <head>
  </head>
  
  <body>
 	<%if("include".equals(to)){ %> 
    <jsp:forward page="include.jsp"></jsp:forward>
   <%} else{ %> 
    <jsp:forward page="sum.jsp"></jsp:forward>
    <%} %>
  </body>
</html>
