import java.awt.Image;
import java.awt.Toolkit;
import java.util.LinkedList;

public class Snake
{
	LinkedList<snakeNode> snakeList;
	int length,direction,ndirection;
	public final static int up=1;
	public final static int right=2;
	public final static int down=-1;
	public final static int left=-2;
	Image snakeHead;
	Image snakeBody;
	public static Image snakeFood;
	boolean canHitWall=false;
	int sleepTime=100;
	public Snake()
	{
		snakeFood=Toolkit.getDefaultToolkit().getImage("img\\snakeFood.gif");
		length=0;
	}
	public void reset(TCSgrid t,int an,int m)
	{
		direction=left;
		snakeList=new LinkedList<snakeNode>();
		length=3;
		if(m==1)
		{
			snakeHead=Toolkit.getDefaultToolkit().getImage("img\\snakeHead1.gif");
			snakeBody=Toolkit.getDefaultToolkit().getImage("img\\snakeBody1.gif");
		}
		else if(m==2)
		{
			snakeHead=Toolkit.getDefaultToolkit().getImage("img\\snakeHead2.gif");
			snakeBody=Toolkit.getDefaultToolkit().getImage("img\\snakeBody2.gif");
		}
		for(int i=0;i<length;++i)
		{
			snakeList.add(new snakeNode(t.cnum/2+i,t.rnum/(an+1)*m));
		}
	}
	
	void setLength(int length)
	{
		this.length=length;
	}
	void setDirection(int Direction)
	{
		direction=Direction;
	}
}

