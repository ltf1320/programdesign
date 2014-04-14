<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<%@page contentType="text/html;charset=UTF-8" %>
<%!Integer number=null;%>
<% 
out.println("欢迎！");
if(session.isNew()){

number=(Integer)application.getAttribute("countNum");
if(number==null){
	number=new Integer(1);
	application.setAttribute("countNum",number);
	}
else
{
number=new Integer(number.intValue()+1);
application.setAttribute("countNum",number)
;
}

}%>
<br>
<p>您是第<%=((Integer)application.getAttribute("countNum")).intValue()%>位访问本网站的用户</p><BR>
<p>您是第${countNum}位访问本网站的用户</p>