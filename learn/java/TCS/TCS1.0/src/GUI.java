import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
public class GUI extends JFrame implements ActionListener{
	Container container;
	TCSgrid Tgrid;
	ButtonPane BPane;
	SnakeGO snakeGo;
	GUI()
	{
		container=getContentPane();
		container.setLayout(new BorderLayout());
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Tgrid=TCSgrid.getTCSgrid();
		container.add(Tgrid,BorderLayout.CENTER);
		BPane=new ButtonPane(this);
		container.add(BPane,BorderLayout.SOUTH);
		this.addKeyListener(new KeyListen());
		snakeGo=new SnakeGO();
		
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
		return;
	}
}

class ButtonPane extends JPanel
{
	private static final long serialVersionUID = 2401040040368920070L;
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
		StartB.addKeyListener(new KeyListen());
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
		if(d+Tgrid.snake.direction==0) //防止相反方向
			return;
		Tgrid.snake.setDirection(d);
		
	}
}