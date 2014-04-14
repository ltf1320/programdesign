import javax.swing.*;

import java.awt.*;
import java.awt.event.*;
public class GUI extends JFrame implements ActionListener{
	Container container;
	TCSgrid Tgrid;
	ButtonPane BPane;
	SnakeGO snakeGo;
	TCSMenu menu;
	static int numOfGame;
	GUI instance;
	GUI()
	{
		numOfGame=1;
		container=getContentPane();
		container.setLayout(new BorderLayout());
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Tgrid=TCSgrid.getTCSgrid();
		container.add(Tgrid,BorderLayout.CENTER);
		BPane=new ButtonPane(this);
		container.add(BPane,BorderLayout.SOUTH);
		this.addKeyListener(new KeyListen());
		menu=new TCSMenu();
		this.setJMenuBar(menu);
		this.addKeyListener(new KeyListen());
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
			if(numOfGame==1)
				snakeGo=new SnakeGO();
			if(numOfGame==2)
				snakeGo=new SnakeGO2();
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
	static void setNumOfGame(int a)
	{
		numOfGame=a;
	}
}

class ButtonPane extends JPanel
{
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
		StartB.addKeyListener(new KeyListen());    //我也不知道为什么键盘监听器要安在按钮上，但只有这样才能执行..
		add(StartB);
		add(PauseB);
		add(ContinueB);
		ContinueB.setVisible(false);
	}
}

class KeyListen extends KeyAdapter
{
	TCSgrid Tgrid;
	KeyListen()
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
		default: return;
		}
		if(d+Tgrid.snake.ndirection==0) //防止相反方向
			return;
		Tgrid.snake.setDirection(d);
		
	}
	
}

class TCSMenu extends JMenuBar
{
	JMenu StartMenu;
	JMenu OptionMenu;
	JMenu LeverMenu;
	JMenuItem canThrowWall,noThrowWall;
	Listener listener;
	TCSMenu()
	{
		listener=new Listener();
		
		StartMenu=new JMenu("开始");
		JMenuItem Game;
		Game=new JMenuItem("单人游戏");
		Game.addActionListener(listener);
		StartMenu.add(Game);
		Game=new JMenuItem("双人游戏");
		Game.addActionListener(listener);
		StartMenu.add(Game);
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
			
			if(arg0.getActionCommand().equals("单人游戏"))
			{
				Tgrid=TCSgrid.getTCSgrid();
				GUI.setNumOfGame(1);
			}
			if(arg0.getActionCommand().equals("双人游戏"))
			{
				Tgrid=TCSgrid2.getTCSgrid2();
				GUI.setNumOfGame(2);
			}
			if(arg0.getActionCommand().equals("可以穿墙"))
			{
				Tgrid.canHitWall=true;
				canThrowWall.setVisible(false);
				noThrowWall.setVisible(true);
			}
			if(arg0.getActionCommand().equals("不可以穿墙"))
			{
				Tgrid.canHitWall=false;
				canThrowWall.setVisible(true);
				noThrowWall.setVisible(false);
			}
			if(arg0.getActionCommand().equals("容易"))
			{
				Tgrid.sleepTime=500;
			}
			if(arg0.getActionCommand().equals("一般"))
			{
				Tgrid.sleepTime=100;
			}
			if(arg0.getActionCommand().equals("困难"))
			{
				Tgrid.sleepTime=40;
			}
			if(arg0.getActionCommand().equals("变态"))
			{
				Tgrid.sleepTime=10;
			}
			
		}
		
	}
}

