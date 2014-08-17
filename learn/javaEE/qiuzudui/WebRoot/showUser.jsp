<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<%@page import="org.hibernate.*" %>
<%@page import="connect.*" %>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
Session ses=HibernateSessionFactory.getSession();
SQLQuery qu=ses.createSQLQuery("select * from Users where userName=?").addEntity(Users.class);
qu.setString(0, (String)request.getParameter("userName"));
Users nUser=(Users)qu.uniqueResult();
request.setAttribute("nUser", nUser);

qu=ses.createSQLQuery("select * from school").addEntity(School.class);
List<School> sclist=(List<School>)qu.list();
Map<String,String> mp=new LinkedHashMap<String,String>();
for(School sc : sclist)
{
	mp.put(sc.getIdschool().toString(), sc.getName());
}
request.setAttribute("scmp", mp);
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>My JSP 'showUser.jsp' starting page</title>
    
	<meta http-equiv="pragma" content="no-cache">
	<meta http-equiv="cache-control" content="no-cache">
	<meta http-equiv="expires" content="0">    
	<meta http-equiv="keywords" content="keyword1,keyword2,keyword3">
	<meta http-equiv="description" content="This is my page">
	<link rel="stylesheet" type="text/css" href="<%=basePath %>ext-all.css">

  </head>
  
  <body>
  	<%@include file="../template.jsp" %>
    <div class="register">
    <div style="height:50px;width:100%;background-color:#00DD00;text-align:left;padding-top:10px;">
		<s:label cssStyle="" value="个人信息查看"></s:label>
    </div>
    <s:if test="#request.nUser==null">
    	<div style="margin-top:30px;margin-left:20px;">
    	<label style="font-size:20">未找到此用户的信息</label>
    	</div>
    	</s:if>
    	<s:else>
    <div style="background-color:#66FF66;padding-top:10px;text-align:left;'">
    <s:fielderror cssStyle="color:red;"></s:fielderror>
    <div>
    <s:label readonly="true" name="userName" value="%{#request.nUser.getUserName()}" cssStyle="height:40px;width:300px;font-size:16;"></s:label>
    	&nbsp;&nbsp;
    	<s:property value="#request.nUser.school.name"/>
    	<s:property value="#request.nUser.sex"/>
    	</div>
    <div>
    	<s:label value="qq"></s:label><s:label readonly="true" name="qq" value="%{#request.nUser.getQq()}" cssStyle="height:40px;width:300px;font-size:16;"></s:label>
    </div>
    <div>
    <s:label value="email"></s:label><s:label  readonly="true" name="email" value="%{#request.nUser.getEmail()}" cssStyle="height:40px;width:300px;font-size:16;"></s:label>
    </div>
    <div>
    	<s:label value="phone"></s:label><s:label readonly="true" name="phone" value="%{#request.nUser.getPhone()}" cssStyle="height:40px;width:300px;font-size:16;"></s:label>
    </div>
    </div>
    </s:else>
    </div>
  </body>
</html>
