<%@ page language="java" import="common.*"  import="java.sql.*" pageEncoding="GBK"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>My JSP 'login.jsp' starting page</title>
    
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
    <%
      //获取连接
      Connection con=new Conn().connection();
      Statement st=null;
      ResultSet rs=null;
      if(con!=null){      
	try{
	     st=con.createStatement();
	     rs=st.executeQuery("select * from authors");
     %>
	
	<table width="220" border="1">
	  <tr align="center">
	    <td><span class="style1">姓名</span></td>
	    <td><span class="style1">地址</span></td>
	    <td><span class="style1">城市</span></td>
	  </tr>
	<%
	  while(rs.next()){
	%>
	  <tr align="center">
	    <td><%=rs.getString("au_lname")%></td>
	    <td><%=rs.getString("address")%></td>
	    <td><%=rs.getString("city")%></td>
	  </tr>
	<%}%>
	</table>
	<%
	  }catch(Exception e){
	    e.printStackTrace();
	  }finally{//关闭结果集、连接 
		try{
			if(rs!=null) rs.close();
			if(st!=null) st.close();
			con.close();
		}catch(Exception e){}
	  }
	 }//end if
	%>
   
  </body>
</html>
