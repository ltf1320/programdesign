<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    <asp:SqlDataSource ID="sqlData" runat="server" DataSourceMode="DataReader" 
            ConnectionString="<%$ ConnectionStrings:connection %>" 
            SelectCommand="SELECT [sid], [sname] FROM [stuInfo]"></asp:SqlDataSource>

    </div>
    <asp:GridView ID="GridView1" runat="server" AutoGenerateColumns="False" 
        DataKeyNames="sid" DataSourceID="sqlData" >
        <Columns>
            <asp:BoundField DataField="sid" HeaderText="学号" ReadOnly="True" 
                SortExpression="sid" />
            <asp:BoundField DataField="sname" HeaderText="姓名" SortExpression="sname" />
        </Columns>
    </asp:GridView>
    </form>
</body>
</html>
