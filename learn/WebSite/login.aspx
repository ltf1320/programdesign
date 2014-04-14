<%@ Page Language="C#" AutoEventWireup="true" CodeFile="login.aspx.cs" Inherits="login" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" action="login.aspx" method="post" runat="server">
        <asp:Label ID="Label1" runat="server" Text="你的名字？"></asp:Label>
        <asp:TextBox ID="txtName" runat="server"></asp:TextBox>
        <br />
        <asp:Label ID="Label2" runat="server" Text="你的生日"></asp:Label>
        <asp:TextBox ID="txtBirth" runat="server"></asp:TextBox>
        <asp:Button ID="Button1" runat="server" Text="提交" />
    </form>
</body>
</html>
