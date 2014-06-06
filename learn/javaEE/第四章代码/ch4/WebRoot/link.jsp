<%@ page language="java" pageEncoding="GBK"%>  

<html>
<head>
<title>中文问题</title>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">  
</head>
<% //request.setCharacterEncoding("GBK");  %>

<%String uname=request.getParameter("uname");
  //uname=new String(uname.getBytes("ISO8859_1"), "gb2312"); 
%>
<body>
  <%=uname %>
</body>
</html>
