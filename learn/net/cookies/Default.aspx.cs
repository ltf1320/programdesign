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
        if (!Page.IsPostBack)
        {
            if (Request.QueryString["AcceptsCookies"] == null)
            {
                Response.Cookies["TestCookies"].Value = "ok";
                Response.Cookies["TestCookies"].Expires = DateTime.Now.AddMinutes(1);
                Response.Redirect("Default2.aspx?redirect=" + Server.UrlEncode(Request.Url.ToString()));
            }
            else
            {
                Response.Write("结果:"+Request.QueryString["AcceptsCookies"]);
            }
        }
    }
}