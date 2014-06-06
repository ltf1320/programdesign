package org.model;

import java.sql.Timestamp;

/**
 * TbUser entity. @author MyEclipse Persistence Tools
 */

public class TbUser implements java.io.Serializable {

	// Fields

	private String name;
	private String sex;
	private Timestamp born;
	private String profession;

	// Constructors

	/** default constructor */
	public TbUser() {
	}

	/** minimal constructor */
	public TbUser(String name) {
		this.name = name;
	}

	/** full constructor */
	public TbUser(String name, String sex, Timestamp born, String profession) {
		this.name = name;
		this.sex = sex;
		this.born = born;
		this.profession = profession;
	}

	// Property accessors

	public String getName() {
		return this.name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getSex() {
		return this.sex;
	}

	public void setSex(String sex) {
		this.sex = sex;
	}

	public Timestamp getBorn() {
		return this.born;
	}

	public void setBorn(Timestamp born) {
		this.born = born;
	}

	public String getProfession() {
		return this.profession;
	}

	public void setProfession(String profession) {
		this.profession = profession;
	}

}