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
		if(arg0.getActionCommand().equals("��ʼ"))
		{
			snakeGo=new SnakeGO();
			snakeGo.start();
		}
		if(arg0.getActionCommand().equals("��ͣ"))
		{
			snakeGo.pauseGame();
			BPane.PauseB.setVisible(false);
			BPane.ContinueB.setVisible(true);
		}
		if(arg0.getActionCommand().equals("����"))
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
			StartB=new JButton("��ʼ");
			PauseB=new JButton("��ͣ");
			ContinueB=new JButton("����");
			setLayout(new FlowLayout());
			StartB.addActionListener(g);
			PauseB.addActionListener(g);
			ContinueB.addActionListener(g);
			StartB.addKeyListener(new KeyListen1());    //��Ҳ��֪��Ϊʲô���̼�����Ҫ���ڰ�ť�ϣ���ֻ����������ִ��..
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
			if(d+Tgrid.snake1.ndirection==0) //��ֹ�෴����
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
			if(d+Tgrid.snake2.ndirection==0) //��ֹ�෴����
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
		
		StartMenu=new JMenu("��ʼ");
		JMenuItem st;
		st=new JMenuItem("������Ϸ");
		st.addActionListener(listener);
		StartMenu.add(st);
		JMenu sr=new JMenu("˫����Ϸ");
		st=new JMenuItem("��г����");
		st.addActionListener(listener);
		sr.add(st);
		st=new JMenuItem("����ʱ��");
		st.addActionListener(listener);
		sr.add(st);
		StartMenu.add(sr);
		st=new JMenuItem("�˳�");
		st.addActionListener(listener);
		StartMenu.add(st);
		add(StartMenu);
		
		
		OptionMenu=new JMenu("ѡ��");
		canThrowWall=new JMenuItem("���Դ�ǽ");
		canThrowWall.addActionListener(listener);
		OptionMenu.add(canThrowWall);
		noThrowWall=new JMenuItem("�����Դ�ǽ");
		noThrowWall.addActionListener(listener);
		noThrowWall.setVisible(false);
		OptionMenu.add(noThrowWall);
		
		LeverMenu=new JMenu("�Ѷ�");
		JMenuItem lever;
		lever=new JMenuItem("����");
		lever.addActionListener(listener);
		LeverMenu.add(lever);
		lever=new JMenuItem("һ��");
		lever.addActionListener(listener);
		LeverMenu.add(lever);
		lever=new JMenuItem("����");
		lever.addActionListener(listener);
		LeverMenu.add(lever);
		lever=new JMenuItem("��̬");
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
			if(arg0.getActionCommand().equals("���Դ�ǽ"))
			{
				Tgrid.snake1.canHitWall=true;
				Tgrid.snake2.canHitWall=true;
				canThrowWall.setVisible(false);
				noThrowWall.setVisible(true);
			}
			if(arg0.getActionCommand().equals("�����Դ�ǽ"))
			{
				Tgrid.snake1.canHitWall=false;
				Tgrid.snake2.canHitWall=false;
				canThrowWall.setVisible(true);
				noThrowWall.setVisible(false);
			}
			if(arg0.getActionCommand().equals("����"))
			{
				Tgrid.snake1.sleepTime=500;
				Tgrid.snake2.sleepTime=500;
			}
			if(arg0.getActionCommand().equals("һ��"))
			{
				Tgrid.snake1.sleepTime=100;
				Tgrid.snake2.sleepTime=100;
			}
			if(arg0.getActionCommand().equals("����"))
			{
				Tgrid.snake1.sleepTime=40;
				Tgrid.snake2.sleepTime=40;
			}
			if(arg0.getActionCommand().equals("��̬"))
			{
				Tgrid.snake1.sleepTime=10;
				Tgrid.snake2.sleepTime=10;
			}
			if(arg0.getActionCommand().equals("������Ϸ"))
			{
				Tgrid.setNumOfPler(1);
			}
			if(arg0.getActionCommand().equals("��г����"))
			{
				Tgrid.setNumOfPler(2);
				Tgrid.setPleyType(TCSgrid.hxType);
			}
			if(arg0.getActionCommand().equals("����ʱ��"))
			{
				Tgrid.setNumOfPler(2);
				Tgrid.setPleyType(TCSgrid.jzType);
			}
			if(arg0.getActionCommand().equals("�˳�"))
			{
				System.exit(0);
			}
		}
		
	}
}

