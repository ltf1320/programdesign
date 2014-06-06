<%@page contentType="text/html;charset=gb2312"%>
<html>
	<head>
		<title>表单中汉字的处理</title>
	</head>
	<%request.setCharacterEncoding("gb2312");%>
	<body>
		<%
        String name=request.getParameter("name");
        //name=new String(name.getBytes("ISO8859_1"),"gb2312");
	    out.println("用户名：" +name+"<br>");
      %>
	</body>
</html>