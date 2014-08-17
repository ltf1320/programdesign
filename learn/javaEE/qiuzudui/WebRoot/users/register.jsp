<%@page import="connect.HibernateSessionFactory"%>
<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<%@ page import="connect.*" %>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";

org.hibernate.Session ses=HibernateSessionFactory.getSession();
org.hibernate.SQLQuery qu=ses.createSQLQuery("select * from school").addEntity(School.class);
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
    
    <title>My JSP 'register.jsp' starting page</title>
    
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
    <div style="height:50px;width:100%;background-color:#F1E1FF;text-align:left;padding-top:10px;">
    	<img src="<%=basePath %>/img/register.png">
    </div>
    <div style="background-color:#F1E1FF;padding-top:10px;">
    <s:form action="register" method="post" theme="simple" >
    <s:fielderror cssStyle="color:red;"></s:fielderror>
    <table>
    <tr>
    	<td><s:label cssStyle="width:50px;text-align:center;" value="用户名"></s:label></td>
    	<td><s:textfield name="userName"  cssStyle="height:40px;width:300px;font-size:16;"></s:textfield></td>
    </tr>
    <tr>
    	<td><s:label cssStyle="width:50px;text-align:center;" value="密码"></s:label></td>
    	<td><s:password name="pwd" cssStyle="height:40px;width:300px;margin-top:10px;"></s:password></td>
    </tr>
     <tr>
    	<td><s:label cssStyle="width:50px;text-align:center;" value="确认密码"></s:label></td>
    	<td><s:password name="rpwd" cssStyle="height:40px;width:300px;margin-top:10px;"></s:password></td>
    </tr>
    <tr>
    	<td><s:label value="昵称"></s:label></td><td><s:textfield name="name" cssStyle="height:40px;width:300px;font-size:16;"></s:textfield></td>
    	</tr>
    	<tr>
    	<td><s:label value="学校"></s:label></td>
    	<td><s:select name="school" list="#request.scmp" /></td> 
    	</tr>
    	<tr>
    	<td><s:label value="性别"></s:label></td><td><s:select name="sex" list="{'男','女' }"></s:select></td>
    	</tr>
   
    <tr>
    	<td><s:label value="qq"></s:label></td><td><s:textfield name="qq" cssStyle="height:40px;width:300px;font-size:16;"></s:textfield></td>
    </tr>
    <tr><td><s:label value="email"></s:label></td><td><s:textfield name="email" cssStyle="height:40px;width:300px;font-size:16;"></s:textfield></td>
    </tr>
    <tr><td>
    	<s:label value="phone"></s:label></td><td><s:textfield name="phone" cssStyle="height:40px;width:300px;font-size:16;"></s:textfield></td>
    	</tr>
    	</table>
    	<s:submit value="注册	" cssStyle="height:40px;width:300px;margin-top:20px;background-color:#4400B3;color:#FFF;"></s:submit>
    	</s:form>
    </div>
    </div>
    
  </body>
</html>
