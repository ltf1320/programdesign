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
    
    <title>�û���¼</title>
  </head>
  <body>
  	<p>��ӭ����</p><br>
  	���ǵ�${webCnt}λ���ʱ���վ���û�<BR>
  	<form name="loginForm" method="post" action="servlet/CheckLogin">
  		�û�����<input type="text" name="userName"><BR/>
  		���룺&nbsp;
  		<input type="password" name="password"/><BR/>
  		<input type="submit" name="submit" value="��½">
  		<a href="register.jsp">ע��</a>
   	</form>
  </body>
</html>
