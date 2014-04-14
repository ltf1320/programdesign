<%@ page language="java" import="java.util.*" pageEncoding="GB18030"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>

<html>
<head>
<title>JSTLc</title>
</head>
<body>
	<c:out value="第一个JSTL网站"/>
	<br>
	你使用的浏览器是<BR>
	<c:out value="${header['User-Agent']}"/><br>
	<c:set var="user" value="Jack"/>
	<c:out value="JSTL!" escapeXml="true"/><br>
	
	<c:out value="&lt c:out未使用转义 &gt" escapeXml="true"/><br>
	<c:out value="&lt c:out使用转义 &gt" escapeXml="false"/><br>
	
	<c:set var="userName" value="Jeb" scope="page"/><br>
	${userName}
</body>
</html>