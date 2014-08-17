package qiuzudui;



import java.util.List;

import com.opensymphony.xwork2.ActionContext;
import com.opensymphony.xwork2.ActionSupport;

import connect.*;

import org.hibernate.*;
public class searchAction extends ActionSupport {

	/**
	 * 
	 */
	private static final long serialVersionUID = 7576458287112349024L;
	
	String keyword;
	List<Message> msgli;
	public List<Message> getMsgli() {
		return msgli;
	}

	public void setMsgli(List<Message> msgli) {
		this.msgli = msgli;
	}

	public String getKeyword() {
		return keyword;
	}

	public void setKeyword(String keyword) {
		this.keyword = keyword;
	}

	public String execute() throws Exception
	{
		String rstr=SUCCESS;
		Session ses=HibernateSessionFactory.getSession();
		Transaction tr=ses.beginTransaction();
		SQLQuery qu=ses.createSQLQuery("select * from Message where title like ? or text like ? or opt1 like ? or opt2 like ? or opt3 like ?").addEntity(Message.class);
		qu.setString(0, '%'+keyword+'%');
		qu.setString(1, '%'+keyword+'%');
		qu.setString(2, '%'+keyword+'%');
		qu.setString(3, '%'+keyword+'%');
		qu.setString(4, '%'+keyword+'%');
		try{
		setMsgli((List<Message>)qu.list());
		tr.commit();
		}
		catch(Exception e)
		{
			e.printStackTrace();
			tr.rollback();
			rstr=INPUT;
		}
		finally
		{
			ses.close();
		}
		return rstr;
	}
}
