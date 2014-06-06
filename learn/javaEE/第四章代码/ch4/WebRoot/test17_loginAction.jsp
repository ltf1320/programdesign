<%@ page contentType="text/html;charset=gb2312"%>
<html>
	<head>
		<title>确认JSP</title>
	</head>
	<body>
	  <%
		String name = request.getParameter("name");
	    //前页控件中不输入任何值提交时，此处request得到的值为""(空串)
		String pwd = request.getParameter("pwd");
		if ((name != null) && (!name.equals(""))) {
		 //不能去掉&&后面的条件，否则name不输入任何值提交时，
		 //仍正常显示用户名、密码，但用户名为空白，即"" 
		 name = new String(name.getBytes("ISO8859_1"), "gb2312");
		 out.println("用户名：" + name + "<br>");
		 out.println("密码：" + pwd + "<br>");
		} else {
		%>
		<p align="center">
			用户名不能为空
		</p>
		<br>
		<br>
		<form method="post" name="frm1" action="test17_loginAction.jsp">
			<p align="center">用户登录</p>
			<p align="center">
			用户名：
			<input type="text" name="name" size="20"/>
			&nbsp;&nbsp;&nbsp;&nbsp; 密码：
			<input type="password" name="pwd" size="20"/>
			<br><br>
			<input type="submit" value=" 提交">
			<input type="reset" value="全部重写">
			</p>
		</form>
		<%
		}
		%>
	</body>
</html>