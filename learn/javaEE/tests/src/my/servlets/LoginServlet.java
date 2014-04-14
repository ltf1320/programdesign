package my.servlets;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class LoginServlet extends HttpServlet {

	/**
	 * Constructor of the object.
	 */
	public LoginServlet() {
		super();
	}

	/**
	 * The doGet method of the servlet. <br>
	 *
	 * This method is called when a form has its tag value method equals to get.
	 * 
	 * @param request the request send by the client to the server
	 * @param response the response send by the server to the client
	 * @throws ServletException if an error occurred
	 * @throws IOException if an error occurred
	 */
	public void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {

		response.setContentType("text/html;charset=gbk");
		PrintWriter out = response.getWriter();
		try
		{
			String myUserName=this.getInitParameter("name");
			String myPassWord=this.getInitParameter("password");
			HttpSession session=request.getSession();
			String scode=(String)session.getAttribute("code");
			String userName=(String) request.getParameter("name");
			String PassWord= (String) request.getParameter("password");
			String code=(String)request.getParameter("code");
			out.println("<html><body>");
			out.println("<br>");
			if(!code.toUpperCase().equals(scode)){out.println("ÑéÖ¤Âë´íÎó£¡");}
			else if(userName.equals(myUserName)&&PassWord.equals(myPassWord))
			{
				out.println("µÇÂ¼³É¹¦£¡");
			}else out.println("µÇÂ¼Ê§°Ü£¡");
			out.println("</body></html>");
		}
		catch(Exception e)
		{
			out.println("Error:"+e.getMessage());
		}
		finally{
			out.close();}
	}

public void doPost(HttpServletRequest request, HttpServletResponse response)
		throws ServletException, IOException {
	doGet(request,response);
}
}
