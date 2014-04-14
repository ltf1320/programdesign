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
		Tgrid.snake.reset(Tgrid,1,1);
		score=0;
		Tgrid.createFood();
		while(running)
		{
			if(pause==true)
				try {
					sleep(Tgrid.sleepTime);
					continue;
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			try{
				
				MoveOn(Tgrid.snake);
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
				sleep(Tgrid.sleepTime);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
		
	}
	void MoveOn(Snake snk) throws TCSRunningException
	{
		nowx=snk.snakeList.getFirst().x;
		nowy=snk.snakeList.getFirst().y;
		switch(Tgrid.snake.direction)
		{
		case Snake.down:nowy+=1;break;
		case Snake.up:nowy-=1;break;
		case Snake.left:nowx-=1;break;
		case Snake.right:nowx+=1;break;
		}
		snk.ndirection=snk.direction;
		if(isHitWall(snk)) throw new TCSRunningException(TCSRunningException.HitWall);
		if(isHitSelf(snk)) throw new TCSRunningException(TCSRunningException.HitSelf);
		snk.snakeList.addFirst(new snakeNode(nowx,nowy));
		if(isEatFood())
		{
			score+=OneScore;
			Tgrid.createFood();
			snk.length++;
		}
		else
		{
			snk.snakeList.removeLast();
		}
	}
	private boolean isHitWall(Snake snk)
	{
		if(Tgrid.canHitWall)
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
	
	private boolean isHitSelf(Snake snk)
	{
		for(int i=0;i<snk.length;i++)
			if(nowx==snk.snakeList.get(i).x && nowy==snk.snakeList.get(i).y)
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
