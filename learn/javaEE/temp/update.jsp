<%@page import="connect.HibernateSessionFactory"%>
<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<%@ taglib prefix="s" uri="/struts-tags"%>
<%@ page import="java.sql.*"%>
<%@ page import="javax.sql.*"%>
<%@ page import="javax.naming.*"%>
<%@ page import="org.hibernate.*" %>

<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>My JSP 'update.jsp' starting page</title>
    
	<meta http-equiv="pragma" content="no-cache">
	<meta http-equiv="cache-control" content="no-cache">
	<meta http-equiv="expires" content="0">    
	<meta http-equiv="keywords" content="keyword1,keyword2,keyword3">
	<meta http-equiv="description" content="This is my page">
	<!--
	<link rel="stylesheet" type="text/css" href="styles.css">
	-->

  </head>
  <%!String name,type,price,stock; %>
  <%
  	int Id=Integer.parseInt((String)session.getAttribute("upId"));
  		Session s=HibernateSessionFactory.getSession();
  		try
  		{
  	Transaction tr=s.beginTransaction();
  	SQLQuery qu=s.createSQLQuery("select * from good where Id=?");
  	qu.setInteger(1, Id);
  	connect.good res=(connect.good)qu.uniqueResult();
  	request.setAttribute("name", res.getName());
  	request.setAttribute("type", res.getType());
  	request.setAttribute("price", res.getPrice());
  	request.setAttribute("stock", res.getStock());
  		}
  		catch(Exception e)
  		{
  	e.printStackTrace();
  		}
  		finally
  		{
  	s.close();
  		}
  %>
  
  <body>
    <s:form action="/doUpdate" method="post">
    	<s:label value="Id"/><s:label value="%{#session.upId}"/>
    	<s:label value=" 商品名:"/><s:textfield name="name" value="%{#request.name}" ></s:textfield><BR>
    <s:label value="类别:"/><s:textfield name="type" value="%{#request.type}" /><BR>
    <s:label value="价格:"/><s:textfield name="price" value="%{#request.price}"/><BR>
   <s:label value="库存:"/><s:textfield name="stock" value="%{#request.stock}"/><BR>
   <s:submit value="提交"></s:submit>
    </s:form>
    <a href="display.jsp">返回</a>
  </body>
</html>
