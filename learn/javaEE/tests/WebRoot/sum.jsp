<%@ page language="java" import="java.util.*" pageEncoding="gb2312"%>

<html>
<body>
<% int sum=0;int n=100;
for(int i=1;i<=n;i++)
sum+=i;
out.println("java:"+sum); %>
<br>
html:<%=sum %>
</body>
</html>