﻿<%@ Page Language="C#" AutoEventWireup="true" CodeFile="login.aspx.cs" Inherits="login" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" action="login.aspx" method="method" runat="server">
    <div>
        <asp:Label ID="Label1" runat="server" Text="用户名"></asp:Label>
        <asp:TextBox ID="userNametxt" runat="server"></asp:TextBox>
        <br />
        <asp:Label ID="Label2" runat="server" Text="密码"></asp:Label>
        &nbsp;<asp:TextBox ID="pwdtxt" runat="server" TextMode="Password"></asp:TextBox>
        <br />
         <asp:Button ID="Button1" runat="server" Text="提交"  onclick="Button1_Click" />
        <asp:HyperLink ID="HyperLink1"  NavigateUrl="~/show.aspx" Text="提交"  runat="server">HyperLink</asp:HyperLink>
    </div>
    
    </form>
</body>
</html>
