<%@ page contentType="text/html; charset=gb2312" language="java" errorPage="" %>
<%@ page import="java.util.List"%>
<%@ page import="org.model.TbUser"%>
<%@ page import="org.model.TbHibernateDao"%>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
<title>创建Hibernate实例</title>
</head>
<body>
<table  border="1" align="center" cellpadding="0" cellspacing="0">
  <tr align="center" height="25">
    <td width="100">用户名</td>
    <td width="100">性别</td>
    <td width="100">出生日期</td>
    <td width="100">职业</td> 
  </tr>
<%
TbHibernateDao dao=new TbHibernateDao();
List list=dao.selectManager();
for(int i=0;i<list.size();i++){
TbUser form=(TbUser)list.get(i);
%>
  <tr align="center" height="25">
    <td><%=form.getName()%></td>
    <td><%=form.getSex()%></td>
    <td><%=form.getBorn()%></td>
    <td><%=form.getProfession()%></td>
  </tr>
<%}%>
</table>
</body>
</html>
