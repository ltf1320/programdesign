package com.struts2;




public class TestAction {

    public String execute() {

        if ("".equals(getName())) {
            return "FAILURE";
        } else {
            setGreeting("ÄãºÃ£¡" + getName());

            return "SUCCESS";
        }
    }
    
//    public String find() {
//
//        if ("".equals(getName())) {
//            return "FAILURE";
//        } else {
//            setGreeting("ÄãºÃfind£¡" + getName());
//
//            return "SUCCESS";
//        }
//    }
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
