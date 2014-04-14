import java.awt.Color;
import java.awt.Graphics;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.util.Random;

import javax.swing.*;
//Ì°³ÔÉßµÚ¶þ°æ
public class TCSgrid extends JPanel{
	private static final long serialVersionUID = -3110360624677086931L;
	int rnum,cnum;
	int gridWidth,gridHeight;
	static TCSgrid instance;
	Color backgroundColor=Color.blue;
	Snake[] snakes;
	snakeNode food;
	int numOfPler;
	boolean isReady[];
	private TCSgrid()
	{
		rnum=cnum=30;
		numOfPler=1;
	}
	void createSnake(int n)
	{
		numOfPler=n;
		snakes=new Snake[numOfPler];
		for(int i=0;i<numOfPler;i++)
			snakes[i]=new Snake();
		isReady=new boolean[numOfPler];
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
		if(snakes==null) return;
		for(int i=0;i<numOfPler;i++)
		{
			Snake snake=snakes[i];
			if(snake.length>0)
				g.drawImage(snake.snakeHead,snake.snakeList.get(0).x*gridWidth,snake.snakeList.get(0).y*gridHeight,gridWidth,gridHeight,this);
			for(int j=1;j<snake.length;++j)
			{
				g.drawImage(snake.snakeBody,snake.snakeList.get(i).x*gridWidth,snake.snakeList.get(i).y*gridHeight,gridWidth,gridHeight,this);
			}
			if(food!=null)
			{
				g.drawImage(snake.snakeFood,food.x*gridWidth,food.y*gridHeight,gridWidth,gridHeight,this);
			}
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
			for(int i=0;i<numOfPler;i++)
			{
				Snake snake=snakes[i];
				for(int j=0;j<snake.length;++j)
				{
					if(x==snake.snakeList.get(i).x && y==snake.snakeList.get(i).y)
						continue LD;
				}
			}
			break;
		}
		food=new snakeNode(x,y);
	}
	public void createFoodh()
	{
		int nowx,nowy;
		TCSgrid Tgrid=TCSgrid.getTCSgrid();
		nowx=Tgrid.snakes[0].snakeList.getFirst().x;
		nowy=Tgrid.snakes[0].snakeList.getFirst().y;
		switch(Tgrid.snakes[0].direction)
		{
		case Snake.down:nowy+=1;break;
		case Snake.up:nowy-=1;break;
		case Snake.left:nowx-=1;break;
		case Snake.right:nowx+=1;break;
		}
		food=new snakeNode(nowx,nowy);
	}
	void ready(int num)
	{
		isReady[num]=true;
	}
}
