package com.struts2;



public class GreetAction {

    public String execute() {
    	System.out.println("11"+getName()+"22");
    	System.out.println(getName());//ֱ������acion,Ϊnull
        if ("".equals(getName())) {
            return "FAILURE";
        } else {
            setGreeting("��ã�" + getName());
            setName("zhangsan");
           
            return "SUCCESS";
        }
    }
    
    public String getSum() {
        return "277777778888";
    }
    
//    public String find() {
//
//        if ("".equals(getName())) {
//            return "FAILURE";
//        } else {
//            setGreeting("���find��" + getName());
//
//            return "SUCCESS";
//        }
//    }
    private String pwd;//��action�ж��������,ǰһ��action��û��
                       //ǰһ��action�в��ܸ�pwd��ֵ
   
   	public String getPwd() {		
		return pwd+"99999";
		 //pwdֵΪnull,��"99999"��pwd����ʾnull,
		//ҳ����ֻ��ʾnullʱ,ɶҲ����ʾ.
	}

	public void setPwd(String pwd) {
		this.pwd = pwd;
	}

	private String name;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
    private String Greeting;

    public String getGreeting() {
        return Greeting;
    }

    public void setGreeting(String Greeting) {
        this.Greeting = Greeting;
    }
}
