<%@ page language="java" contentType="text/html;charset=gb2312"%>
<%@ taglib prefix="s" uri="/struts-tags"%>
<html>
	<head>
		<title>�ֶ�У������</title>
	</head>
	<body>		
			<h4>
				�����ϵ��
			</h4>
		
		   <s:form action="addUser" method="post">
				<s:textfield name="userName" label="��ϵ������"></s:textfield>								
				<s:textfield name="userTelephone" label="��ϵ�˵绰"></s:textfield>				
				<s:textfield name="userAddress" label="��ϵ�˵�ַ"></s:textfield>				
				<s:submit value="�ύ" />
			</s:form>
			
			<!--  
			<s:form action="addUser" method="post"  theme="simple">
				<s:textfield name="userName" label="��ϵ������"></s:textfield>
					<s:fielderror cssStyle="color:red">
	                   <s:param>userName</s:param>
					</s:fielderror>
					<br>				
				<s:textfield name="userTelephone" label="��ϵ�˵绰"></s:textfield>
					<s:fielderror cssStyle="color:red">
	                   <s:param>userTelephone</s:param>
					</s:fielderror>
					<br>
				<s:textfield name="userAddress" label="��ϵ�˵�ַ"></s:textfield>
					<s:fielderror cssStyle="color:red">
	                   <s:param>userAddress</s:param>
					</s:fielderror>
					<br>
				<s:submit value="�ύ" />
			</s:form>
		   -->
	</body>
</html>