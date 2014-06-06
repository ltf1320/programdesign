<%@ page language="java" import="java.util.*" %>
<%@ page isErrorPage="true" %>
<html> 
<head>
<title>test </title>
</head>
 <body bgcolor="white"> 
<font color="blue">
<%!int i=1;%> 
 <%i++;
 System.out.println("i= "+i);
%>

<%int a=1;%> 
<%a++;
 System.out.println("a= "+a);
%>
</font>
 </body> 
</html>
