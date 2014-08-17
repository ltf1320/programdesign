package connect;

import java.util.HashSet;
import java.util.Set;


/**
 * AbstractSchool entity provides the base persistence definition of the School entity. @author MyEclipse Persistence Tools
 */

public abstract class AbstractSchool  implements java.io.Serializable {


    // Fields    

     private Integer idschool;
     private City city;
     private String name;
     private Set userses = new HashSet(0);
     private Set messages = new HashSet(0);


    // Constructors

    /** default constructor */
    public AbstractSchool() {
    }

	/** minimal constructor */
    public AbstractSchool(City city, String name) {
        this.city = city;
        this.name = name;
    }
    
    /** full constructor */
    public AbstractSchool(City city, String name, Set userses, Set messages) {
        this.city = city;
        this.name = name;
        this.userses = userses;
        this.messages = messages;
    }

   
    // Property accessors

    public Integer getIdschool() {
        return this.idschool;
    }
    
    public void setIdschool(Integer idschool) {
        this.idschool = idschool;
    }

    public City getCity() {
        return this.city;
    }
    
    public void setCity(City city) {
        this.city = city;
    }

    public String getName() {
        return this.name;
    }
    
    public void setName(String name) {
        this.name = name;
    }

    public Set getUserses() {
        return this.userses;
    }
    
    public void setUserses(Set userses) {
        this.userses = userses;
    }

    public Set getMessages() {
        return this.messages;
    }
    
    public void setMessages(Set messages) {
        this.messages = messages;
    }
   








}