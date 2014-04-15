<%@ page language="java" import="java.util.*" pageEncoding="GB18030"%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">

<html>
  <head>
    
    <title>用户登录</title>
  </head>
  <p>欢迎访问</p>
  <body>
  	<form name="loginForm" method="post" action="servlet/CheckLogin">
  		用户名：<input type="text" name="userName"><BR/>
  		密码：&nbsp;
  		<input type="password" name="password"/><BR/>
  		<input type="submit" name="submit" value="登陆">
  		<a href="register.jsp">注册</a>
   	</form>
  </body>
</html>
