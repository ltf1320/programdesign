<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@ taglib prefix="s" uri="/struts-tags" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
"http://www.w3.org/TR/html4/loose.dtd">

<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>演示迭代Map对象</title>
    </head>
    <body>
        <table>
          <tr> <th>序号</th>
          <th>型号</th>
          <th>价格</th></tr>
          <s:iterator value="#{'IBMT400':'13500','HP nx6330':'8900','Dell4500':'7800'}" id="computers" status="st">
             <tr>
                 <td>
                    <s:property value="#st.getIndex()"/>
                 </td>
                 <td >
                    <s:property value="#computers.key"/>
                 </td>
                 <td >
                    <s:property value="#computers.value"/>
                 </td>
                </tr>
            </s:iterator>               
        </table>
    </body>
</html>
