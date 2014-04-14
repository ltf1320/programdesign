<%@ page language="java" import="java.util.*" pageEncoding="GB18030"%>
<%@page contentType="text/html;charset=gbk" %>
<%=session.getId() %><br>
<% String name=(String)session.getAttribute("userName");
session.invalidate(); %>
<%=name %> ё╛ты╪Шё║<br>
<%=session.getId() %><br>
<% name=(String)session.getAttribute("userName");%><br>
<%=name %> 