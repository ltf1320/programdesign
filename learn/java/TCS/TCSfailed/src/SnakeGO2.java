import javax.swing.JOptionPane;


public class SnakeGO2 extends SnakeGO {
	public SnakeGO2()
	{
		super();
		Tgrid=TCSgrid2.getTCSgrid2();
	}
	public void run()
	{
		running=true;
		Tgrid.snake.reset(Tgrid,2,1);
		((TCSgrid2)Tgrid).snake2.reset(Tgrid,2,2);
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
					stopGame(2);
			}
			try{
				MoveOn(((TCSgrid2)Tgrid).snake2);
				Tgrid.repaint();
			}catch(TCSRunningException e)
			{
					stopGame(1);
			}
			try {
				sleep(Tgrid.sleepTime);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
		
	}
	public void stopGame(int a)
	{
		running=false;
		JOptionPane.showMessageDialog(Tgrid,"Player "+a+" wins");
	}
}
