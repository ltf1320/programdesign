<%@ page language="java" pageEncoding="gb2312"%>
<%@page contentType="text/html; charset=gb2312" %>
<HTML><BODY>
  <%
    String yourName=(String)session.getAttribute("LogName");
    if (yourName==null)
    {
    %>����δ��¼
    <%
    }else
    {
    %>
    "<%=yourName%>"�Ѿ���¼
    <%
    }
  %>
</BODY></HTML>
