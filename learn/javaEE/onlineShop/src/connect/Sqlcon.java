package connect;

import java.sql.*;

public class Sqlcon {
	static final public String conurl="jdbc:mysql://localhost:3306/onlineshop";
	static final public String conuser="root";
	static final public String conpwd="abcd";
	
	public static Connection getCon() throws SQLException, ClassNotFoundException
	{
		Class.forName("com.mysql.jdbc.Driver");
		Connection con=DriverManager.getConnection(conurl, conuser, conpwd);
		return con;
	}
	
}
