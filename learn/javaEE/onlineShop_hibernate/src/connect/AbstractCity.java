package connect;

import java.util.HashSet;
import java.util.Set;


/**
 * AbstractCity entity provides the base persistence definition of the City entity. @author MyEclipse Persistence Tools
 */

public abstract class AbstractCity  implements java.io.Serializable {


    // Fields    

     private Integer idcity;
     private String name;
     private Set messages = new HashSet(0);
     private Set schools = new HashSet(0);


    // Constructors

    /** default constructor */
    public AbstractCity() {
    }

	/** minimal constructor */
    public AbstractCity(String name) {
        this.name = name;
    }
    
    /** full constructor */
    public AbstractCity(String name, Set messages, Set schools) {
        this.name = name;
        this.messages = messages;
        this.schools = schools;
    }

   
    // Property accessors

    public Integer getIdcity() {
        return this.idcity;
    }
    
    public void setIdcity(Integer idcity) {
        this.idcity = idcity;
    }

    public String getName() {
        return this.name;
    }
    
    public void setName(String name) {
        this.name = name;
    }

    public Set getMessages() {
        return this.messages;
    }
    
    public void setMessages(Set messages) {
        this.messages = messages;
    }

    public Set getSchools() {
        return this.schools;
    }
    
    public void setSchools(Set schools) {
        this.schools = schools;
    }
   








}