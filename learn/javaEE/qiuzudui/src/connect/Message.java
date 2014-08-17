package connect;

import java.sql.Timestamp;

/**
 * Message entity. @author MyEclipse Persistence Tools
 */
public class Message extends AbstractMessage implements java.io.Serializable {

	// Constructors

	/** default constructor */
	public Message() {
	}

	/** minimal constructor */
	public Message(Users users, String cl1, Timestamp createTime, String title) {
		super(users, cl1, createTime, title);
	}

	/** full constructor */
	public Message(Users users, String cl1, String cl2, Timestamp createTime,
			String time, String title, String text, String opt1, String opt2,
			String opt3) {
		super(users, cl1, cl2, createTime, time, title, text, opt1, opt2, opt3);
	}

}
