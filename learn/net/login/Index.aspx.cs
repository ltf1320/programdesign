using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class Index : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if(Session["userName"]==null)
        {
            Response.Write("您不是合法用户");
            Response.Write("<P><A href='login.aspx'>登陆</A>");
        }
        else
        {
            Response.Write(Session["userName"]+" 登陆成功");
        }
    }
}