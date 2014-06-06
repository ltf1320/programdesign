using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Xml;

public partial class xmlRead : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        string xmlFilePath = this.Server.MapPath("BOP_YZ_WeiBo_TransportBroadcast.xml"); //Xml 文件路路
        XmlDocument xmlDoc = new XmlDocument();
        xmlDoc.Load(xmlFilePath);
        XmlNodeList xnl = xmlDoc.SelectSingleNode("ArrayOfNewsItem").ChildNodes;
        this.Response.Write("News&nbsp;&nbsp;&nbsp;&nbsp;Title");
        foreach (XmlNode xn in xnl)
        {
            XmlElement xe = (XmlElement)xn;
            this.Response.Write("<br/>" + xe.GetAttribute("Title"));
            XmlNodeList xnl2 = xe.ChildNodes;
            foreach (XmlNode xn2 in xnl2)
            {
            //    if(xn2.Name=="Title")
                this.Response.Write("&nbsp;&nbsp;&nbsp;&nbsp;" + xn2.InnerText+"<BR>");
            }
        }
    }
}
