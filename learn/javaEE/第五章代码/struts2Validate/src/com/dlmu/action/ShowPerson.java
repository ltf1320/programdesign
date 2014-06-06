package com.dlmu.action;

import com.opensymphony.xwork2.ActionSupport;

@SuppressWarnings("serial")
public class ShowPerson extends ActionSupport{

	private String name;
	private String sex;
	private String age;
	private String address;
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getSex() {
		return sex;
	}
	public void setSex(String sex) {
		this.sex = sex;
	}
	public String getAge() {
		return age;
	}
	public void setAge(String age) {
		this.age = age;
	}
	public String getAddress() {
		return address;
	}
	public void setAddress(String address) {
		this.address = address;
	}
	
	public String inputperson(){
		return SUCCESS;				
	}
	
	public void validateInputperson() {
		//如果姓名为空，则把错误信息添加到Action类的fieldErrors
		if(this.getName()==null||this.getName().trim().equals("")){
				addFieldError("name","validateInputperson()：姓名是必须的！"); //把错误信息保存起来
		}		
		if(this.getAge()==null||this.getAge().trim().equals("")){
			addFieldError("age","validateInputperson()：年龄是必须的！");//把错误信息保存起来
		}	
	}
	public void validate() {
		//如果姓名为空，则把错误信息添加到Action类的fieldErrors
		if(this.getName()==null||this.getName().trim().equals("")){
				addFieldError("name","validate()：姓名是必须的！");//把错误信息保存起来
		}	
		if(this.getAge()==null||this.getAge().trim().equals("")){
			addFieldError("age","validate()：年龄是必须的！");//把错误信息保存起来
		}
	}
}
