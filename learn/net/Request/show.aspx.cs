using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class show : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
    //    string name = Request.Form["userNametxt"];
    //    string pwd = Request.Form["pwdtxt"];
        string name = Request.QueryString["userNametxt"];
        string pwd = Request.QueryString["pwdtxt"];
        userNametxt.Text = name;
        pwdtxt.Text = pwd;
    }
}