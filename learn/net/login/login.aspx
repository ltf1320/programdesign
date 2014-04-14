<%@ Page Language="C#" AutoEventWireup="true" CodeFile="login.aspx.cs" Inherits="login" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <style type="text/css">
    .stylel
    {
        text-align:center;
    }
    </style>
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div class="stylel">
        <br />登陆<br />
        <br />
        <asp:Label ID="Label1" runat="server" Text="用户名"></asp:Label>
        <asp:TextBox ID="userNametxt" runat="server" ></asp:TextBox>
        <br />
        <br />
        <asp:Label ID="Label2" runat="server" Text="密码"></asp:Label>
        &nbsp;
        <asp:TextBox ID="pwdtxt" runat="server" Text="" TextMode="Password" Width="145px"></asp:TextBox>
        <br />
        <asp:Button ID="login_btn" runat="server" Text="登陆" onclick="login_btn_Click" />
        <asp:Button ID="reset_btn" runat="server" Text="重置" onclick="reset_btn_Click" />
    </div>
    
    </form>
</body>
</html>
