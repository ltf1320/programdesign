package common;

//import java.sql.DriverManager;
import java.sql.Connection;
import java.sql.Statement;
import java.sql.ResultSet;
import javax.naming.*;
import javax.sql.DataSource;

public class Conn { 
	private InitialContext ct=null;
	protected Connection con=null;
	private DataSource ds=null;
	private Statement st=null;
	private ResultSet rs=null;
	
//获取连接	
	public Conn(){
		try{
			ct=new InitialContext();//准备JNDI的访问环境			
			ds=(DataSource)ct.lookup("java:comp/env/jdbc/connectionPool");
			   //jdbc/connectionPool为连接池名
			   //java:comp/env是环境命名上下文,
			   //JDBC数据源引用在java:comp/env/jdbc 子上下文中声明
			con=ds.getConnection();			
		}catch(Exception e){
			e.printStackTrace();
		}
	}
	//执行查询
	public ResultSet executeQuery(String sql){		
			try{
				st=con.createStatement();
				rs=st.executeQuery(sql);				
			}catch(Exception e){
				e.printStackTrace();
			}
			return rs;		
	}
	//执行修改
	public int executeUpdate(String sql){		
			int count=0;
			try{
				st=con.createStatement();
				count=st.executeUpdate(sql);
				if(count!=0){
					con.commit();
				}
			}catch(Exception e){
				e.printStackTrace();
			}
			return count;		
	}
	public void close(){
		try{
			if(rs!=null){
				rs.close();
			}
			if(st!=null){
				st.close();
			}
			if(con!=null){
				con.close();
				con=null;
			}
		}catch(Exception e){
			e.printStackTrace();
			System.out.println("由于未知原因,关闭连接过程中出现异常");
		}
	}
	public Connection returnConn(){
		return con;
	}
}