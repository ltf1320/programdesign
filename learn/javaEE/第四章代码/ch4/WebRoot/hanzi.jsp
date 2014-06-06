<%@ page contentType="text/html;charset=gb2312"%>
<html>
	<head>
		<title>表单处理的汉字问题</title>
	</head>
	<body>
		<form method="post" name="frm1" action="hanziAction.jsp">
			<p align="center">用户登录</P>
				<p align="center">用户名：
				<input type="text" name="name" size="20">
				<input type="submit" value=" 提交">
			</p>
			<a href="link.jsp?uname=张三">跳转(get请求)</a>
		</form>
	</body>
</html>