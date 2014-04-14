using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class _Default : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        Response.Write("已有" + Application["AllCounter"] + "位用户访问了本网站");
        Response.Write("<BR>");
        Response.Write("现在有" + Application["Online"] + "位用户在线");
    }
}