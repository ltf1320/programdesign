package shop;

import java.sql.Connection;
import java.sql.PreparedStatement;

import com.opensymphony.xwork2.ActionSupport;

import org.apache.struts2.ServletActionContext;
import org.hibernate.*;

import java.sql.*;

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
		Session s=connect.HibernateSessionFactory.getSession();
		Id=(String)ServletActionContext.getRequest().getParameter("Id");
		String reStr=SUCCESS;
		try
		{
			Transaction tr=s.beginTransaction();
			SQLQuery qu=s.createSQLQuery("delete from goods where Id=?");
			qu.setInteger(0, Integer.parseInt(Id));
	    	if(qu.executeUpdate()==0)
	    		reStr=INPUT;
	    	tr.commit();
		}
		catch(Exception e)
		{
			e.printStackTrace();
			reStr=INPUT;
		}
		finally
		{
			s.close();
		}
		return reStr;
	}
	
}
