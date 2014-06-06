<%@ page contentType="text/html;charset=gb2312" %>
<html>
	<head>
		<title>test</title>
	</head>
    <% request.setCharacterEncoding("gb2312"); 
       //让传到下页的中文参数显示正常，不设置时出现乱码（一个汉字一个问号，提交乱码两个问号）
       //只在该页面设置即可，forwardTo.jsp页面不用设置
    %>
	<body>
		<jsp:forward page="forwardTo.jsp">
			<jsp:param name="userName" value="张扎zhang"/>
		</jsp:forward>
	</body>
</html>

