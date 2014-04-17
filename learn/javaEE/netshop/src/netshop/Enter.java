package netshop;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class Enter extends HttpServlet {

	/**
	 * Constructor of the object.
	 */
	public Enter() {
		super();
	}

	/**
	 * The doPost method of the servlet. <br>
	 *
	 * This method is called when a form has its tag value method equals to post.
	 * 
	 * @param request the request send by the client to the server
	 * @param response the response send by the server to the client
	 * @throws ServletException if an error occurred
	 * @throws IOException if an error occurred
	 */
	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		HttpSession session=request.getSession();
		
		if(session.isNew())
		{
			Integer cnt=(Integer)this.getServletContext().getAttribute("webCnt");
			if(cnt==null)
				cnt=new Integer(0);
			cnt=cnt+1;
			this.getServletContext().setAttribute("webCnt", cnt);
		}
		String userName=(String)session.getAttribute("userName");
		if(userName==null)
			response.sendRedirect("login.jsp");
		else
			response.sendRedirect("goods.jsp");
	}
	public void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doPost(request,response);
	}
}
