package com.action;

import java.util.Map;
import java.util.ArrayList;
import java.util.List;

import com.method.AuthorMethod;
import com.opensymphony.xwork2.ActionContext;
import com.opensymphony.xwork2.ActionSupport;
import com.action.*;
import com.entity.Author;

@SuppressWarnings("serial")
public class FindAuthorAction extends ActionSupport{	
	private String account;   
    private String password; 
    public String getAccount() {
		return account;
	}
	public void setAccount(String account) {
		this.account = account;
	}
	public String getPassword() {
		return password;
	}
	public void setPassword(String password) {
		this.password = password;
	}
	
	@SuppressWarnings("unchecked")
	public String execute() throws Exception {                
		ActionContext ac = ActionContext.getContext(); 
        ac.getSession().put("account", account);   
       
        AuthorMethod Am=new AuthorMethod();
        ArrayList<Author> al=Am.findAuthor(account); 	
		
		ac.getSession().put("alist", al);
		
        return "toWelcome";   
    }   
   
    
}
