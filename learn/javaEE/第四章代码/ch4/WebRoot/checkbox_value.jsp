<%@ page contentType="text/html;charset=gb2312"%>
<html>
	<head>
		<title>ͨ��request�����ȡ����Ϣ</title>
	</head>
	<body>	  
	  <form method="post" action="checkbox_value_post.jsp">		
		������
		<input type="text" name="user" size="20"><br>
		�Ա�:
		�� <input type="radio" name="sex" value="��" checked>	
		Ů<input type="radio" name="sex" value="Ů"><br>
		���ã�
		����<input type="checkbox" name="hobby" value="����" checked>
		����<input type="checkbox" name="hobby" value="����">
		��Ӿ<input type="checkbox" name="hobby" value="��Ӿ">
		�ܲ�<input type="checkbox" name="hobby" value="�ܲ�"><br>
		��飺	
		<input type="text" name="intro"><br>	
		<input type="submit" value=" �ύ">
		<input type="reset" value="ȫ����д">
	  </form>
	</body>
</html>
