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
	 //��request.getParameter("hobby")ֻ��ȡ��һ��ֵ
	String intro=request.getParameter("intro");
	
	out.println("������"+user+"<br>");	
	out.println("�Ա�"+sex+"<br>");	
	out.println("���ã�");	
	if(hobby!=null){
		for(int i=0;i<hobby.length;i++){
			out.println(hobby[i]+"  ");
		}
	}
	out.println("<br>");	
	out.println("��飺"+intro+"<br>");
%>
</body>
</html>

