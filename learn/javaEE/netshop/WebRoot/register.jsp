<%@ page language="java" import="java.util.*" pageEncoding="GB2312" %>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <title>ע��</title>
  </head>
  
  <body >
  
    <form action="servlet/CheckRegister" method="post"> 
    	�û�����<input type="text" name="userName" required="true" pattern="[a-zA-Z0-9]+"/><BR/>
    	���룺<input type="password" name="password" required="true"/><BR/>
    	�Ա�<input type="radio" name="sex" value="��">��
    	<input type="radio" name="sex" value="Ů">Ů<BR/>
    	<select name="pro">
    		<option value="ѧ��">ѧ��</option>
    		<option value="��ʦ">��ʦ</option>
    	</select>
    	<BR/>
    	��Ȥ���ã�<BR/>
    	<input type="checkbox" name="intres" value="����"/>����
     	<input type="checkbox" name="intres" value="����"/>����
     	<input type="checkbox" name="intres" value="��Ӿ"/>��Ӿ
     	<BR/>
     	���ҽ���:<BR/>
     	<textarea rows="5" cols="40" name="selfIntro"></textarea><BR/>
     	<input type="submit" value="�ύ"/>
     </form>
  </body>
</html>
