using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class login : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void login_btn_Click(object sender, EventArgs e)
    {
        string userName = userNametxt.Text.Trim();
        string Pwd = pwdtxt.Text.Trim();
        if (userName == "ltf" && Pwd == "111")
        {
            Session.Timeout = 30;
            Session["userName"] = userName;
            Server.Transfer("Index.aspx");
        }
        else
        {
            Response.Write("用户名或密码错误");
        }
    }
    protected void reset_btn_Click(object sender, EventArgs e)
    {
        pwdtxt.Text = "";
        userNametxt.Text = "";
    }
}