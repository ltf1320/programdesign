<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@taglib prefix="s" uri="/struts-tags"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
"http://www.w3.org/TR/html4/loose.dtd">

<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>演示push标签 </title>
    </head>
    <body>
    
        
         <s:bean name="struts2.tag.BookBean1"  id="mybook1">
            <s:param name="name" value="'Java EE 编程技术333333333'"/>
            <s:param name="price" value="29.56666"/>           
        </s:bean>
        <s:push value="#mybook1" >
            <s:property value="name"/><br>
            <s:property value="price"/>   
            <s:debug/>        
        </s:push> 
        
        
        
        <%--仅在push标签内，变量才位于valuestack的顶部 --%><br><br>
        <s:property value="#mybook.name"/><br>
        <s:property value="#mybook.price"/> 
        
        
    </body>