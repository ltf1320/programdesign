<%@ page contentType="text/html; charset=GBK" language="java" errorPage="" %>
<%@taglib prefix="s" uri="/struts-tags"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
	"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
	<title>s:if��ǩ����</title>
</head>
<body>
<!-- ��Stack Context�ж���һ��age���ԣ���ֵΪ29 -->
<s:set name="age" value="29"/>
<s:debug/>
<s:if test="#age>60">
	������
</s:if>
<s:elseif test="#age>35">
	������
</s:elseif>
<s:elseif test="#age>15">
	������
</s:elseif>
<s:else>
	����
</s:else>

</body>
</html>
