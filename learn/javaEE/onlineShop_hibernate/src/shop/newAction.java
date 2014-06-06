package shop;
import java.sql.Connection;

import com.opensymphony.xwork2.ActionContext;
import com.opensymphony.xwork2.ActionSupport;

import java.sql.*;

import org.hibernate.Session;
import org.hibernate.Transaction;

import connect.Goods;
public class newAction extends ActionSupport {

	/**
	 * 
	 */
	String Id,name,type,price,stock;
	
	public String getId() {
		return Id;
	}
	public void setId(String id) {
		Id = id;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getType() {
		return type;
	}
	public void setType(String type) {
		this.type = type;
	}
	public String getPrice() {
		return price;
	}
	public void setPrice(String price) {
		this.price = price;
	}
	public String getStock() {
		return stock;
	}
	public void setStock(String stock) {
		this.stock = stock;
	}
	private static final long serialVersionUID = 8622448245937378143L;
	@Override
	public String execute() throws Exception
	{
		Session s=connect.HibernateSessionFactory.getSession();
		Transaction tr=s.beginTransaction();
		String reStr=SUCCESS;
		try
		{
			Goods gd=new Goods();
			gd.setId(Integer.parseInt(Id));
			gd.setName(name);
			gd.setPrice(Double.parseDouble(price));
			gd.setStock(Integer.parseInt(stock));
			gd.setType(type);
			s.save(gd);
			tr.commit();
		}
		catch(Exception e)
		{
			e.printStackTrace();
			reStr=INPUT;
			tr.rollback();
		}
		finally
		{
			s.close();
		}
		return reStr;
	}
}
