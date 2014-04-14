<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">

<% String pageName=request.getParameter("pageName");
Integer count=(Integer)application.getAttribute(pageName);
if(count==null)
	count=new Integer(0);
count=new Integer(count.intValue()+1);
application.setAttribute(pageName,count);
out.println(count); %>

<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Insert title here</title>
</head>
<body>
</body>
</html>