<%@ Page Language="C#" AutoEventWireup="true" CodeFile="show.aspx.cs" Inherits="show" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <asp:Label ID="Label1" runat="server" Text="用户名"></asp:Label>
        <asp:TextBox ID="userNametxt" runat="server"></asp:TextBox>
        <asp:Label ID="Label2" runat="server" Text="密码"></asp:Label>
        &nbsp;<asp:TextBox ID="pwdtxt" runat="server"></asp:TextBox>
    </div>
    </form>
</body>
</html>
