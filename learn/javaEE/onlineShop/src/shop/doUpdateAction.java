package shop;

import java.sql.Connection;
import java.sql.PreparedStatement;

import com.opensymphony.xwork2.ActionContext;
import com.opensymphony.xwork2.ActionSupport;

import connect.Sqlcon;



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
		Connection con=null;
		String reStr=SUCCESS;
		int Id=Integer.parseInt((String)ActionContext.getContext().getSession().get("upId"));
		try
		{
			con=Sqlcon.getCon();
			String sql="update goods set name=?,type=?,price=?,stock=? where Id=?";
			PreparedStatement st=con.prepareStatement(sql);
			st.setString(1, name);
			st.setString(2, type);
			st.setDouble(3, Double.parseDouble(price));
			st.setInt(4, Integer.parseInt(stock));
			st.setInt(5, Id);
	    	st.execute();
		}
		catch(Exception e)
		{
			e.printStackTrace();
			reStr=INPUT;
		}
		finally
		{
			con.close();
		}
		return reStr;
	}
	
}
