package connect;

import java.util.Set;


/**
 * School entity. @author MyEclipse Persistence Tools
 */
public class School extends AbstractSchool implements java.io.Serializable {

    // Constructors

    /** default constructor */
    public School() {
    }

	/** minimal constructor */
    public School(City city, String name) {
        super(city, name);        
    }
    
    /** full constructor */
    public School(City city, String name, Set userses, Set messages) {
        super(city, name, userses, messages);        
    }
   
}
