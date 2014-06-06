<%@ page language="java" pageEncoding="gb2312"%>
<%@ page contentType="text/html; charset=gb2312" %>
<%@ page import="java.util.*" %>
<HTML>
  <BODY>
<% request.setCharacterEncoding("gb2312");//显示汉字 %>
  <%
    String Name=request.getParameter("UserName");
    session.setAttribute("LogName", Name);  
 %>
  你的名字"<%=Name%>"已经写入session 
  <br>
  <a href="check_session.jsp">check session</a>
  </BODY>
</HTML>
