package my.servlets;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.GenericServlet;
import javax.servlet.ServletException;
import javax.servlet.ServletRequest;
import javax.servlet.ServletResponse;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class request extends GenericServlet {

	@Override
	public void service(ServletRequest req, ServletResponse response)
			throws ServletException, IOException {
		// TODO Auto-generated method stub
		response.setContentType("text/html");
		PrintWriter out = response.getWriter();
		out.println("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\">");
		out.println("<HTML>");
		out.println("  <HEAD><TITLE>A Servlet</TITLE></HEAD>");
		out.println("  <BODY>");
		out.println("content length:"+req.getContentLength()+"<br>");
		out.println("content type:"+req.getContentType()+"<br");
		out.println("content protocol:"+req.getProtocol()+"<br>");
		out.println("request CharacterEncode:"+req.getCharacterEncoding()+"<br>");
		out.println("request servername:"+req.getServerName()+"<br>");
		out.println("request serverport"+req.getServerPort()+"<br>");
		out.println("request remote address:"+req.getRemoteAddr()+"<br>");
		out.println("request remote host:"+req.getRemoteHost()+"<br>");
		out.println("request parameter name:"+req.getParameter("name")+"<br>");
		out.println("  </BODY>");
		out.println("</HTML>");
		out.flush();
		out.close();
	}

	/**
	 * Constructor of the object.
	 */
	public request() {
		super();
	}


}
