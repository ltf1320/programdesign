package shop;
import java.sql.Connection;

import com.opensymphony.xwork2.ActionSupport;

import java.sql.*;


import connect.Sqlcon;
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
		Connection con=null;
		String reStr=SUCCESS;
		try
		{
			con=Sqlcon.getCon();
			String sql="insert into goods values(?,?,?,?,?)";
			PreparedStatement st=con.prepareStatement(sql);
			st.setInt(1, Integer.parseInt(Id));
			st.setString(2, name);
			st.setString(3, type);
			st.setDouble(4,Double.parseDouble(price) );
			st.setInt(5, Integer.parseInt( stock));
	    	if(!st.execute())
	    		reStr=INPUT;
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
