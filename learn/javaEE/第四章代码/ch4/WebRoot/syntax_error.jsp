<%@ page contentType="text/html;charset=gb2312" %>
<%--导入JAVA的util包，使用包中的Calendar类；错误连接到exception.jsp--%>
<%@ page import="java.util.*"  errorPage="ErrorPage.jsp"%>
<%
Calendar rightNow=null ;//将rightNow设空
rightNow.getTime(); //此行代码会抛出空指针异常
%>
