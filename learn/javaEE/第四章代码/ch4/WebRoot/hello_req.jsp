<%@ page language="java" pageEncoding="gb2312"%>

<%@ page import="java.util.*"%>
<HTML>
	<%
		request.setCharacterEncoding("gb2312");//��ʾ����
	%>
	<BODY>
		���,
		<%!String Name;%>
		<%
			Name = request.getParameter("UserName");
		%>
		<%=Name%>, ������
		<%
			Date today = new Date();
		%>
		<%=today.getDate()%>�ţ�����<%=today.getDay()%>
	</BODY>
</HTML>

