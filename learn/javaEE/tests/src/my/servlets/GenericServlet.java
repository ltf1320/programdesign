package my.servlets;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.ServletRequest;
import javax.servlet.ServletResponse;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class GenericServlet extends HttpServlet {

	/**
	 * Constructor of the object.
	 */
	public GenericServlet() {
		super();
	}

	public void service(ServletRequest req,ServletResponse res) throws ServletException,IOException
	{
		doResponse("Hello:",res);
	}
	
	public String getServletInfo()
	{
		return "Servlet Example";
	}
	
	public void doResponse(String str,ServletResponse res) throws ServletException,IOException
	{
		PrintWriter out=res.getWriter();
		out.println(str);
		out.println(getServletInfo());
		out.close();
	}
}
