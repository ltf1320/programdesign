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
SQLQuery qu=ses.createSQLQuery("select * from Users where userName=?").addEntity(Users.class);
qu.setString(0, (String)session.getAttribute("userName"));
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
    
    <title>My JSP 'info.jsp' starting page</title>
    
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
    <div style="height:30px;width:100%;background-color:#0066CC;text-align:left;padding-top:10px;">
		&nbsp;<s:label cssStyle="font-size:18;color:#FBFBFF;" value="个人信息修改"></s:label>
    </div>
    <div style="background-color:#F1E1FF;padding-top:10px;">
    <s:form action="alter" method="post" theme="simple" >
    <s:fielderror cssStyle="color:red;"></s:fielderror>
    <table>
    <tr>
    	<td><s:label cssStyle="width:50px;text-align:center;" value="用户名"></s:label></td>
    	<td><s:textfield name="userName" value="%{#request.nUser.getUserName()}" cssStyle="height:40px;width:300px;font-size:16;"></s:textfield></td>
    </tr>
    <tr>
    	<td><s:label cssStyle="width:50px;text-align:center;" value="密码"></s:label></td>
    	<td><s:textfield name="pwd" value="%{#request.nUser.getPwd()}" cssStyle="height:40px;width:300px;margin-top:10px;"></s:textfield></td>
    </tr>
    <tr>
    	<td><s:label value="昵称"></s:label></td><td><s:textfield name="name" value="%{#request.nUser.getName()}" cssStyle="height:40px;width:300px;font-size:16;"></s:textfield></td>
    	</tr>
    	<tr>
    	<td><s:label value="学校"></s:label></td>
    	<td><s:select name="school" list="#request.scmp" selectedValue="<%=nUser.getSchool().getIdschool()%>" /></td> 
    	</tr>
    	<tr>
    	<td><s:label value="性别"></s:label></td><td><s:select name="sex" list="{'男','女' }" selectedValue="<%=nUser.getSex() %>"></s:select></td>
    	</tr>
    <tr>
    	<td><s:label value="qq"></s:label></td><td><s:textfield name="qq" value="%{#request.nUser.getQq()}" cssStyle="height:40px;width:300px;font-size:16;"></s:textfield></td>
    </tr>
    <tr><td><s:label value="email"></s:label></td><td><s:textfield name="email" value="%{#request.nUser.getEmail()}" cssStyle="height:40px;width:300px;font-size:16;"></s:textfield></td>
    </tr>
    <tr><td>
    	<s:label value="phone"></s:label></td><td><s:textfield name="phone" value="%{#request.nUser.getPhone()}" cssStyle="height:40px;width:300px;font-size:16;"></s:textfield></td>
    	</tr>
    	</table>
    	<s:submit value="修改	" cssStyle="height:40px;width:300px;margin-top:20px;background-color:#4400B3;color:#FFF;"></s:submit>
    	</s:form>
    </div>
    </div>
  </body>
</html>
