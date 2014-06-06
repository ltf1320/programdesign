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
		//�������Ϊ�գ���Ѵ�����Ϣ��ӵ�Action���fieldErrors
		if(this.getName()==null||this.getName().trim().equals("")){
				addFieldError("name","validateInputperson()�������Ǳ���ģ�"); //�Ѵ�����Ϣ��������
		}		
		if(this.getAge()==null||this.getAge().trim().equals("")){
			addFieldError("age","validateInputperson()�������Ǳ���ģ�");//�Ѵ�����Ϣ��������
		}	
	}
	public void validate() {
		//�������Ϊ�գ���Ѵ�����Ϣ��ӵ�Action���fieldErrors
		if(this.getName()==null||this.getName().trim().equals("")){
				addFieldError("name","validate()�������Ǳ���ģ�");//�Ѵ�����Ϣ��������
		}	
		if(this.getAge()==null||this.getAge().trim().equals("")){
			addFieldError("age","validate()�������Ǳ���ģ�");//�Ѵ�����Ϣ��������
		}
	}
}
