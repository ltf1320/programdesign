package com.struts2;



public class GreetAction {

    public String execute() {
    	System.out.println("11"+getName()+"22");
    	System.out.println(getName());//直接运行acion,为null
        if ("".equals(getName())) {
            return "FAILURE";
        } else {
            setGreeting("你好！" + getName());
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
//            setGreeting("你好find！" + getName());
//
//            return "SUCCESS";
//        }
//    }
    private String pwd;//本action中定义的属性,前一个action中没有
                       //前一个action中不能给pwd传值
   
   	public String getPwd() {		
		return pwd+"99999";
		 //pwd值为null,有"99999"，pwd能显示null,
		//页面上只显示null时,啥也不显示.
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
