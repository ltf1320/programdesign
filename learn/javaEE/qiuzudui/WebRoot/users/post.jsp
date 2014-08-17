<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<%

String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";

if(session.getAttribute("userName")==null)
{
	response.sendRedirect(basePath+"users/login.jsp");
}
%>
<%@ taglib uri="/struts-tags" prefix="s" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>My JSP 'post.jsp' starting page</title>
    
	<meta http-equiv="pragma" content="no-cache">
	<meta http-equiv="cache-control" content="no-cache">
	<meta http-equiv="expires" content="0">    
	<meta http-equiv="keywords" content="keyword1,keyword2,keyword3">
	<meta http-equiv="description" content="This is my page">

	<link rel="stylesheet" type="text/css" href="<%=basePath %>ext-all.css">


  </head>
  
  <body>
    <%@include file="../template.jsp"%>
    <div class="postbody">
    <div style="height:30px;width:100%;background-color:#0072E3;text-align:left;padding-top:10px;border:1px solid #00F;margin:auto;">
    	&nbsp;<s:label cssStyle="font-size:18;color:#FBFBFF;" value=" 发布新消息"></s:label>
    </div>
    <div style="width:100%;border:1px solid #00F;">
    <s:form action="post" method="post" theme="simple">
    	<div class="cls">
    	<s:set name="cls"   value="# {'学科竞赛':{'ACM-ICPC','数学建模','创新创业'},'电子竞技':{'英雄联盟','Dota'},'体育运动':{'游泳','羽毛球','篮球','足球'},'吃喝玩乐':{'美食','娱乐'},'社会活动':{'志愿者','公益活动'}}"/> 
    	<s:doubleselect name="cl1" theme="simple" doubleList="#cls[top]" list="#cls.keySet()" doubleName="cl2" label="类别"></s:doubleselect>
    	</div>
    		<div class="title">
    			<s:label value="标题:"/><s:textfield name="title"/>
    		</div>
    		<div class="title">
    			<s:label value="时间"/>
    			<s:textfield name="time"/>
    		</div>
    		<div class="text">
    			<s:label value="内容:"/><BR>
    			<s:textarea name="text"/>
    		</div>
    		<div class="bq">
    		<s:label value="标签"/>
    		<s:textfield name="opt1"/>
    		<s:textfield name="opt2"/>
    		<s:textfield name="opt3"/>
    		
    		</div>
    		<div class="submit">
    			<s:submit value="提交"/>
    		</div>
    </s:form>
    </div>
    </div>
  </body>
</html>
