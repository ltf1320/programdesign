<%@ page language="java" import="java.util.*" pageEncoding="GB18030"%>
<%@ taglib prefix="s" uri="/struts-tags"%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
	<head>
		<title>My JSP 'index.jsp' starting page</title>
	</head>
	<body>
	111 <%=request.getParameter("account") %>
	<br>
	222 <%=request.getAttribute("account") %>
	<br>
	333 <%=session.getAttribute("account") %>
	
	<br><br><br>
		��ӭ�˺�Ϊ
		<s:property value="account" />
		<br><BR>
		��������е��˺ţ�
		<s:property value="#parameters.account" />
		<br><br>
				
		���������е��˺ţ�
		<s:property value="#request.account2" />
		<br><br>
		
		�Ự�����е��ʺţ�
		<s:property value="#session.account" />
		<br><br>
		
		Ӧ�������е��˺ţ�
		<s:property value="#application.account" />
		<br><br>
		
		attr�е��˺ţ�
		<s:property value="#attr.account" />

		<br><br><br>
		<table border="0" cellspacing="0" cellpadding="1">
		   <s:iterator value="#session.alist" id="name" status="st">   
		   <%-- <s:iterator value="#request.al" id="name" status="st">--%> 
           <%-- <s:iterator value="al" id="name" status="st">    --%>        
              <tr>
                <s:if test="#st.Even"> 
                    <td>
                       <s:property value="%{#st.index}"/>
                       <s:property value="name"/>
                    </td>
                </s:if>
                <s:else>
                    <td>
                       <s:property value="#st.index"/>
                       <s:property value="name"/>
                    </td>
                </s:else>
              </tr>
            </s:iterator>
        </table>

	</body>
</html>
