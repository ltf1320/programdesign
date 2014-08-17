package qiuzudui;

import java.math.BigInteger;

import org.hibernate.SQLQuery;
import org.hibernate.Session;
import org.hibernate.Transaction;

import com.opensymphony.xwork2.ActionContext;
import com.opensymphony.xwork2.ActionSupport;

import connect.HibernateSessionFactory;

public class loginAction extends ActionSupport {

	/**
	 * 
	 */
	String userName,pwd;
	public String getPwd() {
		return pwd;
	}
	public String getUserName() {
		return userName;
	}
	public void setUserName(String userName) {
		this.userName = userName;
	}
	public void setPwd(String pwd) {
		this.pwd = pwd;
	}
	private static final long serialVersionUID = 605977492567825154L;
	public String execute() throws Exception
	{
		Session session=HibernateSessionFactory.getSession();
		Transaction tr=session.beginTransaction();
		String rstr=SUCCESS;
		try{
		SQLQuery qu=session.createSQLQuery("select count(*) from users where userName=? and pwd=?");
		qu.setString(0,userName);
		qu.setString(1, pwd);
		BigInteger cnt=(BigInteger)qu.uniqueResult();
		if(cnt.intValue()==1)
		{
			ActionContext.getContext().getSession().put("userName", userName);
		}
		else
		{
			rstr=INPUT;
		}
		}catch(Exception e)
		{
			rstr=INPUT;
			tr.rollback();
		}
		finally
		{
			session.close();
		}
		return rstr;
	}
}
