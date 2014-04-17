<%@ page language="java" import="java.util.*" pageEncoding="GB18030"%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">

<%
	if(session.isNew())
		{
			Integer cnt=(Integer)this.getServletContext().getAttribute("webCnt");
			if(cnt==null)
				cnt=new Integer(0);
			cnt=cnt+1;
			this.getServletContext().setAttribute("webCnt", cnt);
		}
 %>

<html>	
  <head>
    
    <title>用户登录</title>
  </head>
  <body>
  	<p>欢迎访问</p><br>
  	您是第${webCnt}位访问本网站的用户<BR>
  	<form name="loginForm" method="post" action="servlet/CheckLogin">
  		用户名：<input type="text" name="userName"><BR/>
  		密码：&nbsp;
  		<input type="password" name="password"/><BR/>
  		<input type="submit" name="submit" value="登陆">
  		<a href="register.jsp">注册</a>
   	</form>
  </body>
</html>
