package qiuzudui;

import org.hibernate.*;

import com.opensymphony.xwork2.ActionSupport;

import connect.*;
public class registerAction extends ActionSupport {

	/**
	 * 
	 */
	private static final long serialVersionUID = -7398211398689647455L;
	
	String userName,name,pwd,qq,email,phone;
	String school,sex;
	
	public String execute() throws Exception
	{
		Session session=HibernateSessionFactory.getSession();
		Transaction tr=session.beginTransaction();
		String rstr=SUCCESS;
		try{
		Users user=new Users();
		user.setUserName(userName);
		user.setName(name);
		user.setPwd(pwd);
		user.setQq(qq);
		user.setEmail(email);
		user.setPhone(phone);
		user.setSchool((School)session.load(School.class, Integer.parseInt(school)));
		user.setSex(sex);
		session.save(user);
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

	public String getUserName() {
		return userName;
	}

	public void setUserName(String userName) {
		this.userName = userName;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getPwd() {
		return pwd;
	}

	public void setPwd(String pwd) {
		this.pwd = pwd;
	}

	public String getQq() {
		return qq;
	}

	public void setQq(String qq) {
		this.qq = qq;
	}

	public String getEmail() {
		return email;
	}

	public void setEmail(String email) {
		this.email = email;
	}

	public String getPhone() {
		return phone;
	}

	public void setPhone(String phone) {
		this.phone = phone;
	}

	public String getSchool() {
		return school;
	}

	public void setSchool(String school) {
		this.school = school;
	}

	public String getSex() {
		return sex;
	}

	public void setSex(String sex) {
		this.sex = sex;
	}
	
}
