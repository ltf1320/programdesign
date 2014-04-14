import javax.swing.JOptionPane;


public class SnakeGO extends Thread {
	TCSgrid Tgrid;
	public final int baseSleepTime=10;
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
		int time1 = 0,time2=0;
		if(Tgrid.numOfPler==1)
		{
			Tgrid.snake1.reset(Tgrid,1,1);
		}
		else
		{
			Tgrid.snake1.reset(Tgrid,2,1);
			Tgrid.snake2.reset(Tgrid,2,2);
		}
		score=0;
		Tgrid.createFood();
		if(Tgrid.numOfPler==1)
		{
			while(running)
			{
				if(pause==true)
					try {
						sleep(Tgrid.snake1.sleepTime);
						continue;
					} catch (InterruptedException e) {
						e.printStackTrace();
					}
				try{
					MoveOn(Tgrid.snake1);
					Tgrid.repaint();
				}catch(TCSRunningException e)
				{
					switch(e.getErrorNum())
					{
					case TCSRunningException.HitWall:
					case TCSRunningException.HitSelf:
					JOptionPane.showMessageDialog(Tgrid,"Your Score:"+score, "GameOver:",JOptionPane.YES_OPTION);
					stopGame();
						break;
					}
				}
				try {
					sleep(Tgrid.snake1.sleepTime);
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
		}
		else if(Tgrid.numOfPler==2)
		{
			while(running)
			{
				if(pause==true)
					try {
						sleep(baseSleepTime);
						continue;
					} catch (InterruptedException e) {
						e.printStackTrace();
					}
				try{
				try{
					if(time1>=Tgrid.snake1.sleepTime)
					{
						MoveOn(Tgrid.snake1);
						time1=0;
					}
				}catch(TCSRunningException e)
				{
					switch(e.getErrorNum())
					{
					case TCSRunningException.HitWall:
					case TCSRunningException.HitSelf:
					throw new LostException(e.getErrorNum(),1);
					}
				}
				try{
					if(time2>=Tgrid.snake2.sleepTime)
					{
						MoveOn(Tgrid.snake2);
						time2=0;
					}
					Tgrid.repaint();
				}catch(TCSRunningException e)
				{
					switch(e.getErrorNum())
					{
					case TCSRunningException.HitWall:
					case TCSRunningException.HitSelf:
					throw new LostException(e.getErrorNum(),1);
					}
				}
				if(Tgrid.playType==TCSgrid.jzType)
				{
					JZJudger();
				}
				}catch(LostException e)
				{
					switch(e.getErrorNum())
					{
					case TCSRunningException.HitWall:
					case TCSRunningException.HitSelf:
					case LostException.HeadCrash:
						
						if(e.getLostOne()!=0) JOptionPane.showMessageDialog(Tgrid,"Player "+(3-e.getLostOne())+" Wins!!", "GameOver:",JOptionPane.YES_OPTION);
						else JOptionPane.showMessageDialog(Tgrid,"DRAW", "GameOver:",JOptionPane.YES_OPTION);
						stopGame();
					}
				}
				try {
					sleep(baseSleepTime);
					time1+=baseSleepTime;
					time2+=baseSleepTime;
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
		}
		
	}
	void MoveOn(Snake snake) throws TCSRunningException
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
		if(isHitWall(snake)) throw new TCSRunningException(TCSRunningException.HitWall);
		if(isHitSelf(snake)) throw new TCSRunningException(TCSRunningException.HitSelf);
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
	
	void JZJudger() throws LostException
	{
		int nx=Tgrid.snake1.snakeList.get(0).x;
		int ny=Tgrid.snake1.snakeList.get(0).y;
		if(nx==Tgrid.snake2.snakeList.get(0).x && ny==Tgrid.snake2.snakeList.get(0).y)
		{
			if(Tgrid.snake1.length<Tgrid.snake2.length)
				throw new LostException(LostException.HeadCrash,2);
			else if(Tgrid.snake2.length<Tgrid.snake1.length)
				throw new LostException(LostException.HeadCrash,1);
			else throw new LostException(LostException.HeadCrash,0);
		}
		for(int i=1;i<Tgrid.snake2.length;i++)
		{
			if(nx==Tgrid.snake2.snakeList.get(i).x && ny==Tgrid.snake2.snakeList.get(i).y)
			{
				if(i==2)
					throw new LostException(LostException.HeadCrash,2);
				else throw new LostException(LostException.HeadCrash,1);
			}
		}
		
		
		nx=Tgrid.snake2.snakeList.get(0).x;
		ny=Tgrid.snake2.snakeList.get(0).y;
		if(nx==Tgrid.snake1.snakeList.get(0).x && ny==Tgrid.snake1.snakeList.get(0).y)
		{
			if(Tgrid.snake1.length<Tgrid.snake2.length)
				throw new LostException(LostException.HeadCrash,2);
			else if(Tgrid.snake2.length<Tgrid.snake1.length)
				throw new LostException(LostException.HeadCrash,1);
			else throw new LostException(LostException.HeadCrash,0);
		}
		for(int i=1;i<Tgrid.snake1.length;i++)
		{
			if(nx==Tgrid.snake1.snakeList.get(i).x && ny==Tgrid.snake1.snakeList.get(i).y)
			{
				if(i==2)
					throw new LostException(LostException.HeadCrash,1);
				else throw new LostException(LostException.HeadCrash,2);
			}
		}
		
	}
	
	private boolean isHitWall(Snake snake)
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
	
	private boolean isHitSelf(Snake snake)
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
	
	
	public void stopGame()
	{
		running=false;
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
