<%@ page language="java" import="java.util.*" pageEncoding="GB18030"%>


<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    
    <title>My JSP 'request.jsp' </title>

  </head>
  
  <body>
    <form action="" method="post">
    <input type="text" name="req"/>
    <input type="submit" value="�ύ">
    </form>
    ���󷽷���<%=request.getMethod() %><br>
    ����URL:<%=request.getRequestURI() %><br>
    �����Э�飺<%=request.getProtocol() %><br>
    ������ļ�����<%=request.getServletPath() %><br>
    ������IP:<%=request.getServerName() %><br>
 �������˿ڣ�<%=request.getServerPort() %><br>
  �ͻ���IP��ַ<%=request.getRemoteAddr() %><br>
  �ͻ���������<%=request.getRemoteHost() %><br>
  <%request.setCharacterEncoding("gb2312"); %><br>
  ��ñ��ύ��ֵ<%=request.getParameter("req") %><br>
  </body>
</html>
