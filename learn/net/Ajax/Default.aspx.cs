using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class _Default : System.Web.UI.Page
{
    int a;
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void onchanged(object sender, EventArgs e)
    {
        a = drop.SelectedIndex;
        momo.Items.Add(a.ToString());
    }
}