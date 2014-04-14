import javax.swing.*;
import java.awt.*;
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
	private static final long serialVersionUID = -3110360624677086931L;
	int rnum,cnum;
	int gridWidth,gridHeight;
	static TCSgrid instance;
	int numOfPler;
	int playType;
	public static int hxType=1;
	public static int jzType=2;
	
	Color backgroundColor=Color.blue;
	Snake snake1;
	Snake snake2;
	snakeNode food;
	private TCSgrid()
	{
		rnum=cnum=25;
		numOfPler=1;
		snake1=new Snake();
		snake2=new Snake();
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
		if(snake1.length>0)
			g.drawImage(snake1.snakeHead,snake1.snakeList.get(0).x*gridWidth,snake1.snakeList.get(0).y*gridHeight,gridWidth,gridHeight,this);
		for(int i=1;i<snake1.length;++i)
		{
			g.drawImage(snake1.snakeBody,snake1.snakeList.get(i).x*gridWidth,snake1.snakeList.get(i).y*gridHeight,gridWidth,gridHeight,this);
		}
		if(numOfPler==2)
		{
			if(snake2.length>0)
				g.drawImage(snake2.snakeHead,snake2.snakeList.get(0).x*gridWidth,snake2.snakeList.get(0).y*gridHeight,gridWidth,gridHeight,this);
			for(int i=1;i<snake2.length;++i)
			{
				g.drawImage(snake2.snakeBody,snake2.snakeList.get(i).x*gridWidth,snake2.snakeList.get(i).y*gridHeight,gridWidth,gridHeight,this);
			}
		}
		if(food!=null)
		{
			g.drawImage(Snake.snakeFood,food.x*gridWidth,food.y*gridHeight,gridWidth,gridHeight,this);
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
			for(int i=0;i<snake1.length;++i)
			{
				if(x==snake1.snakeList.get(i).x && y==snake1.snakeList.get(i).y)
					continue LD;
			}
			if(numOfPler==2)
				for(int i=0;i<snake2.length;i++)
				{
					if(x==snake2.snakeList.get(i).x && y==snake2.snakeList.get(i).y)
						continue LD;
				}
			break;
		}
		food=new snakeNode(x,y);
	}
	public void createFoodh1()
	{
		int nowx,nowy;
		TCSgrid Tgrid=TCSgrid.getTCSgrid();
		nowx=Tgrid.snake1.snakeList.getFirst().x;
		nowy=Tgrid.snake1.snakeList.getFirst().y;
		switch(Tgrid.snake1.direction)
		{
		case Snake.down:nowy+=1;break;
		case Snake.up:nowy-=1;break;
		case Snake.left:nowx-=1;break;
		case Snake.right:nowx+=1;break;
		}
		food=new snakeNode(nowx,nowy);
	}
	void setNumOfPler(int n)
	{
		numOfPler=n;
	}
	void setPleyType(int n)
	{
		playType=n;
	}
}



