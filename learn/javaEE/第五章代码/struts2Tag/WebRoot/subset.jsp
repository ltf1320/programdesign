<%-- 
    Document   : subset
    Created on : 2010-1-6, 20:16:38
    Author     : Administrator
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@taglib prefix="s" uri="/struts-tags"%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
"http://www.w3.org/TR/html4/loose.dtd">

<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>演示Subset标记使用</title>
    </head>
    <body>
        <s:bean id="mydecider" name="struts2.tag.MyDecider"/>
<table border="1" width="200">
            <s:subset source="{'十月围城','三枪拍案惊奇','风云二','2012','阿凡达'}"
            start="1" count="3" decider="mydecider">
                <s:iterator status="st">
                    <tr >
                        <td><s:property/></td>
                    </tr>
                </s:iterator>
            </s:subset>
        </table>

    </body>
</html>
