<%@ page contentType="text/html;charset=gb2312"%>
<html>
<head><title>test</title></head>
<body>
<%
	request.setCharacterEncoding("gb2312");
%>
<%
	String user=request.getParameter("user");	
	String sex=request.getParameter("sex");
	String[] hobby=request.getParameterValues("hobby");
	 //用request.getParameter("hobby")只能取出一个值
	String intro=request.getParameter("intro");
	
	out.println("姓名："+user+"<br>");	
	out.println("性别："+sex+"<br>");	
	out.println("爱好：");	
	if(hobby!=null){
		for(int i=0;i<hobby.length;i++){
			out.println(hobby[i]+"  ");
		}
	}
	out.println("<br>");	
	out.println("简介："+intro+"<br>");
%>
</body>
</html>

