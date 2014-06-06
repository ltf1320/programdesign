<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@taglib prefix="s" uri="/struts-tags"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
   "http://www.w3.org/TR/html4/loose.dtd">

<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>演示Action标签</title>
    </head>
    <body>
        这是调用页面本身的部分<br>
        <s:action name="actiontest" ignoreContextParams="false" executeResult="true"></s:action>
        <%--executeResult：该属性是可选的，指定是否要将Action的处理结果页面包含到本页面,默认为false 
            ignoreContextParam：该属性是可选的，指定该页面中的请求参数是否需要传入调用的Action,默认为false
               ignoreContextParams="true"
        --%>
    </body>
</html>
