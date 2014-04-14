
<%@page import="javax.servlet.*" pageEncoding="gb2312" %>
<% int a=Integer.parseInt(request.getParameter("a"));
int b=Integer.parseInt(request.getParameter("b"));
out.println(a+b);%>
<br>