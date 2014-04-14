<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1" import="javax.servlet.http.*"%>

<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Insert title here</title>
</head>
<body>
	<%String name=request.getParameter("userName");
		String pwd=request.getParameter("userPwd");
		out.println(name);
		out.println("<br>");
		if("admin".equals(name) && "admin".equals(pwd))
		{
			out.println("OK");
			Cookie c=new Cookie("username","john");
			response.addCookie(c);
		}else
			out.println("ERROR"); %>
<jsp:include page="count.jsp">	
    	<jsp:param name="pageName" value="testCount"/>
    	</jsp:include>
</body>
</html>