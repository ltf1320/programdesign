<%@ page contentType="text/html;charset=gb2312"%>
<html>
	<head>
		<title>ȷ��JSP</title>
	</head>
	<body>
	  <%
		String name = request.getParameter("name");
	    //ǰҳ�ؼ��в������κ�ֵ�ύʱ���˴�request�õ���ֵΪ""(�մ�)
		String pwd = request.getParameter("pwd");
		if ((name != null) && (!name.equals(""))) {
		 //����ȥ��&&���������������name�������κ�ֵ�ύʱ��
		 //��������ʾ�û��������룬���û���Ϊ�հף���"" 
		 name = new String(name.getBytes("ISO8859_1"), "gb2312");
		 out.println("�û�����" + name + "<br>");
		 out.println("���룺" + pwd + "<br>");
		} else {
		%>
		<p align="center">
			�û�������Ϊ��
		</p>
		<br>
		<br>
		<form method="post" name="frm1" action="test17_loginAction.jsp">
			<p align="center">�û���¼</p>
			<p align="center">
			�û�����
			<input type="text" name="name" size="20"/>
			&nbsp;&nbsp;&nbsp;&nbsp; ���룺
			<input type="password" name="pwd" size="20"/>
			<br><br>
			<input type="submit" value=" �ύ">
			<input type="reset" value="ȫ����д">
			</p>
		</form>
		<%
		}
		%>
	</body>
</html>