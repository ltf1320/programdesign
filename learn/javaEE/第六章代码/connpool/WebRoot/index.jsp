<%@ page language="java" import="java.sql.*" import="java.util.*" pageEncoding="GB2312"%>

   <%
	Connection con = null;
	
	try {
		Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
		//SQL Server�����֤
		String URL = "jdbc:sqlserver://localhost:1433;DatabaseName=pubs";
		String user = "sa";
		String password = "123";
		con = DriverManager.getConnection(URL, user, password);
		
		//Windows�����֤
		//String URL = "jdbc:sqlserver://localhost:1433;IntegratedSecurity=true;DatabaseName=pubs";
		//con = DriverManager.getConnection(URL);
		System.out.println("3333333333");
	} catch (ClassNotFoundException e) {
		e.printStackTrace();
	}
          %>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>        
    <title>ͨ��JDBC����SQL Server���ݿ�</title> 
</head>
  
  <body>
   <%
	if (con != null) {
		out.println("���ݿ����ӳɹ���");
	} else {
		out.println("���ݿ�����ʧ�ܣ�");
	}
   %>
       <br>
   <%
	String SQL = "Select * From authors";
	Statement smt = null;
	ResultSet rs = null;
	try {
	  smt = con.createStatement();
	  rs = smt.executeQuery(SQL);
    %>
    <table width="413" border="0" cellspacing="0" cellpadding="0">
	<tr>
	<td width="86">		
			����	
	</td>
	<td width="80">		
			��ַ	
	</td>
	<td width="82">		
			����	
	</td>
	</tr>
	<%
	    for (int i = 0; i < 10; i++) {
	       rs.next();
	%>
	<tr>
		<td>		
			<%=rs.getString("au_lname")%>		
		</td>
		<td>		
			<%=rs.getString("address")%>	
		</td>
		<td>		
			<%=rs.getString("city")%>	
		</td>

	</tr>
	<%
		}//end for
		} catch (Exception e) {
			e.printStackTrace();
		} finally {//�رս���������� 
			try {
				if (rs != null)
			rs.close();
				if (smt != null)
			smt.close();
				con.close();
			} catch (Exception e) {
			}
		}
	%>
		</table>
  </body>
</html>
