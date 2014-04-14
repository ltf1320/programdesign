using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

/// <summary>
///Book 的摘要说明
/// </summary>
/// 
[Serializable]
public class Book
{
    public string name;
    public string author;
    public double price;
	public Book(string N,string A,double p)
	{
        name = N;
        author = A;
        price = p;
		//
		//TODO: 在此处添加构造函数逻辑
		//
	}
}
