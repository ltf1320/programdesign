<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@ taglib prefix="s" uri="/struts-tags"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
"http://www.w3.org/TR/html4/loose.dtd">

<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
		<title>iterator标签示例</title>
	</head>
	<body>
	  <table border="0" cellspacing="0" cellpadding="1">
	    <s:iterator value="{'北京','上海','广州'}" id="name" status="st">		
		  <tr>
		    <s:if test="#st.Even">
			  <td style="background:red">
				<s:property value="#st.index" />
				<s:property value="#name" />				
			  </td>
			</s:if>
			<s:else>
			  <td style="background:lightgreen">
				<s:property value="#st.index" />
				<s:property value="#name" />				
			  </td>
			</s:else>
		  </tr>
		</s:iterator>
				 
	  </table>
	</body>
</html>
