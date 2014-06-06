<%@ page language="java" pageEncoding="gb2312"%>

<%@ page import="java.util.*"%>
<HTML>
	<%
		request.setCharacterEncoding("gb2312");//显示汉字
	%>
	<BODY>
		你好,
		<%!String Name;%>
		<%
			Name = request.getParameter("UserName");
		%>
		<%=Name%>, 今天是
		<%
			Date today = new Date();
		%>
		<%=today.getDate()%>号，星期<%=today.getDay()%>
	</BODY>
</HTML>

