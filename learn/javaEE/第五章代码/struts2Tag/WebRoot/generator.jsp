<%-- 
    Document   : generator
    Created on : 2010-1-6, 16:00:38
    Author     : Administrator
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@ taglib prefix="s" uri="/struts-tags" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
"http://www.w3.org/TR/html4/loose.dtd">

<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>演示generator</title>
    </head>
    <body>
        <s:generator val="'aaa,bbb,ccc,ddd,eee'" separator=","  count="4" id="name">
         
        </s:generator>
        <% java.util.Iterator i = (java.util.Iterator) pageContext.getAttribute("name");
        while (i.hasNext()) {
            String s = (String) i.next();%>
        <%=s%> <br/>
        <% }
        %>
        

    </body>
</html>
