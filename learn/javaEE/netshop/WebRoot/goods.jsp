<%@ page language="java" import="java.util.*" pageEncoding="GB18030"%>


<% //String userName=(String)session.getAttribute("userName");
	//if(userName==null)
	//	response.sendRedirect("login.jsp");
	 %>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <title>浏览</title>

  </head>
  
  <body>
    <form action="servlet/logout" method="post"> 
    欢迎${userName }&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    	<input type="submit" value="注销"/> 
    </form> <BR>
    商品列表：
  </body>
</html>
