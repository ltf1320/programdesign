<%@ page language="java" import="java.util.*" pageEncoding="GB18030"%>


<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    
    <title>My JSP 'request.jsp' </title>

  </head>
  
  <body>
    <form action="" method="post">
    <input type="text" name="req"/>
    <input type="submit" value="提交">
    </form>
    请求方法：<%=request.getMethod() %><br>
    请求URL:<%=request.getRequestURI() %><br>
    请求的协议：<%=request.getProtocol() %><br>
    请求的文件名：<%=request.getServletPath() %><br>
    服务器IP:<%=request.getServerName() %><br>
 服务器端口：<%=request.getServerPort() %><br>
  客户端IP地址<%=request.getRemoteAddr() %><br>
  客户端主机名<%=request.getRemoteHost() %><br>
  <%request.setCharacterEncoding("gb2312"); %><br>
  获得表单提交的值<%=request.getParameter("req") %><br>
  </body>
</html>
