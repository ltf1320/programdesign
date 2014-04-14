<%@ Page Language="C#" AutoEventWireup="true" CodeFile="message.aspx.cs" Inherits="message" Debug="true" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head id="Head1" runat="server">
    <title></title>
</head>

<body>
    <form id="form1" action="message.aspx" runat="server">
    <div>
        <asp:label ID="nameLabel" runat="server" text="姓名"></asp:label><asp:TextBox ID="nameText" runat="server"></asp:TextBox><br />
        <asp:label ID="ageLabel" runat="server" text="年龄"></asp:label><asp:TextBox ID="ageText" runat="server"></asp:TextBox><br /> 
        <asp:label ID="sexLabel" runat="server" text="性别"></asp:label><asp:TextBox ID="sexText" runat="server"></asp:TextBox><br />
        <asp:label ID="postLabel" runat="server" text="邮编"></asp:label><asp:TextBox ID="postText" runat="server"></asp:TextBox><br />
        <asp:label ID="addLabel" runat="server" text="地址"></asp:label><asp:TextBox ID="addText" runat="server"></asp:TextBox><br />
        <asp:label ID="a" runat="server" text="自我介绍"></asp:label><br />
        <asp:TextBox ID="introText" runat="server"></asp:TextBox><br />
        <asp:Button ID="subBtn" runat="server" text="提交" onclick="subBtn_Click" /><br />

        <asp:label ID="Label1" runat="server" text="姓名"></asp:label><asp:TextBox ID="SnameText" runat="server"></asp:TextBox><br />
        <asp:label ID="Label2" runat="server" text="年龄"></asp:label><asp:TextBox ID="SageText" runat="server"></asp:TextBox><br /> 
        <asp:label ID="Label3" runat="server" text="性别"></asp:label><asp:TextBox ID="SsexText" runat="server"></asp:TextBox><br />
        <asp:label ID="Label4" runat="server" text="邮编"></asp:label><asp:TextBox ID="SpostText" runat="server"></asp:TextBox><br />
        <asp:label ID="Label5" runat="server" text="地址"></asp:label><asp:TextBox ID="SaddText" runat="server"></asp:TextBox><br />
        <asp:label ID="Label6" runat="server" text="自我介绍"></asp:label><br />
        <asp:TextBox ID="SintroText" runat="server"></asp:TextBox><br />
        
    </div>
    </form>
</body>
</html>
