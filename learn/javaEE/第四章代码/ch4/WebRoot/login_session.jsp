<%@ page language="java" pageEncoding="gb2312"%>
<%@ page contentType="text/html; charset=gb2312" %>
<%@ page import="java.util.*" %>
<HTML>
  <BODY>
<% request.setCharacterEncoding("gb2312");//��ʾ���� %>
  <%
    String Name=request.getParameter("UserName");
    session.setAttribute("LogName", Name);  
 %>
  �������"<%=Name%>"�Ѿ�д��session 
  <br>
  <a href="check_session.jsp">check session</a>
  </BODY>
</HTML>
