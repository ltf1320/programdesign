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
        <s:bean name="struts2.tag.BookBean" >
            <s:param name="name" value="'Java EE 编程技术'"/>
            <s:param name="price" value="29.5"/>
            <s:property value="name"/><br>
            <s:property value="price"/>
           <s:debug/>   
        </s:bean>
        <%--定义的bean只在标签体范围内有效， 若在外部引用，需加id属性--%>

    </body>
</html>
