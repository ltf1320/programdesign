package qiuzudui;

import com.opensymphony.xwork2.ActionContext;
import com.opensymphony.xwork2.ActionSupport;

import connect.*;

import org.hibernate.*;
public class deleteAction extends ActionSupport {

	/**
	 * 
	 */
	private static final long serialVersionUID = 3352341017192519801L;

	
	public String execute() throws Exception
	{
		Object obj=ActionContext.getContext().getParameters().get("id");
		int id=Integer.parseInt(((String[])(ActionContext.getContext().getParameters().get("id")))[0]);
		Session ses=HibernateSessionFactory.getSession();
		Transaction tr=ses.beginTransaction();
		try{
		SQLQuery qu=ses.createSQLQuery("delete from message where idmessage=?");
		qu.setInteger(0, id);
		qu.executeUpdate();
		tr.commit();
		}
		catch(Exception e)
		{
			tr.rollback();
		}
		finally
		{
			ses.close();
		}
		return SUCCESS;
	}
}
