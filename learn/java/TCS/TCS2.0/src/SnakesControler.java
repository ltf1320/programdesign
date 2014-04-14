import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;


public class SnakesControler extends Thread {
	public static final int baseSleepTime=5;
	TCSgrid Tgrid;
	boolean running,pause;
	SnakeGO[] runs;
	public SnakesControler()
	{
		Tgrid=TCSgrid.getTCSgrid();
	}
	public void run()
	{
		boolean ready;
		running=true;
		runs=new SnakeGO[Tgrid.numOfPler];
		for(int i=0;i<Tgrid.numOfPler;i++)
		{
			runs[i]=new SnakeGO(Tgrid.snakes[i],i);
		}
		while(running)
		{
			try {
				sleep(baseSleepTime);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			for(int i=0;i<Tgrid.numOfPler;i++)
			{
				runs[i]=new SnakeGO(Tgrid.snakes[i],i);
				runs[i].start();
			}
			ready=true;
			for(int i=0;i<Tgrid.numOfPler;i++)
				if(!Tgrid.isReady[i]) {
					ready=false;
					break;
				}
			if(ready)
			{
				for(int i=0;i<Tgrid.numOfPler;i++)
					Tgrid.isReady[i]=false;
				Tgrid.repaint();
			}
		}
	}
	
	
	public void stopGame(int a)
	{
		for(int i=0;i<Tgrid.numOfPler;i++)
			runs[i].running=false;
		running=false;
	}
	public void pauseGame()
	{
		for(int i=0;i<Tgrid.numOfPler;i++)
			runs[i].pauseGame();
		
		pause=true;
	}
	public void continueGame()
	{
		for(int i=0;i<Tgrid.numOfPler;i++)
			runs[i].continueGame();
		pause=false;
	}
}
