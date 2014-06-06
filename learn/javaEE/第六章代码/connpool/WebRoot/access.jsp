<%@ page contentType="text/html;charset=gb2312"%> 
<%@ page import="java.sql.*"%> 
<html> 
<body> 
<% 
String sitePath = request.getRealPath("/");  
System.out.println(sitePath);
  //获得web应用程序根目录的绝对，如E:\Tomcat 6.0\webapps\connpool\
//String dbPath = sitePath+"db1.mdb"; 
Class.forName("sun.jdbc.odbc.JdbcOdbcDriver"); 
//String url="jdbc:odbc:driver={Microsoft Access Driver (*.mdb)}; DBQ=d:\\db1.mdb"; 
//或
//String url="jdbc:odbc:driver={Microsoft Access Driver (*.mdb)}; DBQ="+dbPath; 
//或
String url="jdbc:odbc:mmm";

Connection conn= DriverManager.getConnection(url,"",""); 
Statement stmt=conn.createStatement(); 
String sql="select * from table1"; 
ResultSet rs=stmt.executeQuery(sql); 
while(rs.next()) {%> 
<%=rs.getString(1)%> 
<%=rs.getString(2)%>
<br /> 
<%}%> 
<%rs.close(); 
stmt.close(); 
conn.close(); 
%> 
</body> 
</html> 

