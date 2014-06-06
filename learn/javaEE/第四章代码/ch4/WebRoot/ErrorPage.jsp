<%@ page contentType="text/html;charset=gb2312"%>
<%@ page import="java.io.*"%>
<%@ page isErrorPage="true" %>
<html>
<body bgcolor="#ffffc0">

<h1>Error page login</h1>

<br>An error occured in the bean. Error Message is: 
<%= exception.getMessage() %><br>
<%= exception.toString()%><br>
<%  //以下是异常错误轨迹的捕获
    //exception.printStackTrace();
    StringWriter sout = new StringWriter();
    PrintWriter pout = new PrintWriter(sout);
    exception.printStackTrace(pout);
%>
    <%--显示异常的相关信息--%>
    <%= sout.toString() %>
</body>
</html>