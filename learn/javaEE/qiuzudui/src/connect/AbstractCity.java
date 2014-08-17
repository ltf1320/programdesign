package connect;

import java.util.HashSet;
import java.util.Set;

/**
 * AbstractCity entity provides the base persistence definition of the City
 * entity. @author MyEclipse Persistence Tools
 */

public abstract class AbstractCity implements java.io.Serializable {

	// Fields

	private Integer idcity;
	private String name;
	private Set schools = new HashSet(0);

	// Constructors

	/** default constructor */
	public AbstractCity() {
	}

	/** minimal constructor */
	public AbstractCity(Integer idcity, String name) {
		this.idcity = idcity;
		this.name = name;
	}

	/** full constructor */
	public AbstractCity(Integer idcity, String name, Set schools) {
		this.idcity = idcity;
		this.name = name;
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

	public Set getSchools() {
		return this.schools;
	}

	public void setSchools(Set schools) {
		this.schools = schools;
	}

}