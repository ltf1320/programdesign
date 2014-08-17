<%@page import="connect.HibernateSessionFactory"%>
<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<%@page import="org.hibernate.*" %>
<%@page import="connect.*" %>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
if(session.getAttribute("userName")==null)
{
	response.sendRedirect(basePath+"users/login.jsp");
}
Session ses=HibernateSessionFactory.getSession();
SQLQuery qu=ses.createSQLQuery("select * from message where userName=?").addEntity(Message.class);
qu.setString(0, (String)session.getAttribute("userName"));
List<Message> msglist=qu.list();
request.setAttribute("msglist", msglist);
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>My JSP 'manage.jsp' starting page</title>
    
	<meta http-equiv="pragma" content="no-cache">
	<meta http-equiv="cache-control" content="no-cache">
	<meta http-equiv="expires" content="0">    
	<meta http-equiv="keywords" content="keyword1,keyword2,keyword3">
	<meta http-equiv="description" content="This is my page">
	<link rel="stylesheet" type="text/css" href="<%=basePath %>ext-all.css">

  </head>
  
  <body>
     <%@include file="../template.jsp"%>
     <div class="manage">
     <div class="top">
     	<div class="msg"><s:label value="已发布的信息"></s:label>
     		<a style="color:#000079;font-size:20;font-weight:bold;" href="<%=basePath %>users/post.jsp">+</a>
     	</div>
     	<div class="info"><a href="<%=basePath%>users/info.jsp">个人信息修改</a></div>
     </div>
     <div class="msgs">
     <s:if test="#request.msglist==null||#request.msglist.size()==0">
     <div style="margin-left:50px;">
     	<s:label cssStyle="font-size:23;" value="你还没发布过消息!"></s:label>
     </div>
     	</s:if>
     	<s:else>
     		<%for(Message msg : msglist){ %>
     			<div style="border:1px solid #96c2f1;background:#eff7ff;width:30%;float:left;margin-left:1%;height:130px;margin-top:2px;">
     				<label><%=msg.getCl1() %></label>/<label><%=msg.getCl2() %></label>&nbsp;
     				<label><%=msg.getCreateTime().toString() %></label>&nbsp;&nbsp;
     				<a href="<%=basePath %>delete?id=<%=msg.getIdmessage()%>">删除</a>
     				<BR>
     				<label><%=msg.getTitle() %></label><BR>
     				<label><%=msg.getTime() %></label><BR>
     				<textarea readonly="readonly" rows="3" cols="50"><%=msg.getText() %></textarea><BR>
     				<label><%=msg.getOpt1() %></label>&nbsp;<label><%=msg.getOpt2() %></label>&nbsp;<label><%=msg.getOpt3() %></label>
     			</div>
     		<%} %>
     	</s:else>
     </div>
     </div>
  </body>
</html>
