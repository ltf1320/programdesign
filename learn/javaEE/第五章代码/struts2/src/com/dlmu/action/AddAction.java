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

	// 调用业务逻辑
	@SuppressWarnings("unchecked")
	public String execute(){
		Calculator biz = new Calculator();
		// 调用业务逻辑方法，获得返回值
		double addresult = biz.add(num1, num2);
		// 将计算结果存入request中
		Map request=(Map)ActionContext.getContext().get("request");
		request.put("resu", addresult);
		// 将计算结果存入Session中
		Map session=ActionContext.getContext().getSession();
		session.put("addresult", addresult);
		//Map application=ActionContext.getContext().getApplication();
		
		return SUCCESS;

	}

}
