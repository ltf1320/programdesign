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
	public School(Integer idschool, City city, String name) {
		super(idschool, city, name);
	}

	/** full constructor */
	public School(Integer idschool, City city, String name, Set userses) {
		super(idschool, city, name, userses);
	}

}
