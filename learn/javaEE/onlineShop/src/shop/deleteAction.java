package shop;

import java.sql.Connection;
import java.sql.PreparedStatement;

import com.opensymphony.xwork2.ActionSupport;

import connect.Sqlcon;


import org.apache.struts2.ServletActionContext;

public class deleteAction extends ActionSupport {
	/**
	 * 
	 */
	private static final long serialVersionUID = 3190270581914944862L;
	String Id;
	/*
	public String getId() {
		return Id;
	}
	public void setId(String id) {
		Id = id;
	}
	*/
	@Override
	public String execute() throws Exception
	{
		System.out.println("deleteAction!");
		Id=(String)ServletActionContext.getRequest().getParameter("Id");
		Connection con=null;
		String reStr=SUCCESS;
		try
		{
			con=Sqlcon.getCon();
			String sql="delete from goods where Id=?";
			PreparedStatement st=con.prepareStatement(sql);
			st.setInt(1, Integer.parseInt(Id));
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
