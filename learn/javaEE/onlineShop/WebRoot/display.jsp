<%@page import="connect.Sqlcon"%>
<%@ taglib prefix="s" uri="/struts-tags"%>
<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<%@ page import="java.sql.*"%>
<%@ page import="javax.sql.*"%>


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
    	String Id="123";
    	Connection con=null;
    	ResultSet rs=null;
    	try{
    	con=Sqlcon.getCon();
    	String sql="select * from goods where type=?";
    	PreparedStatement st=con.prepareStatement(sql);
    	st.setString(1,(String) session.getAttribute("searchStr"));
    	rs=st.executeQuery();
    	
    	while(rs.next())
    	{
    	  %>
    	 <tr align="center">
    	 	<td><%=rs.getString("Id")%></td>
	    <td><%=rs.getString("name")%></td>
	    <td><%=rs.getString("type")%></td>
	    <td><%=rs.getString("price")%></td>
	    <td><%=rs.getString("stock")%></td>
	    <td><a href="<%=path %>/update?Id=<%=rs.getString("Id") %>">修改</a>
	    <a href="<%=path %>/delete?Id=<%=rs.getString("Id") %>">删除</a></td>
	  </tr>
	  <%
	  }
	 }
	  	catch(Exception e)
	  	{
	  	e.printStackTrace();
	  	}
	  	finally
	  	{
	  	try{
			if(rs!=null) rs.close();
			if(con!=null) con.close();
		}catch(Exception e){}
		}
	   %>
    	 </table>

    	 
    	 <a href="index.jsp">返回</a>
  </body>
</html>


