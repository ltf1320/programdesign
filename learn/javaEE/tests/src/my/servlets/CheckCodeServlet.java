package my.servlets;

import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.io.OutputStream;

import javax.imageio.ImageIO;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class CheckCodeServlet extends HttpServlet {

	/**
	 * Constructor of the object.
	 */
	public CheckCodeServlet() {
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
	public void doGet(HttpServletRequest req, HttpServletResponse res)
			throws ServletException, IOException {

		res.setContentType("image/jpeg");
		OutputStream out=res.getOutputStream();
		try{
			res.setHeader("programa", "no-cache");
			res.setHeader("Cache-Control", "no-cache");
			res.setDateHeader("Expires", 0);
			BufferedImage image=new BufferedImage(50,18,BufferedImage.TYPE_INT_RGB);
			Graphics g=image.getGraphics();
			g.setColor(Color.LIGHT_GRAY);
			g.fillRect(0, 0, 50, 18);
			String str="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			String code="";
			for(int i=0;i<4;i++)
			{
				int k=(int)(Math.random()*36);
				char c=str.charAt(k);
				code+=c;
			}
			HttpSession session=req.getSession();
			session.setAttribute("code", code);
			g.setColor(Color.BLACK);
			Font font=new Font("DIALOG",Font.ITALIC,15);
			g.drawString(code, 3, 15);
			ImageIO.write(image, "JPEG", out);
			out.flush();
			out.close();
		}
		finally{out.close();}
	}
	public void doPost(HttpServletRequest req, HttpServletResponse res)
			throws ServletException, IOException
			{
		doGet(req,res);
			}
}
