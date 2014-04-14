using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;


public partial class message : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        SnameText.Visible = false;
        SageText.Visible = false;
        SsexText.Visible = false;
        SpostText.Visible = false;
        SintroText.Visible = false;
        SaddText.Visible = false;
        Label1.Visible = false;
        Label1.Visible = false;
        Label2.Visible = false;
        Label3.Visible = false;
        Label4.Visible = false;
        Label5.Visible = false;
        Label6.Visible = false;
    }

    protected void subBtn_Click(object sender, EventArgs e)
    {
        SnameText.Visible = true;
        SageText.Visible = true;
        SsexText.Visible = true;
        SpostText.Visible = true;
        SintroText.Visible = true;
        SaddText.Visible = true;
        Label1.Visible = true;
        Label1.Visible = true;
        Label2.Visible = true;
        Label3.Visible = true;
        Label4.Visible = true;
        Label5.Visible = true;
        Label6.Visible = true;
        SnameText.Text = nameText.Text;
        SageText.Text = ageText.Text;
        SsexText.Text = sexText.Text;
        SpostText.Text = postText.Text;
        SintroText.Text = introText.Text;
        SaddText.Text = addText.Text;
         
    }
}