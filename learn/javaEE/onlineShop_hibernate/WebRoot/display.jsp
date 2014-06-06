
<%@page import="connect.HibernateSessionFactory"%>
<%@ taglib prefix="s" uri="/struts-tags"%>
<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<%@ page import="java.sql.*"%>
<%@ page import="javax.sql.*"%>
<%@ page import="javax.naming.*"%>
<%@ page import="javax.persistence.Entity" %>
<%@ page import="org.hibernate.*" %>


<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <title>My JSP 'display.jsp' starting page</title>
    
	<meta http-equiv="pragma" content="no-cache">
	<meta http-equiv="cache-control" content="no-cache">
	<meta http-equiv="expires" content="0">    
	<meta http-equiv="keywords" content="keyword1,keyword2,keyword3">
	<meta http-equiv="description" content="This is my page">
	<!--
	<link rel="stylesheet" type="text/css" href="styles.css">
	-->

  </head>
  
  <body>
  	关于<s:property value="searchStr"/>的搜索结果
  	   <table>
  	   <tr align="center">
	    <td><span class="style1">Id</span></td>
	    <td><span class="style1">商品名</span></td>
	    <td><span class="style1">类型</span></td>
	    <td><span class="style1">价格</span></td>
	    <td><span class="style1">库存</span></td>
	    <td><span class="style1">操作</span></td>
	    </tr>
    	<%
    		Session s=HibernateSessionFactory.getSession();
    	    	String Id="123";
    	    	try{
    	    	Transaction tr=s.beginTransaction();
    	    	SQLQuery qu=s.createSQLQuery("select * from Goods where type=?").addEntity(connect.Goods.class);
    	    	qu.setString(0, (String) session.getAttribute("searchStr"));
    	    	List<connect.Goods> gdlist= (List<connect.Goods>)qu.list();
    	    	for(connect.Goods gd:gdlist)
    	    	{
    	%>
    	 <tr align="center">
    	 	<td><%=gd.getId()%></td>
	    <td><%=gd.getName()%></td>
	    <td><%=gd.getType()%></td>
	    <td><%=gd.getPrice()%></td>
	    <td><%=gd.getStock()%></td>
	    <td><a href="<%=path %>/update?Id=<%=gd.getId() %>">修改</a>
	    <a href="<%=path %>/delete?Id=<%=gd.getId() %>">删除</a></td>
	  </tr>
	  <%}
	  tr.commit();
	  	}catch(Exception e)
	  	{
	  	e.printStackTrace();
	  	}
	  	finally
	  	{
	  	try{
			s.close();
		}catch(Exception e){e.printStackTrace();}
		}
	   %>
    	 
    	 </table>
    	 
    	 <a href="index.jsp">返回</a>
  </body>
</html>
