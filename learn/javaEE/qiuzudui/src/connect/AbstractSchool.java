package connect;

import java.util.HashSet;
import java.util.Set;

/**
 * AbstractSchool entity provides the base persistence definition of the School
 * entity. @author MyEclipse Persistence Tools
 */

public abstract class AbstractSchool implements java.io.Serializable {

	// Fields

	private Integer idschool;
	private City city;
	private String name;
	private Set userses = new HashSet(0);

	// Constructors

	/** default constructor */
	public AbstractSchool() {
	}

	/** minimal constructor */
	public AbstractSchool(Integer idschool, City city, String name) {
		this.idschool = idschool;
		this.city = city;
		this.name = name;
	}

	/** full constructor */
	public AbstractSchool(Integer idschool, City city, String name, Set userses) {
		this.idschool = idschool;
		this.city = city;
		this.name = name;
		this.userses = userses;
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

}