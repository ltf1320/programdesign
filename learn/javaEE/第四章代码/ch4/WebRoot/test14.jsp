<%@ page contentType="text/html;charset=gb2312"%>
<html>
	<head>
		<title>application</title>
	</head>
	<body>
	<%
		out.println("Java Servlet API Version "
				+ application.getMajorVersion() + "."
				+ application.getMinorVersion() + "<br>");
		out.println(" aa.doc's MIME type is:"
				+ application.getMimeType("aa.doc") + "<br>");
		out.println("URL of 'tes14.jsp' is: "
				+ application.getResource("/test14.jsp") + "<br>");
		out.println("getServerInfo()=" + application.getServerInfo()
				+ "<br>");
		out.println(application.getRealPath(""));
		application.log("Add a Record to log_file"); //E:\Tomcat6.0\logsÏÂ
	%>
	</body>
</html>
