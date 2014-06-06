<%@ page language="java" contentType="text/html;charset=gb2312"%>
<%@ taglib prefix="s" uri="/struts-tags"%>
<html>
	<head>
		<title>手动校验数据</title>
	</head>
	<body>		
			<h4>
				添加联系人
			</h4>
		
		   <s:form action="addUser" method="post">
				<s:textfield name="userName" label="联系人姓名"></s:textfield>								
				<s:textfield name="userTelephone" label="联系人电话"></s:textfield>				
				<s:textfield name="userAddress" label="联系人地址"></s:textfield>				
				<s:submit value="提交" />
			</s:form>
			
			<!--  
			<s:form action="addUser" method="post"  theme="simple">
				<s:textfield name="userName" label="联系人姓名"></s:textfield>
					<s:fielderror cssStyle="color:red">
	                   <s:param>userName</s:param>
					</s:fielderror>
					<br>				
				<s:textfield name="userTelephone" label="联系人电话"></s:textfield>
					<s:fielderror cssStyle="color:red">
	                   <s:param>userTelephone</s:param>
					</s:fielderror>
					<br>
				<s:textfield name="userAddress" label="联系人地址"></s:textfield>
					<s:fielderror cssStyle="color:red">
	                   <s:param>userAddress</s:param>
					</s:fielderror>
					<br>
				<s:submit value="提交" />
			</s:form>
		   -->
	</body>
</html>