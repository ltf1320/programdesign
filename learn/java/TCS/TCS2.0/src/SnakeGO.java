import javax.swing.JOptionPane;


public class SnakeGO extends Thread {
	Snake snake;
	boolean running,pause;
	int nowx,nowy;
	int score;
	public static int OneScore=10;
	TCSgrid Tgrid;
	int num;
	public SnakeGO(Snake snake,int num)
	{
		this.num=num;
		this.snake=snake;
		running=pause=false;
		Tgrid=TCSgrid.getTCSgrid();
	}
	public void run()
	{
		running=true;
		score=0;
		int time=0;
		while(running)
		{
			time=0;
			if(pause==true)
				try {
					sleep(SnakesControler.baseSleepTime);
					Tgrid.ready(num);
					continue;
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			if(Tgrid.isReady[num]==true)
				try {
					sleep(SnakesControler.baseSleepTime);
					continue;
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			try{
				MoveOn();
				Tgrid.ready(num);
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
				time+=SnakesControler.baseSleepTime;
				if(time<snake.sleepTime)
				{
					Tgrid.ready(num);
					sleep(SnakesControler.baseSleepTime);
					continue;
				}
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
		
	}
	void MoveOn() throws TCSRunningException
	{
		nowx=snake.snakeList.getFirst().x;
		nowy=snake.snakeList.getFirst().y;
		switch(snake.direction)
		{
		case Snake.down:nowy+=1;break;
		case Snake.up:nowy-=1;break;
		case Snake.left:nowx-=1;break;
		case Snake.right:nowx+=1;break;
		}
		snake.ndirection=snake.direction;
		if(isHitWall()) throw new TCSRunningException(TCSRunningException.HitWall);
		if(isHitSelf()) throw new TCSRunningException(TCSRunningException.HitSelf);
		snake.snakeList.addFirst(new snakeNode(nowx,nowy));
		if(isEatFood())
		{
			score+=OneScore;
			Tgrid.createFood();
			snake.length++;
		}
		else
		{
			snake.snakeList.removeLast();
		}
	}
	private boolean isHitWall()
	{
		if(snake.canHitWall)
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
		for(int i=0;i<snake.length;i++)
			if(nowx==snake.snakeList.get(i).x && nowy==snake.snakeList.get(i).y)
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
