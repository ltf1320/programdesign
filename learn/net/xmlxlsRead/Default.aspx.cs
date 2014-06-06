﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data;
using System.IO;
using System.Data.OleDb;

public partial class _Default : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        DataTable tb = ExcelToDataTable("D:\\programdesign\\learn\\net\\xmlxlsRead\\BOP_YZ_BusRoute.xls", "Sheet1");
        GridView1.DataSource = tb;
        GridView1.DataBind();
        Response.Write(tb.Columns[0].ColumnName);
    }
    /// <summary>    
    /// 把数据从Excel装载到DataTable    
    /// </summary>    
    /// <param name="pathName">带路径的Excel文件名</param>    
    /// <param name="sheetName">工作表名</param>
    /// <param name="tbContainer">将数据存入的DataTable</param>
    /// <returns></returns> 
    public DataTable ExcelToDataTable(string pathName, string sheetName)
    {
        DataTable tbContainer = new DataTable();
        string strConn = string.Empty;
        if (string.IsNullOrEmpty(sheetName))
        {
            sheetName = "Sheet1";
        }
        FileInfo file = new FileInfo(pathName);
        if (!file.Exists)
        {
            throw new Exception("文件不存在");
        }
        string extension = file.Extension;
        switch (extension)
        {
            case ".xls":
                strConn = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=" + pathName + ";Extended Properties='Excel 8.0;HDR=Yes;IMEX=1;'";
                break;
            case ".xlsx":
                strConn = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=" + pathName + ";Extended Properties='Excel 12.0;HDR=Yes;IMEX=1;'";
                break;
            default:
                strConn = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=" + pathName + ";Extended Properties='Excel 8.0;HDR=Yes;IMEX=1;'";
                break;
        }
        //链接Excel
        OleDbConnection cnnxls = new OleDbConnection(strConn);
        //读取Excel里面有 表Sheet1
        OleDbDataAdapter oda = new OleDbDataAdapter(string.Format("select * from [{0}$]", sheetName), cnnxls);
        DataSet ds = new DataSet();
        //将Excel里面有表内容装载到内存表中！
        oda.Fill(tbContainer);
        return tbContainer;
    }
}

