<%@page contentType="text/html" pageEncoding="gb2312"%>
<%@ taglib prefix="s" uri="/struts-tags"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
   "http://www.w3.org/TR/html4/loose.dtd">

<html>
    <head>        
        <title>input</title>
    </head>
    <body>
       
        <form action="tst.action" method="post">
          <h1>������<input type="text" name="name" value="" /></h1>
          <input type="submit" value="�ύ" name="sumbit" />
        </form>
       
        <!--    
        <s:form action="test.action" >
			<s:textfield name="name" label="����"/>
			
			<s:submit value="�ύ"/>
		</s:form>
		--> 
        
    </body>
</html>
