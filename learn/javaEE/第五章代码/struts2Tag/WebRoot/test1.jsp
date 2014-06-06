<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@ taglib prefix="s" uri="/struts-tags" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
"http://www.w3.org/TR/html4/loose.dtd">

<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
        <s:if test="%{account=='aaa'}">
            <div>Will Not Be Executed</div>
        </s:if>
        <s:elseif test="%{true}">
            <div>Will Be Executed...</div>
        </s:elseif>
        <s:else>
            <div>Will Not Be Executed</div>
        </s:else>
       

    </body>
</html>
