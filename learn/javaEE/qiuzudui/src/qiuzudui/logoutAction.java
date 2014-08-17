package qiuzudui;

import com.opensymphony.xwork2.ActionContext;
import com.opensymphony.xwork2.ActionSupport;

public class logoutAction extends ActionSupport {
	public String execute() throws Exception
	{
		ActionContext.getContext().getSession().remove("userName");
		return SUCCESS;
	}
}
