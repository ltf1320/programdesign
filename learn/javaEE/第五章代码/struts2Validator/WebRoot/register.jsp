<%@ page language="java"  pageEncoding="UTF-8"%>
<%@ taglib uri="/struts-tags" prefix="s" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
    <head>
        <title>注册页面</title>
    </head>
    <body>
        <s:fielderror cssStyle="color:red;"/>
        <s:form action="register" theme="simple" method="Post">
            <table border="1" cellpadding="0" cellspacing="0">
                <tr>
                    <td>用户名</td>
                    <td><s:textfield name="username" /></td>
                </tr>
                <tr>
                    <td>密  码</td>
                    <td><s:password name="password" label="password" id="password"/></td>
                </tr>
                <tr>
                    <td>再次输入密码</td>
                    <td><s:password name="repassword"  /></td>
                </tr>
                <tr>
                    <td>出生日期</td>
                    <td><s:textfield name="birthday">
                          <s:param name="value">
                            <s:date name="birthday" format="yyyy-MM-dd"/>
                          </s:param>
                        </s:textfield>                        
                    </td>
                </tr>
                <tr>
                    <td>身高（米）</td>
                    <td><s:textfield  name="height" /></td>
                </tr>
                <tr>
                    <td>电子邮箱</td>
                    <td><s:textfield name="myemail" /></td>
                </tr>
                 <tr>
                    <td>博客</td>
                    <td><s:textfield name="blogurl" /></td>
                </tr>
                <tr>
                    <td>身份证号</td>
                    <td><s:textfield name="cardid" /></td>
                </tr>
                 <tr>
                    <td>&nbsp;</td>
                    <td><s:submit  value="注册"/></td>
                </tr>
            </table>
        </s:form>       
           
    </body>
</html>



