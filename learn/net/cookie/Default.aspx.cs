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
        Response.Cookies.Remove("user");
        Response.Cookies.Remove("users");
        Response.Cookies.Remove("ppp");
        Response.Write(Response.Cookies.Count);
        HttpCookie mycookie = new HttpCookie("user", "ltf");
        Response.Cookies.Add(mycookie);
        Label1.Text = Request.Cookies["user"].Value.ToString();

        HttpCookie mycookie2 = new HttpCookie("users", "ltf");
        mycookie2.Values.Add("user1", "aaa");
        Response.Cookies.Add(mycookie2);
        Label2.Text = Request.Cookies["users"].Value.ToString();
        try
        {
            Label3.Text = Request.Cookies["users"]["user1"].ToString();
        }
        catch (Exception ex)
        {
            Response.Write("<BR>不存在此cookie");
        }

        HttpCookie mycookie3 = new HttpCookie("ppp");
        mycookie3.Values.Add("my", "2");
        Response.Cookies.Add(mycookie3);
        Label4.Text=Request.Cookies["ppp"]["my"].ToString();

    }
}