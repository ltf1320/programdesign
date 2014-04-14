import javax.swing.JOptionPane;


public class SnakeGO extends Thread {
	TCSgrid Tgrid;
	boolean running,pause;
	int nowx,nowy;
	int score;
	public static int OneScore=10;
	public SnakeGO()
	{
		Tgrid=TCSgrid.getTCSgrid();
		running=pause=false;
	}
	public void run()
	{
		running=true;
		Tgrid.snake.reset(Tgrid);
		score=0;
		Tgrid.createFood();
		while(running)
		{
			if(pause==true)
				try {
					sleep(Tgrid.snake.sleepTime);
					continue;
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			try{
				MoveOn();
				Tgrid.repaint();
			}catch(TCSRunningException e)
			{
				switch(e.getErrorNum())
				{
				case TCSRunningException.HitWall:
				case TCSRunningException.HitSelf:
					stopGame(e.getErrorNum());
					break;
				}
			}
			try {
				sleep(Tgrid.snake.sleepTime);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
		
	}
	void MoveOn() throws TCSRunningException
	{
		nowx=Tgrid.snake.snakeList.getFirst().x;
		nowy=Tgrid.snake.snakeList.getFirst().y;
		switch(Tgrid.snake.direction)
		{
		case Snake.down:nowy+=1;break;
		case Snake.up:nowy-=1;break;
		case Snake.left:nowx-=1;break;
		case Snake.right:nowx+=1;break;
		}
		Tgrid.snake.ndirection=Tgrid.snake.direction;
		if(isHitWall()) throw new TCSRunningException(TCSRunningException.HitWall);
		if(isHitSelf()) throw new TCSRunningException(TCSRunningException.HitSelf);
		Tgrid.snake.snakeList.addFirst(new snakeNode(nowx,nowy));
		if(isEatFood())
		{
			score+=OneScore;
			Tgrid.createFood();
			Tgrid.snake.length++;
		}
		else
		{
			Tgrid.snake.snakeList.removeLast();
		}
	}
	private boolean isHitWall()
	{
		if(Tgrid.snake.canHitWall)
		{
			if(nowx<0) nowx=Tgrid.cnum-1;
			if(nowx>=Tgrid.cnum) nowx=0;
			if(nowy<0) nowy=Tgrid.rnum-1;
			if(nowy>=Tgrid.rnum) nowy=0;
		}
		else
		{
			if(nowx<0 || nowx>=Tgrid.cnum || nowy<0 || nowy>=Tgrid.rnum) return true;
		}
		return false;
	}
	
	private boolean isHitSelf()
	{
		for(int i=0;i<Tgrid.snake.length;i++)
			if(nowx==Tgrid.snake.snakeList.get(i).x && nowy==Tgrid.snake.snakeList.get(i).y)
				return true;
		return false;
	}
	
	private boolean isEatFood()
	{
		if(nowx==Tgrid.food.x && nowy==Tgrid.food.y) 
			return true;
		return false;
	}
	
	
	public void stopGame(int a)
	{
		running=false;
		JOptionPane.showMessageDialog(Tgrid,"Your Score:"+score, "GameOver:"+a,JOptionPane.YES_OPTION);
	}
	public void pauseGame()
	{
		pause=true;
	}
	public void continueGame()
	{
		pause=false;
	}
}
