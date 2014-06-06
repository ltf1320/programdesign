package com.dlmu.action;

import com.opensymphony.xwork2.ActionSupport;

@SuppressWarnings("serial")
public class AddUserAction extends ActionSupport {
	private String userName;
	private String userTelephone;
	private String userAddress;

	public String getUserName() {
		return userName;
	}

	public void setUserName(String userName) {
		this.userName = userName;
	}

	public String getUserTelephone() {
		return userTelephone;
	}

	public void setUserTelephone(String userTelephone) {
		this.userTelephone = userTelephone;
	}

	public String getUserAddress() {
		return userAddress;
	}

	public void setUserAddress(String userAddress) {
		this.userAddress = userAddress;
	}

	public String execute() {
		System.out.println("execute()!!!!!!!!");
		return SUCCESS;
	}	
	
	public void validate(){
		System.out.println("validate()!!!!!!!!");
		if(userName == null || getUserName().length() < 4||getUserName().length() > 20){
			addFieldError("userName", "*�����ĳ��Ȳ�����Ҫ��!");
		}
		if(userTelephone  == null || getUserTelephone().length() < 7){
			addFieldError("userTelephone", "*�绰�ĳ��Ȳ�����Ҫ��!");
		}
		if(userAddress  == null || getUserAddress().length() < 4){
			addFieldError("userAddress", "*��ַ�ĳ��Ȳ�����Ҫ��!");
		}
		
	}

 
}