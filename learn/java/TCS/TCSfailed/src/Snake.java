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
	Image snakeFood;
	public Snake()
	{
		snakeHead=Toolkit.getDefaultToolkit().getImage("snakeHead.gif");
		snakeBody=Toolkit.getDefaultToolkit().getImage("snakeBody.gif");
		snakeFood=Toolkit.getDefaultToolkit().getImage("snakeFood.gif");
		length=0;
	}
	public void reset(TCSgrid t,int n,int m)
	{
		direction=left;
		snakeList=new LinkedList<snakeNode>();
		length=3;
		for(int i=0;i<length;++i)
		{
			snakeList.add(new snakeNode(t.cnum/2+i,t.rnum/(n+1)*m));
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

class snakeNode
{
	int x,y;
	snakeNode(int x,int y)
	{
		this.x=x;
		this.y=y;
	}
}