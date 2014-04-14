package graphics;
import java.awt.Graphics;

import javax.swing.*;

import java.awt.*;
import java.awt.event.*;
import java.util.LinkedList;
import java.util.ListIterator;

public class GraText {
	JFrame MainFrame;
	Container container;
	TCSgrid Tgrid;
	Snake snake;
	public GraText()
	{
		MainFrame=new JFrame();
		MainFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		MainFrame.setLayout(new BorderLayout());
		container=MainFrame.getContentPane();
		Tgrid=TCSgrid.getTCSgrid();
		container.add(Tgrid,BorderLayout.CENTER);
		MainFrame.setSize(500,500);
		MainFrame.setVisible(true);
	}
	public static void main(String[] args)
	{
		GraText text=new GraText();
	}
}

class TCSgrid extends JPanel
{
	private static final long serialVersionUID = 8484465212118404968L;
	static TCSgrid instance;
	int rnum,cnum;
	int gridWidth,gridHeight;
	private Color color=Color.blue;
	
	Snake snake;
	
	private TCSgrid()
	{
		rnum=cnum=30;
		gridWidth=getSize().width/cnum;
		gridHeight=getSize().height/rnum;
		snake=new Snake(this);
	}
	public static TCSgrid getTCSgrid()
	{
		if(instance==null)
			instance=new TCSgrid();
		return instance;
	}
	public void paintComponent(Graphics g)
	{
		super.paintComponent(g);
		gridWidth=getSize().width/cnum;
		gridHeight=getSize().height/rnum;
		g.draw3DRect(0,0, cnum*gridWidth,rnum*gridHeight, true);
		for(int i=0;i<cnum;++i)
			for(int j=0;j<rnum;++j)
			{
				g.setColor(color);
				g.fill3DRect(i*gridWidth,j*gridHeight, gridWidth, gridHeight, true);
			}
		g.drawImage(snake.snakeHead, snake.snakeList.get(0).x*gridWidth, snake.snakeList.get(0).y*gridHeight,gridWidth,gridHeight, this);
		for(int i=1;i<snake.length;++i)
			g.drawImage(snake.snakeBody,snake.snakeList.get(i).x*gridWidth, snake.snakeList.get(i).y*gridHeight,gridWidth,gridHeight, this);
	}
}

class Snake
{
	int direction,length;
	LinkedList<SnakeNode> snakeList;
	public static final int up=0;
	public static final int right=1;
	public static final int down=2;
	public static final int left=3;
	Image snakeHead,snakeBody;
	public Snake(TCSgrid t)
	{
		reset(t);
	}
	public void reset(TCSgrid t)
	{
		snakeList=new LinkedList<SnakeNode>();
		setDirection(right);
		length=3;
		snakeHead=Toolkit.getDefaultToolkit().getImage("snakeHead.gif");
		snakeBody=Toolkit.getDefaultToolkit().getImage("snakeBody.gif");
		for(int i=0;i<length;++i)
			snakeList.add(new SnakeNode(t.cnum/2-i,t.rnum/2));	
	}
	public int getDirection() {
		return direction;
	}
	public void setDirection(int direction) {
		this.direction = direction;
	}
}

class SnakeNode
{
	int x,y;
	public SnakeNode(int x,int y)
	{
		this.x=x;
		this.y=y;
	}
}