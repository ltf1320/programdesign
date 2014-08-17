package qiuzudui;

import java.sql.Timestamp;
import java.util.Date;

import org.hibernate.Session;
import org.hibernate.Transaction;

import com.opensymphony.xwork2.ActionContext;
import com.opensymphony.xwork2.ActionSupport;

import connect.*;
public class postAction extends ActionSupport {
	
	String cl1,cl2,title,time,text,opt1,opt2,opt3;
	
	public String getCl1() {
		return cl1;
	}

	public void setCl1(String cl1) {
		this.cl1 = cl1;
	}

	public String getCl2() {
		return cl2;
	}

	public void setCl2(String cl2) {
		this.cl2 = cl2;
	}

	public String getTitle() {
		return title;
	}

	public void setTitle(String title) {
		this.title = title;
	}

	public String getTime() {
		return time;
	}

	public void setTime(String time) {
		this.time = time;
	}

	public String getText() {
		return text;
	}

	public void setText(String text) {
		this.text = text;
	}

	public String getOpt1() {
		return opt1;
	}

	public void setOpt1(String opt1) {
		this.opt1 = opt1;
	}

	public String getOpt2() {
		return opt2;
	}

	public void setOpt2(String opt2) {
		this.opt2 = opt2;
	}

	public String getOpt3() {
		return opt3;
	}

	public void setOpt3(String opt3) {
		this.opt3 = opt3;
	}

	public String execute() throws Exception
	{
		String rstr=SUCCESS;
		Message msg=new Message();
		msg.setTitle(title);
		msg.setCl1(cl1);
		msg.setCl2(cl2);
		msg.setCreateTime(new Timestamp(System.currentTimeMillis()));
		msg.setOpt1(opt1);
		msg.setOpt2(opt2);
		msg.setOpt3(opt3);
		msg.setText(text);
		msg.setTime(time);
		Session session=HibernateSessionFactory.getSession();
		Transaction tr=session.beginTransaction();
		try{
			msg.setUsers((Users)session.load(Users.class,(String) ActionContext.getContext().getSession().get("userName")));
			session.save(msg);
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
			session.close();
		}
		return rstr;
	}
}
