<%@ page contentType="text/html;charset=gb2312"%>
<html>
	<head>
		<title>通过request对象获取表单信息</title>
	</head>
	<body>	  
	  <form method="post" action="checkbox_value_post.jsp">		
		姓名：
		<input type="text" name="user" size="20"><br>
		性别:
		男 <input type="radio" name="sex" value="男" checked>	
		女<input type="radio" name="sex" value="女"><br>
		爱好：
		唱歌<input type="checkbox" name="hobby" value="唱歌" checked>
		跳舞<input type="checkbox" name="hobby" value="跳舞">
		游泳<input type="checkbox" name="hobby" value="游泳">
		跑步<input type="checkbox" name="hobby" value="跑步"><br>
		简介：	
		<input type="text" name="intro"><br>	
		<input type="submit" value=" 提交">
		<input type="reset" value="全部重写">
	  </form>
	</body>
</html>
