<%@ page contentType="text/html;charset=gb2312"%>
<html>
	<head><title>�ͻ���ȷ��</title></head>
<body>
<form method="POST" name="frm1" onsubmit="return checkform()">
   <p align="center">�û���¼</p> 
   <p align="center">
       �û�����<input type="text" name="name" size="20">&nbsp;&nbsp;&nbsp;&nbsp;   
       ���룺<input type="password" name="pwd" size="20"><br><br>
   <input type="submit" value=" �ύ">   
   <input type="reset" value= "ȫ����д" >
   </p>   
</form>
<SCRIPT language=JavaScript>
  function checkform(){
	var flag=true;
		if(document.frm1.name.value=="")
		{
		  alert("��������Ϊ�գ�������ֵ��");
		  document.frm1.name.focus();
		  flag=false;		  
		}
	return flag;
  }
</SCRIPT>
</body>
</html>
