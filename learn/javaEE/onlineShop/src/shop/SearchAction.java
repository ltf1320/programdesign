package shop;
import java.sql.*;

import com.opensymphony.xwork2.ActionContext;
import com.opensymphony.xwork2.ActionSupport;

import connect.Sqlcon;

public class SearchAction extends ActionSupport {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1633290663445464794L;
	
	String searchStr;
	
	
	public String getSearchStr() {
		return searchStr;
	}


	public void setSearchStr(String searchStr) {
		this.searchStr = searchStr;
	}


	@Override
	public String execute() throws Exception
	{
		try{
		Connection con=Sqlcon.getCon();
		
		}
		catch(Exception e)
		{
			e.printStackTrace();
			return INPUT;
		}
		ActionContext.getContext().getSession().put("searchStr", searchStr);
		return SUCCESS;
	}
}
