<%@ page language="java" import="java.util.*" pageEncoding="GB2312"%>
<%@ page import="javax.sql.*" %>
<%@ page import="java.sql.*" %>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <title>���ע��</title>
  </head>
  
  <body>
  <%request.setCharacterEncoding("GB2312");%>
  <%
  String userName=request.getParameter("userName");
	String pwd=request.getParameter("password");
	String sex=request.getParameter("sex");
	String pro=request.getParameter("pro");
	String[] intres=request.getParameterValues("intres");
	String selfIntro=request.getParameter("selfIntro"); 
	
	Class.forName("com.mysql.jdbc.Driver");
	String url="jdbc:oracle:thin:@localhost:3304:netshop_DB";
	Connection con=DriverManager.getConnection(url,"root","abcd");
	
	%>
    �û�����<%=userName %><BR/>
    	���룺<%=pwd %><BR/>
    	�Ա�<%=sex %><BR/>
    	ְҵ��<%=pro %><BR/>
    	<BR/>
    	��Ȥ���ã�
    	<%if(intres!=null)
    	for(int i=0;i<intres.length;i++) out.println(intres[i]); %>
     	<BR/>
     	���ҽ���:<BR/>
     	<textarea rows="5" cols="40" name="selfIntro" readonly="true" ><%=selfIntro %></textarea><BR/>
     	<a href="login.jsp">���ص�½</a>
  </body>
</html>
