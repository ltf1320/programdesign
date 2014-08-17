package connect;

import java.sql.Timestamp;


/**
 * AbstractMessage entity provides the base persistence definition of the Message entity. @author MyEclipse Persistence Tools
 */

public abstract class AbstractMessage  implements java.io.Serializable {


    // Fields    

     private Integer idmessage;
     private School school;
     private Users users;
     private City city;
     private String cl1;
     private String cl2;
     private Timestamp createTime;
     private String time;
     private String title;
     private String text;
     private String opt1;
     private String opt2;
     private String opt3;


    // Constructors

    /** default constructor */
    public AbstractMessage() {
    }

	/** minimal constructor */
    public AbstractMessage(Users users, String cl1, Timestamp createTime, String title) {
        this.users = users;
        this.cl1 = cl1;
        this.createTime = createTime;
        this.title = title;
    }
    
    /** full constructor */
    public AbstractMessage(School school, Users users, City city, String cl1, String cl2, Timestamp createTime, String time, String title, String text, String opt1, String opt2, String opt3) {
        this.school = school;
        this.users = users;
        this.city = city;
        this.cl1 = cl1;
        this.cl2 = cl2;
        this.createTime = createTime;
        this.time = time;
        this.title = title;
        this.text = text;
        this.opt1 = opt1;
        this.opt2 = opt2;
        this.opt3 = opt3;
    }

   
    // Property accessors

    public Integer getIdmessage() {
        return this.idmessage;
    }
    
    public void setIdmessage(Integer idmessage) {
        this.idmessage = idmessage;
    }

    public School getSchool() {
        return this.school;
    }
    
    public void setSchool(School school) {
        this.school = school;
    }

    public Users getUsers() {
        return this.users;
    }
    
    public void setUsers(Users users) {
        this.users = users;
    }

    public City getCity() {
        return this.city;
    }
    
    public void setCity(City city) {
        this.city = city;
    }

    public String getCl1() {
        return this.cl1;
    }
    
    public void setCl1(String cl1) {
        this.cl1 = cl1;
    }

    public String getCl2() {
        return this.cl2;
    }
    
    public void setCl2(String cl2) {
        this.cl2 = cl2;
    }

    public Timestamp getCreateTime() {
        return this.createTime;
    }
    
    public void setCreateTime(Timestamp createTime) {
        this.createTime = createTime;
    }

    public String getTime() {
        return this.time;
    }
    
    public void setTime(String time) {
        this.time = time;
    }

    public String getTitle() {
        return this.title;
    }
    
    public void setTitle(String title) {
        this.title = title;
    }

    public String getText() {
        return this.text;
    }
    
    public void setText(String text) {
        this.text = text;
    }

    public String getOpt1() {
        return this.opt1;
    }
    
    public void setOpt1(String opt1) {
        this.opt1 = opt1;
    }

    public String getOpt2() {
        return this.opt2;
    }
    
    public void setOpt2(String opt2) {
        this.opt2 = opt2;
    }

    public String getOpt3() {
        return this.opt3;
    }
    
    public void setOpt3(String opt3) {
        this.opt3 = opt3;
    }
   








}