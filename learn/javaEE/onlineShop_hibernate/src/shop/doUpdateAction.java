package shop;

import java.sql.Connection;
import java.sql.PreparedStatement;

import com.opensymphony.xwork2.ActionContext;
import com.opensymphony.xwork2.ActionSupport;

import connect.Goods;

import org.hibernate.*;



public class doUpdateAction extends ActionSupport {

	/**
	 * 
	 */
	private static final long serialVersionUID = -1875749117486533100L;
	String name,type,price,stock;
	
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
	@Override
	public String execute() throws Exception
	{
		Session s=connect.HibernateSessionFactory.getSession();
		Transaction tr=s.beginTransaction();
		String reStr=SUCCESS;
		int Id=Integer.parseInt((String)ActionContext.getContext().getSession().get("upId"));
		try
		{
			Goods gd=new Goods();
			gd.setId(Id);
			gd.setName(name);
			gd.setPrice(Double.parseDouble(price));
			gd.setStock(Integer.parseInt(stock));
			gd.setType(type);
			s.update(gd);
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
