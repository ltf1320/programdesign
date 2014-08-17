package connect;

import java.util.HashSet;
import java.util.Set;


/**
 * AbstractUsers entity provides the base persistence definition of the Users entity. @author MyEclipse Persistence Tools
 */

public abstract class AbstractUsers  implements java.io.Serializable {


    // Fields    

     private String userName;
     private School school;
     private String name;
     private String pwd;
     private String sex;
     private String qq;
     private String email;
     private String phone;
     private Set messages = new HashSet(0);


    // Constructors

    /** default constructor */
    public AbstractUsers() {
    }

	/** minimal constructor */
    public AbstractUsers(String pwd, String sex) {
        this.pwd = pwd;
        this.sex = sex;
    }
    
    /** full constructor */
    public AbstractUsers(School school, String name, String pwd, String sex, String qq, String email, String phone, Set messages) {
        this.school = school;
        this.name = name;
        this.pwd = pwd;
        this.sex = sex;
        this.qq = qq;
        this.email = email;
        this.phone = phone;
        this.messages = messages;
    }

   
    // Property accessors

    public String getUserName() {
        return this.userName;
    }
    
    public void setUserName(String userName) {
        this.userName = userName;
    }

    public School getSchool() {
        return this.school;
    }
    
    public void setSchool(School school) {
        this.school = school;
    }

    public String getName() {
        return this.name;
    }
    
    public void setName(String name) {
        this.name = name;
    }

    public String getPwd() {
        return this.pwd;
    }
    
    public void setPwd(String pwd) {
        this.pwd = pwd;
    }

    public String getSex() {
        return this.sex;
    }
    
    public void setSex(String sex) {
        this.sex = sex;
    }

    public String getQq() {
        return this.qq;
    }
    
    public void setQq(String qq) {
        this.qq = qq;
    }

    public String getEmail() {
        return this.email;
    }
    
    public void setEmail(String email) {
        this.email = email;
    }

    public String getPhone() {
        return this.phone;
    }
    
    public void setPhone(String phone) {
        this.phone = phone;
    }

    public Set getMessages() {
        return this.messages;
    }
    
    public void setMessages(Set messages) {
        this.messages = messages;
    }
   








}