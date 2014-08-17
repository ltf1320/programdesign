package connect;

import java.util.Set;

/**
 * Users entity. @author MyEclipse Persistence Tools
 */
public class Users extends AbstractUsers implements java.io.Serializable {

	// Constructors

	/** default constructor */
	public Users() {
	}

	/** minimal constructor */
	public Users(String userName, String pwd, String sex) {
		super(userName, pwd, sex);
	}

	/** full constructor */
	public Users(String userName, School school, String name, String pwd,
			String sex, String qq, String email, String phone, Set messages) {
		super(userName, school, name, pwd, sex, qq, email, phone, messages);
	}

}
