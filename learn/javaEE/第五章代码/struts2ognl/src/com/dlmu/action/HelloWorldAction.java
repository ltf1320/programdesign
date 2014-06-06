package com.dlmu.action;



import java.util.Map;
import java.util.ArrayList;
import java.util.List;
import com.opensymphony.xwork2.ActionContext;
import com.opensymphony.xwork2.ActionSupport;

@SuppressWarnings("serial")
public class HelloWorldAction extends ActionSupport{	
	private String account;   
    private String password;   
    
    private ArrayList<String>  al;
    public ArrayList<String> getAl() { 
    	return al; 
    }
    
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
        this.businessExecute();   
        Map request1=(Map)ActionContext.getContext().get("request");
		request1.put("account2", account);
        
		ActionContext ac = ActionContext.getContext(); 
		
		Map session=ac.getSession();		
        session.put("account", account);
        Map application=ac.getApplication();
        application.put("account", account);    
        
        al=new ArrayList<String>();
		al.add("111");
		al.add("222");
		al.add("333");
		al.add("444");
		ac.getSession().put("alist", al);
           
        return "toWelcome";   
    }   
    /**  
     * 示例方法，表示可以执行业务逻辑处理的方法，  
     */   
    public void businessExecute(){   
        System.out.println("用户5555555555输入的参数为==="+"account="+account+",password="+password);   
    }         

}
