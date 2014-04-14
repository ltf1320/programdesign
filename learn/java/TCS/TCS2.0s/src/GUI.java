import javax.swing.*;

import java.awt.*;
import java.awt.event.*;
public class GUI extends JFrame implements ActionListener{
	private static final long serialVersionUID = 1L;
	Container container;
	TCSgrid Tgrid;
	ButtonPane BPane;
	SnakeGO snakeGo;
	TCSMenu menu;
	GUI()
	{
		container=getContentPane();
		container.setLayout(new BorderLayout());
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Tgrid=TCSgrid.getTCSgrid();
		container.add(Tgrid,BorderLayout.CENTER);
		BPane=new ButtonPane(this);
		container.add(BPane,BorderLayout.SOUTH);
		menu=new TCSMenu();
		this.setJMenuBar(menu);
		this.setFocusable(true);
		setSize(500,500);
		setVisible(true);
	}
	public static void main(String args[])
	{
		GUI gui=new GUI();
	}
	public void actionPerformed(ActionEvent arg0) {
		if(arg0.getActionCommand().equals("开始"))
		{
			snakeGo=new SnakeGO();
			snakeGo.start();
		}
		if(arg0.getActionCommand().equals("暂停"))
		{
			snakeGo.pauseGame();
			BPane.PauseB.setVisible(false);
			BPane.ContinueB.setVisible(true);
		}
		if(arg0.getActionCommand().equals("继续"))
		{
			snakeGo.continueGame();
			BPane.PauseB.setVisible(true);
			BPane.ContinueB.setVisible(false);
		}
	}
	class ButtonPane extends JPanel
	{
		/**
		 * 
		 */
		private static final long serialVersionUID = 1L;
		JButton StartB,PauseB,ContinueB;
		public ButtonPane(GUI g)
		{
			StartB=new JButton("开始");
			PauseB=new JButton("暂停");
			ContinueB=new JButton("继续");
			setLayout(new FlowLayout());
			StartB.addActionListener(g);
			PauseB.addActionListener(g);
			ContinueB.addActionListener(g);
			StartB.addKeyListener(new KeyListen1());    //我也不知道为什么键盘监听器要安在按钮上，但只有这样才能执行..
			StartB.addKeyListener(new KeyListen2());
			add(StartB);
			add(PauseB);
			add(ContinueB);
			ContinueB.setVisible(false);
		}
	}



	class KeyListen1 extends KeyAdapter
	{
		TCSgrid Tgrid;
		KeyListen1()
		{
			super();
			Tgrid=TCSgrid.getTCSgrid();
		}
		public void keyPressed(KeyEvent arg0) {
			int d=0;
			switch(arg0.getKeyCode())
			{
			case KeyEvent.VK_LEFT:d=Snake.left;break;
			case KeyEvent.VK_RIGHT:d=Snake.right;break;
			case KeyEvent.VK_UP:d=Snake.up;break;
			case KeyEvent.VK_DOWN:d=Snake.down;break;
			case KeyEvent.VK_P:
			if(snakeGo.pause==false)
			{
				snakeGo.pauseGame();
				BPane.PauseB.setVisible(false);
				BPane.ContinueB.setVisible(true);
			}
			else
			{
				snakeGo.continueGame();
				BPane.PauseB.setVisible(true);
				BPane.ContinueB.setVisible(false);
			}
//			case KeyEvent.VK_CONTROL:Tgrid.createFoodh();
			default: return;
			}
			if(d+Tgrid.snake1.ndirection==0) //防止相反方向
				return;
			Tgrid.snake1.setDirection(d);
		}
	}
	class KeyListen2 extends KeyAdapter
	{
		TCSgrid Tgrid;
		KeyListen2()
		{
			super();
			Tgrid=TCSgrid.getTCSgrid();
		}
		public void keyPressed(KeyEvent arg0) {
			if(Tgrid.numOfPler<2) return;
			int d=0;
			switch(arg0.getKeyCode())
			{
			case KeyEvent.VK_A:d=Snake.left;break;
			case KeyEvent.VK_D:d=Snake.right;break;
			case KeyEvent.VK_W:d=Snake.up;break;
			case KeyEvent.VK_S:d=Snake.down;break;
//			case KeyEvent.VK_CONTROL:Tgrid.createFoodh();
			default: return;
			}
			if(d+Tgrid.snake2.ndirection==0) //防止相反方向
				return;
			Tgrid.snake2.setDirection(d);
		}
	}
}



class TCSMenu extends JMenuBar
{
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	JMenu StartMenu;
	JMenu OptionMenu;
	JMenu LeverMenu;
	JMenuItem canThrowWall,noThrowWall;
	Listener listener;
	TCSMenu()
	{
		listener=new Listener();
		
		StartMenu=new JMenu("开始");
		JMenuItem st;
		st=new JMenuItem("单人游戏");
		st.addActionListener(listener);
		StartMenu.add(st);
		JMenu sr=new JMenu("双人游戏");
		st=new JMenuItem("和谐世界");
		st.addActionListener(listener);
		sr.add(st);
		st=new JMenuItem("竞争时代");
		st.addActionListener(listener);
		sr.add(st);
		StartMenu.add(sr);
		st=new JMenuItem("退出");
		st.addActionListener(listener);
		StartMenu.add(st);
		add(StartMenu);
		
		
		OptionMenu=new JMenu("选项");
		canThrowWall=new JMenuItem("可以穿墙");
		canThrowWall.addActionListener(listener);
		OptionMenu.add(canThrowWall);
		noThrowWall=new JMenuItem("不可以穿墙");
		noThrowWall.addActionListener(listener);
		noThrowWall.setVisible(false);
		OptionMenu.add(noThrowWall);
		
		LeverMenu=new JMenu("难度");
		JMenuItem lever;
		lever=new JMenuItem("容易");
		lever.addActionListener(listener);
		LeverMenu.add(lever);
		lever=new JMenuItem("一般");
		lever.addActionListener(listener);
		LeverMenu.add(lever);
		lever=new JMenuItem("困难");
		lever.addActionListener(listener);
		LeverMenu.add(lever);
		lever=new JMenuItem("变态");
		lever.addActionListener(listener);
		LeverMenu.add(lever);
		OptionMenu.add(LeverMenu);
		
		
		add(OptionMenu);
	}
	
	private class Listener implements ActionListener
	{
		TCSgrid Tgrid;
		public Listener()
		{
			Tgrid=TCSgrid.getTCSgrid();
		}
		public void actionPerformed(ActionEvent arg0) {
			if(arg0.getActionCommand().equals("可以穿墙"))
			{
				Tgrid.snake1.canHitWall=true;
				Tgrid.snake2.canHitWall=true;
				canThrowWall.setVisible(false);
				noThrowWall.setVisible(true);
			}
			if(arg0.getActionCommand().equals("不可以穿墙"))
			{
				Tgrid.snake1.canHitWall=false;
				Tgrid.snake2.canHitWall=false;
				canThrowWall.setVisible(true);
				noThrowWall.setVisible(false);
			}
			if(arg0.getActionCommand().equals("容易"))
			{
				Tgrid.snake1.sleepTime=500;
				Tgrid.snake2.sleepTime=500;
			}
			if(arg0.getActionCommand().equals("一般"))
			{
				Tgrid.snake1.sleepTime=100;
				Tgrid.snake2.sleepTime=100;
			}
			if(arg0.getActionCommand().equals("困难"))
			{
				Tgrid.snake1.sleepTime=40;
				Tgrid.snake2.sleepTime=40;
			}
			if(arg0.getActionCommand().equals("变态"))
			{
				Tgrid.snake1.sleepTime=10;
				Tgrid.snake2.sleepTime=10;
			}
			if(arg0.getActionCommand().equals("单人游戏"))
			{
				Tgrid.setNumOfPler(1);
			}
			if(arg0.getActionCommand().equals("和谐世界"))
			{
				Tgrid.setNumOfPler(2);
				Tgrid.setPleyType(TCSgrid.hxType);
			}
			if(arg0.getActionCommand().equals("竞争时代"))
			{
				Tgrid.setNumOfPler(2);
				Tgrid.setPleyType(TCSgrid.jzType);
			}
			if(arg0.getActionCommand().equals("退出"))
			{
				System.exit(0);
			}
		}
		
	}
}

