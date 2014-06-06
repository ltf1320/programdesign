package shop;

import java.sql.Connection;
import java.sql.PreparedStatement;

import com.opensymphony.xwork2.ActionContext;
import com.opensymphony.xwork2.ActionSupport;

import connect.Sqlcon;

import java.sql.*;

import org.apache.struts2.ServletActionContext;

public class updateAction extends ActionSupport {
	/**
	 * 
	 */
	private static final long serialVersionUID = 319027058914944862L;
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
		Connection con=null;
		String reStr=SUCCESS;
		ResultSet rs=null;
		Id=(String)ServletActionContext.getRequest().getParameter("Id");
		try
		{
			con=Sqlcon.getCon();
			String sql="select count(*) from goods where Id=?";
			PreparedStatement st=con.prepareStatement(sql);
			st.setInt(1, Integer.parseInt(Id));
	    	rs=st.executeQuery();
	    	rs.next();
	    	if(rs.getInt(1)==0)
	    		reStr=INPUT;
	    	else ActionContext.getContext().getSession().put("upId", Id);
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
