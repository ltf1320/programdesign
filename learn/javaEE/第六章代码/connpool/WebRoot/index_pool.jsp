<%@ page contentType="text/html; charset=gb2312" language="java"  errorPage="" %>
<%@ page import="java.sql.*"%>
<%@ page import="javax.sql.*"%>
<%@ page import="javax.naming.*"%>
	<html>
	<head>
	<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
	<title>ͨ��Tomcat���ӳ�����SQL Server���ݿ�</title>
	<style type="text/css">
	<!--
	.style1 {color: #0000FF}
	-->
	</style>
	</head>
	
	<body>
	<%
	System.out.println("*******");
	%>
	<div align="center">
	<span class="style1">
	<%
	System.out.println("*******");
	DataSource ds = null;
	Connection conn=null;
	Statement stmt=null;
	ResultSet rs=null;
	
	try{
		InitialContext ctx=new InitialContext();//׼��JNDI�ķ��ʻ���
		ds=(DataSource)ctx.lookup("java:comp/env/jdbc/connectionPool");//jdbc/connectionPoolΪ���ӳ���
		  //java:comp/env�ǻ������������ģ�environment naming context��
		  //JDBC����Դ������java:comp/env/jdbc��������������
		conn = ds.getConnection();		
	}
	catch(Exception e){
		e.printStackTrace();
	}
	%>
	<%if(conn!=null){
	try{
		stmt=conn.createStatement();
		rs=stmt.executeQuery("select * from authors");
	%>
	ȡ�����ݿ����ӳɹ�������</span>
	<table width="220" border="1">
	  <tr align="center">
	    <td><span class="style1">����</span></td>
	    <td><span class="style1">��ַ</span></td>
	    <td><span class="style1">����</span></td>
	  </tr>
	  <%while(rs.next()){
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
	}finally{//�رս���������� 
		try{
			if(rs!=null) rs.close();
			conn.close();
			System.out.println("�ر�����^^^^");
		}catch(Exception e){}
	}
	
	%>
	<%}%>
    </div>
	</body>
	</html>
