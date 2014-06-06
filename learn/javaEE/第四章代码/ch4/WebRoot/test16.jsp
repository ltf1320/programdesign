<%@ page contentType="text/html;charset=gb2312"%>
<html>
	<head><title>客户端确认</title></head>
<body>
<form method="POST" name="frm1" onsubmit="return checkform()">
   <p align="center">用户登录</p> 
   <p align="center">
       用户名：<input type="text" name="name" size="20">&nbsp;&nbsp;&nbsp;&nbsp;   
       密码：<input type="password" name="pwd" size="20"><br><br>
   <input type="submit" value=" 提交">   
   <input type="reset" value= "全部重写" >
   </p>   
</form>
<SCRIPT language=JavaScript>
  function checkform(){
	var flag=true;
		if(document.frm1.name.value=="")
		{
		  alert("姓名不能为空，请输入值！");
		  document.frm1.name.focus();
		  flag=false;		  
		}
	return flag;
  }
</SCRIPT>
</body>
</html>
