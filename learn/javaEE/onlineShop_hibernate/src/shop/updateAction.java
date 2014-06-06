package shop;

import java.sql.Connection;
import java.sql.PreparedStatement;

import com.opensymphony.xwork2.ActionContext;
import com.opensymphony.xwork2.ActionSupport;



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
	}*/
	@Override
	public String execute() throws Exception
	{
		Id=(String)ServletActionContext.getRequest().getParameter("Id");
		ActionContext.getContext().getSession().put("upId", Id);
		return SUCCESS;
	}
	
}
