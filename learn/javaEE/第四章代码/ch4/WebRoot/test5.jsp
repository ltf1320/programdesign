<%@ page language="java" import="java.util.*" %>
<html>
<head>
<title> test5 </title>
</head>
<body>
<center>
<%Date date1=new Date(); %> 

<%! Date date=new Date(); %> 
<%! int a, b, c; %>
<% int d=1; %>
<% a=12;b=a; c=a+b;%>
<font color="blue">
<%=date.toString()%>
</font><br>
<b>a=<%= a %></b> <br>
<b>b=<%= b %></b><br>
<b>c=<%= c %></b><br>

<%=date1.toString()%>
<br><br>
</center>


</body>
</html>
