<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@taglib prefix="s" uri="/struts-tags"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
"http://www.w3.org/TR/html4/loose.dtd">

<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>演示bean标签 </title>
    </head>
    <body>
        <s:bean name="struts2.tag.BookBean" id="mybook">
            <s:param name="name" value="'Java EE 编程技术'"/>
            <s:param name="price" value="29.5"/>           
        </s:bean>
            <s:property value="#mybook.name"/><br>
            <s:property value="#mybook.price"/>
            
    </body>
</html>