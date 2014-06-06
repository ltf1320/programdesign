<%-- 
    Document   : compare
    Created on : 2010-1-6, 19:58:52
    Author     : Administrator
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@taglib prefix="s" uri="/struts-tags"%>
<html>
<head>
<title>演示使用sort标记</title>
</head>
<body>
<s:bean id="namecomparator" name="struts2.tag.NameComparator"/>
<table border="1" width="200">
<s:sort
source="{'Tom','Mary','Jack','Brunce'}"
comparator="#namecomparator">
<s:iterator status="st">
<tr>
   <td><s:property/></td>
</tr>
</s:iterator>
</s:sort>
</table>
</body>
</html>