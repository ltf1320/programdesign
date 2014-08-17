package connect;

import java.util.Set;


/**
 * City entity. @author MyEclipse Persistence Tools
 */
public class City extends AbstractCity implements java.io.Serializable {

    // Constructors

    /** default constructor */
    public City() {
    }

	/** minimal constructor */
    public City(String name) {
        super(name);        
    }
    
    /** full constructor */
    public City(String name, Set messages, Set schools) {
        super(name, messages, schools);        
    }
   
}
