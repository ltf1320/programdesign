<%@ page contentType="text/html;charset=gb2312" %>
<html>
	<head>
		<title>test11.jsp </title>
	</head>
	<body>
    <% //request.setCharacterEncoding("gb2312"); //显示中文参数用%> 
	<jsp:include page="test11_1.jsp" flush="true" >
		<jsp:param name="User" value="王Wangfang" />
	</jsp:include> 
	</body>
</html>
