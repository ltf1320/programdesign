﻿<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <asp:ScriptManager ID="ScriptManager1" runat="server">
        </asp:ScriptManager>
        <asp:UpdatePanel ID="UpdatePanel1" runat="server">
            <ContentTemplate>
                <asp:DropDownList ID="drop" OnSelectedIndexChanged="onchanged" AutoPostBack="true" runat="server">
                    <asp:ListItem>1</asp:ListItem>
                    <asp:ListItem>2</asp:ListItem>
                </asp:DropDownList>
                <asp:DropDownList ID="momo" AutoPostBack="true" runat="server">
                
                </asp:DropDownList>
            </ContentTemplate>
        </asp:UpdatePanel>
        <asp:TextBox ID="ca" runat="server" TextMode="Password"></asp:TextBox>
    </div>
    </form>
</body>
</html>
