<%-- 
    Document   : g3
    Created on : 2010-4-1, 23:08:55
    Author     : Administrator
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@ taglib prefix="s" uri="/struts-tags" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
"http://www.w3.org/TR/html4/loose.dtd">

<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>演示利用Generator生成非String集合</title>
    </head>
    <body>
  <s:generator val="'1:正常,2:注销,3:未审核'" separator="," converter="myConverter" id="map1" />
  <s:select list="map1" />
  <s:debug/>


    </body>
</html>