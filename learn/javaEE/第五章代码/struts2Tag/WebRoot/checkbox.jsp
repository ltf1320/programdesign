<%-- 
    Document   : checkbox
    Created on : 2010-1-7, 10:28:36
    Author     : Administrator
--%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@ taglib prefix="s" uri="/struts-tags" %>
<html>
<head>
<title>checkbox 标记演示</title>
<style type="text/css">@import url(css/main.css);</style>
</head>
<body>
<div id="global" style="width:300px">
	<h3>喜欢吃的水果</h3>
    <s:form action="CheckBox" method="Post">
        <s:checkbox name="apple" label="苹果"/>
		<s:checkbox name="orange" label="桔子"/>
        <s:checkbox name="peach" label="梨子" fieldValue="true"
		    disabled="true"
		/>
        <s:submit value="提交"/>

	</s:form>
</div>
</body>
</html>