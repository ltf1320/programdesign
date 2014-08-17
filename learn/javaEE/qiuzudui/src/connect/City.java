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
	public City(Integer idcity, String name) {
		super(idcity, name);
	}

	/** full constructor */
	public City(Integer idcity, String name, Set schools) {
		super(idcity, name, schools);
	}

}
