<%@ page language="java" import="java.util.*" pageEncoding="GB18030"%>


<% //String userName=(String)session.getAttribute("userName");
	//if(userName==null)
	//	response.sendRedirect("login.jsp");
	 %>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <title>���</title>

  </head>
  
  <body>
    <form action="servlet/logout" method="post"> 
    ��ӭ${userName }&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
    	<input type="submit" value="ע��"/> 
    </form> <BR>
    ��Ʒ�б�
  </body>
</html>
