<%@ page contentType="text/html; charset=GBK" language="java" errorPage="" %>
<%@taglib prefix="s" uri="/struts-tags"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
	"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
	<title>使用s:itertor标签迭代List</title>
</head>
<body>
<table border="1" width="300">
<s:iterator value="{'疯狂Java讲义',
	'轻量级Java EE企业应用实战',
	'经典Java EE企业应用实战'}"
	id="name">	
	<tr>
		<td><s:property value="name"/></td>
	</tr>
</s:iterator>

</table>
</body>
</html>
