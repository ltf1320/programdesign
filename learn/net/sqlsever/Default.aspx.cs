using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;
using System.Configuration;
using System.Data;

public partial class _Default : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        SqlConnection connection = getSqlConnect();
        connection.Open();
        string sqlcmd = "SELECT * FROM Us";
        SqlCommand cmd = new SqlCommand(sqlcmd, connection);
        /*
        SqlDataReader reader = cmd.ExecuteReader();
        while (reader.Read())
        {
            for(int i=0;i<3;i++)
                Response.Write(reader[i].ToString() + "&nbsp;");
            Response.Write("<BR>");
        }
        */
        SqlDataAdapter adp = new SqlDataAdapter(sqlcmd, connection);
        DataSet dset = new DataSet();
        adp.Fill(dset);
        Response.Write(dset.Container.Components.Count);
    }
    SqlConnection getSqlConnect()
    {
        string constr = ConfigurationManager.AppSettings["connstring"].ToString();
        SqlConnection connection = new SqlConnection(constr);
        return connection;
    }
}