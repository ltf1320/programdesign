<%@ page language="java" import="java.util.*" pageEncoding="GB18030"%>
<%@ taglib prefix="s" uri="/struts-tags"%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
	<head>
		<title>My JSP 'index.jsp' starting page</title>
	</head>
	<body>
	attr中的账号333：<s:property value="#attr.account" /><br><br>
	搜索结果:
	<table border="1" cellspacing="0" cellpadding="1">
			<tr>
				<td><B>作者</B></td>
				<td><B>城市</B></td>
			</tr> 
        <s:iterator value="#session.alist" id="name" status="st"> 
            <tr>                 
             <s:if test="#st.Even">
                <td style="background:lightgreen">
                  <s:property value="#name.au_lname"/><br>                       
                </td>
                <td style="background:lightgreen">
                  <s:property value="#name.city"/><br>                       
                </td>
             </s:if>
             <s:else>                                          
                <td>
                  <s:property value="#name.au_lname"/><br>                       
                </td>
                <td>
                  <s:property value="#name.city"/><br>                       
                </td>
               </s:else>                 
            </tr>           
         </s:iterator>
      </table>		

     </body>
</html>
