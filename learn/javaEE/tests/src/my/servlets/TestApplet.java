package my.servlets;

import java.applet.Applet;
import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;

public class TestApplet extends Applet {
	String strFont;
	public TestApplet() {
		super();
	}

	public void destroy() {
		// Put your code here
	}


	public String getAppletInfo() {
		return "This is my default applet created by Eclipse";
	}

	public void init() {
		// Put your code here
		strFont=getParameter("font");
	}

	public void start() {
		// Put your code here
	}
	public void paint(Graphics g)
	{
		Font f=new Font(strFont,Font.BOLD,30);
		g.setFont(f);
		g.setColor(Color.blue);
		g.drawString("jsp:plugin", 0, 30);
	}

	public void stop() {
		// Put your code here
	}

}
