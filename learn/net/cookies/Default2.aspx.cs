using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class Default2 : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        string redirect = Request.QueryString["redirect"];
        string acceptsCookies;
        if (Request.Cookies["TestCookies"] == null)
            acceptsCookies = "不接受cookies";
        else
        {
            acceptsCookies = "接受cookies";
            Response.Cookies["TestCookies"].Expires = DateTime.Now.AddDays(-1);
        }
        Response.Redirect(redirect + "?AcceptsCookies=" + acceptsCookies, true);
    }
}