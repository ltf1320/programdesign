<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<%@ taglib prefix="s" uri="/struts-tags"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>

    <title>My JSP 'newgoods.jsp' starting page</title>
    
	<meta http-equiv="pragma" content="no-cache">
	<meta http-equiv="cache-control" content="no-cache">
	<meta http-equiv="expires" content="0">    
	<meta http-equiv="keywords" content="keyword1,keyword2,keyword3">
	<meta http-equiv="description" content="This is my page">

  </head>
  
  <body>
    <s:form action="/new" method="post">
    <s:label value="Id"/><s:textfield name="Id"></s:textfield>
    <BR>
   <s:label value=" 商品名:"/><s:textfield name="name"></s:textfield><BR>
    <s:label value="类别:"/><s:textfield name="type"/><BR>
    <s:label value="价格:"/><s:textfield name="price"/><BR>
   <s:label value=" 库存:"/><s:textfield name="stock"/><BR>
    <s:submit value="添加"/>
    </s:form>
    <a href="index.jsp">返回</a>
  </body>
</html>
