import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.awt.image.MemoryImageSource;
import java.util.LinkedList;
import java.util.Random;
public class TCSgrid extends JPanel{
	
	public static void main(String args[])
	{
		JFrame mainFrame=new JFrame();
		mainFrame.setLayout(new BorderLayout());
		mainFrame.add(new TCSgrid(),BorderLayout.CENTER);
		mainFrame.setSize(500,500);
		mainFrame.setVisible(true);
	}
	
	
	boolean canHitWall=false;
	int sleepTime=100;
	private static final long serialVersionUID = -3110360624677086931L;
	int rnum,cnum;
	int gridWidth,gridHeight;
	static TCSgrid instance;
	Color backgroundColor=Color.blue;
	Snake snake;
	snakeNode food;
	protected TCSgrid()
	{
		rnum=cnum=30;
		snake=new Snake();
	}
	public static TCSgrid getTCSgrid()
	{
		if(instance==null) {
			instance=new TCSgrid();
		}
		return instance;
	}
	public void paintComponent(Graphics g)
	{
		super.paintComponent(g);
		gridWidth=getSize().width/cnum;
		gridHeight=getSize().height/rnum;
		g.setColor(backgroundColor);
		for(int i=0;i<rnum;++i)
			for(int j=0;j<cnum;j++)
				g.fill3DRect(j*gridWidth, i*gridHeight, gridWidth, gridHeight, true);
		if(snake.length>0)
			g.drawImage(snake.snakeHead,snake.snakeList.get(0).x*gridWidth,snake.snakeList.get(0).y*gridHeight,gridWidth,gridHeight,this);
		for(int i=1;i<snake.length;++i)
		{
			g.drawImage(snake.snakeBody,snake.snakeList.get(i).x*gridWidth,snake.snakeList.get(i).y*gridHeight,gridWidth,gridHeight,this);
		}
		if(food!=null)
		{
			g.drawImage(snake.snakeFood,food.x*gridWidth,food.y*gridHeight,gridWidth,gridHeight,this);
		}
	}
	public void createFood()
	{
		Random rd=new Random();
		int x,y;
		LD: while(true)
		{
			x=(int) (rd.nextDouble()*cnum);
			y=(int) (rd.nextDouble()*rnum);
			for(int i=0;i<snake.length;++i)
			{
				if(x==snake.snakeList.get(i).x && y==snake.snakeList.get(i).y)
					continue LD;
			}
			break;
		}
		food=new snakeNode(x,y);
	}
}



