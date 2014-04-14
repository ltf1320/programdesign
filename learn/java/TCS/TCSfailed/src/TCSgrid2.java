import java.awt.Graphics;


public class TCSgrid2 extends TCSgrid {
	Snake snake2;
	protected TCSgrid2()
	{
		super();
		snake2=new Snake();
	}
	public static TCSgrid2 getTCSgrid2()
	{
		if(instance==null)
			instance=new TCSgrid2();
		return (TCSgrid2) instance;
	}
	
	public void paintComponent(Graphics g)
	{
		super.paintComponent(g);
		if(snake2.length>0)
		{
			g.drawImage(snake2.snakeHead,snake.snakeList.get(0).x*gridWidth,snake2.snakeList.get(0).y*gridHeight,gridWidth,gridHeight,this);
			for(int i=1;i<snake2.length;++i)
			{
				g.drawImage(snake2.snakeBody,snake.snakeList.get(i).x*gridWidth,snake2.snakeList.get(i).y*gridHeight,gridWidth,gridHeight,this);
			}
		}
	}
}
