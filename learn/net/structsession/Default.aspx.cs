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
        List<Book> bks=new List<Book>();
        Book a=new Book("sss","ppp",10);
        bks.Add(a);
        a = new Book("qqq", "www", 20);
        bks.Add(a);
        Session["book"]=bks;
        Server.Transfer("show.aspx");
    }
}