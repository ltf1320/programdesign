<%@ page contentType="text/html;charset=gb2312" %>
<html>
	<head>
		<title>test</title>
	</head>
    <% request.setCharacterEncoding("gb2312"); 
       //�ô�����ҳ�����Ĳ�����ʾ������������ʱ�������루һ������һ���ʺţ��ύ���������ʺţ�
       //ֻ�ڸ�ҳ�����ü��ɣ�forwardTo.jspҳ�治������
    %>
	<body>
		<jsp:forward page="forwardTo.jsp">
			<jsp:param name="userName" value="����zhang"/>
		</jsp:forward>
	</body>
</html>

