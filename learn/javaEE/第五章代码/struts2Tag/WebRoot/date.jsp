<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@ taglib prefix="s" uri="/struts-tags"%>
<html>
	<head>
		<title>date Tag 演示</title>
	</head>
	<body>
		<div id="global" style="width: 350px">
			<s:bean name="java.util.Date" id="today" />
			今天 (原始格式):
			<s:property value="#today" />
			<s:date name="#today" id="format1" format="yyyy-MM-dd" />
			<br />
			今天 (yyyy-MM-dd):
			<s:property value="#format1" />

		</div>
	</body>
</html>