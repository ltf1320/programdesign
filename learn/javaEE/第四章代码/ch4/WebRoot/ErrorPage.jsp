<%@ page contentType="text/html;charset=gb2312"%>
<%@ page import="java.io.*"%>
<%@ page isErrorPage="true" %>
<html>
<body bgcolor="#ffffc0">

<h1>Error page login</h1>

<br>An error occured in the bean. Error Message is: 
<%= exception.getMessage() %><br>
<%= exception.toString()%><br>
<%  //�������쳣����켣�Ĳ���
    //exception.printStackTrace();
    StringWriter sout = new StringWriter();
    PrintWriter pout = new PrintWriter(sout);
    exception.printStackTrace(pout);
%>
    <%--��ʾ�쳣�������Ϣ--%>
    <%= sout.toString() %>
</body>
</html>