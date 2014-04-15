<%@ page language="java" import="java.util.*" pageEncoding="GB2312" %>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <title>注册</title>
  </head>
  
  <body >
  
    <form action="servlet/CheckRegister" method="post"> 
    	用户名：<input type="text" name="userName" required="true" pattern="[a-zA-Z0-9]+"/><BR/>
    	密码：<input type="password" name="password" required="true"/><BR/>
    	性别：<input type="radio" name="sex" value="男">男
    	<input type="radio" name="sex" value="女">女<BR/>
    	<select name="pro">
    		<option value="学生">学生</option>
    		<option value="教师">教师</option>
    	</select>
    	<BR/>
    	兴趣爱好：<BR/>
    	<input type="checkbox" name="intres" value="足球"/>足球
     	<input type="checkbox" name="intres" value="篮球"/>篮球
     	<input type="checkbox" name="intres" value="游泳"/>游泳
     	<BR/>
     	自我介绍:<BR/>
     	<textarea rows="5" cols="40" name="selfIntro"></textarea><BR/>
     	<input type="submit" value="提交"/>
     </form>
  </body>
</html>
