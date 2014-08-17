 <%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<%@ taglib uri="/struts-tags" prefix="s" %>
<%-- <% --%>
<%-- String path = request.getContextPath(); --%>
<%-- String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/"; --%>
<%-- %> --%>

<%-- <!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"> --%>
<%-- <html> --%>
<%--   <head> --%>
<%--     <base href="<%=basePath%>"> --%>
    
<%--     <title>My JSP 'template.jsp' starting page</title> --%>
    
<%-- 	<meta http-equiv="pragma" content="no-cache"> --%>
<%-- 	<meta http-equiv="cache-control" content="no-cache"> --%>
<%-- 	<meta http-equiv="expires" content="0">     --%>
<%-- 	<meta http-equiv="keywords" content="keyword1,keyword2,keyword3"> --%>
<%-- 	<meta http-equiv="description" content="This is my page"> --%>
	
<%-- 	<link rel="stylesheet" type="text/css" href="<%=basePath %>ext-all.css"> --%>
<%--   </head> --%>
  
<%--   <body> --%>
  <div class="template">
  	<div class="topbody">
  		<div class="logo">
  			<a title="求组队" href="<%=basePath %>"><img src="<%=basePath%>img/logo.png"></a>
  		</div>
  		<div class="search">
  			<s:form action="/search" method="post" theme="simple">
  			<s:textfield name="keyword" cssStyle="width:400px;height:40px;"></s:textfield>
  			<s:submit class="inputbtn" cssStyle="width:64px;height:40px;font-size:18;color:#4400B3;bro" value="搜索"></s:submit>
  			</s:form>
  		</div>
  		
  		<s:if test="null==#session.userName||#session.userName.isEmpty()">
  		<div class="userPannal">
  			<a href="users/login.jsp"><img src="<%=basePath%>img/login.png"></a>
  			<a href="users/register.jsp"><img src="<%=basePath%>img/register.png"></a>
  		</div>
  		</s:if>
  		<s:else>
  			<div class="userPannal2">
  			<a style="font-size:18;color:#4400FF;" href="users/manage.jsp">${userName}</a>
  			<a style="font-size:18;color:#4400FF;" href="<%=basePath %>logout">退出登陆</a>
  			</div>
  		</s:else>
  		
  	</div>
    
    <div class="nav">
    	<div class="cls">
    		<ul class="list">
    			<li>
    				<a href="<%=basePath %>">首页</a>
    			</li>
    			<li>
    				<a href="<%=basePath %>cl/contests.jsp">学科竞赛</a>
    			</li>
    			<li>
    				<a href="<%=basePath %>cl/e-sports.jsp">电子竞技</a>
    			</li>
    			<li>
    				<a href="<%=basePath %>cl/sports.jsp">体育运动</a>
    			</li>
    			<li>
    				<a href="<%=basePath %>cl/plays.jsp">吃喝玩乐</a>
    			</li>
    			<li>
    				<a href="<%=basePath %>cl/activities.jsp">社会活动</a>
    			</li>
    		</ul>
    	</div>
    </div>
   </div>
<!--   </body> -->
<!-- </html> -->
