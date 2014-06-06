package com.dlmu.action;

import com.dlmu.model.*;
import java.util.Map;
import com.opensymphony.xwork2.ActionContext;
import com.opensymphony.xwork2.ActionSupport;

@SuppressWarnings("serial")
public class AddAction extends ActionSupport{
	private double num1;
	private double num2;

	public double getNum1() {
		return num1;
	}

	public void setNum1(double num1) {
		this.num1 = num1;
	}

	public double getNum2() {
		return num2;
	}

	public void setNum2(double num2) {
		this.num2 = num2;
	}

	// ����ҵ���߼�
	@SuppressWarnings("unchecked")
	public String execute(){
		Calculator biz = new Calculator();
		// ����ҵ���߼���������÷���ֵ
		double addresult = biz.add(num1, num2);
		// ������������request��
		Map request=(Map)ActionContext.getContext().get("request");
		request.put("resu", addresult);
		// ������������Session��
		Map session=ActionContext.getContext().getSession();
		session.put("addresult", addresult);
		//Map application=ActionContext.getContext().getApplication();
		
		return SUCCESS;

	}

}
