<%@ page language="java" import="java.util.*" pageEncoding="gb2312"%>

<html>
<body>
<head><title>你好！</title></head>
<html>
<body>

<jsp:include page="apb.jsp">
<jsp:param value="1" name="a"/>
<jsp:param value="2" name="b"/>
</jsp:include>

现在的时间是：
<%@ include file="date.jsp" %>
</body></html>
</body>
</html>