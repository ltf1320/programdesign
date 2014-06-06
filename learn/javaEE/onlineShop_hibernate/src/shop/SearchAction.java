package shop;
import java.sql.*;

import com.opensymphony.xwork2.ActionContext;
import com.opensymphony.xwork2.ActionSupport;


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
		ActionContext.getContext().getSession().put("searchStr", searchStr);
		return SUCCESS;
	}
}
