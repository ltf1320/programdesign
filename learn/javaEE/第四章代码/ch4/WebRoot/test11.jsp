<%@ page contentType="text/html;charset=gb2312" %>
<html>
	<head>
		<title>test11.jsp </title>
	</head>
	<body>
    <% //request.setCharacterEncoding("gb2312"); //��ʾ���Ĳ�����%> 
	<jsp:include page="test11_1.jsp" flush="true" >
		<jsp:param name="User" value="��Wangfang" />
	</jsp:include> 
	</body>
</html>
