package common;
//import java.sql.DriverManager;
import java.sql.Connection;
import java.sql.Statement;
import java.sql.ResultSet;
import javax.naming.*;
import javax.sql.DataSource;

public class Conn { 
	DataSource ds = null;
	Connection con=null;
	Statement stmt=null;
	ResultSet rs=null;
//获取连接	
	public Connection connection()
	{
		System.out.println("create conntion!!!!!!!!");		
		try{
			InitialContext ctx=new InitialContext();
			ds=(DataSource)ctx.lookup("java:comp/env/jdbc/connectionPool");
			       //jdbc/connectionPool为连接池名
			   //java:comp/env是环境命名上下文,
			   //JDBC数据源引用在java:comp/env/jdbc 子上下文中声明
			con = ds.getConnection();
		}catch(Exception e){
			e.printStackTrace();
		}
		return con;		
	}
//关闭连接
	public void close(){
		try{			
			if(con!=null){
			  con.close();
			  con=null;
			}
		}catch(Exception e){
			System.out.println("由于未知原因,关闭连接过程中出现异常");
		}
	}
	
	public Connection returnConn(){		
		return con;
	}
}