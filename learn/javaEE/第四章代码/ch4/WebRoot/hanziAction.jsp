<%@page contentType="text/html;charset=gb2312"%>
<html>
	<head>
		<title>���к��ֵĴ���</title>
	</head>
	<%request.setCharacterEncoding("gb2312");%>
	<body>
		<%
        String name=request.getParameter("name");
        //name=new String(name.getBytes("ISO8859_1"),"gb2312");
	    out.println("�û�����" +name+"<br>");
      %>
	</body>
</html>