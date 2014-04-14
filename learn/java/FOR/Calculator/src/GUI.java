import javax.swing.*;

import java.awt.*;
import java.awt.event.*;
public class GUI{
	JFrame mainFrame=null;
	JPanel Pane=null;
	JTextArea textArea=null;
	caler cer=null;
	GUI()
	{
		mainFrame=new JFrame("Calculator");
		mainFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Pane=new JPanel();
		textArea=new JTextArea(3,3);
		cer=new caler();
		mainFrame.setLayout(new BorderLayout(10,10));
		Pane.setLayout(new GridLayout(4,5));
		JButton bu;
		bu=new JButton("1");
		bu.addActionListener(new ButtonListener());
		Pane.add(bu);
		bu=new JButton("2");
		bu.addActionListener(new ButtonListener());
		Pane.add(bu);
		bu=new JButton("3");
		bu.addActionListener(new ButtonListener());
		Pane.add(bu);
		bu=new JButton("+");
		bu.addActionListener(new ButtonListener());
		Pane.add(bu);
		bu=new JButton("-");
		bu.addActionListener(new ButtonListener());
		Pane.add(bu);
		bu=new JButton("4");
		bu.addActionListener(new ButtonListener());
		Pane.add(bu);
		bu=new JButton("5");
		bu.addActionListener(new ButtonListener());
		Pane.add(bu);
		bu=new JButton("6");
		bu.addActionListener(new ButtonListener());
		Pane.add(bu);
		bu=new JButton("*");
		bu.addActionListener(new ButtonListener());
		Pane.add(bu);
		bu=new JButton("/");
		bu.addActionListener(new ButtonListener());
		Pane.add(bu);
		bu=new JButton("7");
		bu.addActionListener(new ButtonListener());
		Pane.add(bu);
		bu=new JButton("8");
		bu.addActionListener(new ButtonListener());
		Pane.add(bu);
		bu=new JButton("9");
		bu.addActionListener(new ButtonListener());
		Pane.add(bu);
		bu=new JButton("(");
		bu.addActionListener(new ButtonListener());
		Pane.add(bu);
		bu=new JButton(")");
		bu.addActionListener(new ButtonListener());
		Pane.add(bu);
		bu=new JButton(".");
		bu.addActionListener(new ButtonListener());
		Pane.add(bu);
		bu=new JButton("0");
		bu.addActionListener(new ButtonListener());
		Pane.add(bu);
		bu=new JButton("=");
		bu.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent arg0) {
				cer.setString(textArea.getText());
				textArea.setText(""+cer.calculate());
			}
			
		});
		Pane.add(bu);
		bu=new JButton("^");
		bu.addActionListener(new ButtonListener());
		Pane.add(bu);
		bu=new JButton("cls");
		bu.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e)
			{
				textArea.setText("");
			}
		});
		Pane.add(bu);
		mainFrame.add("North",textArea);
		mainFrame.add(Pane);
		mainFrame.setSize(300,400);
		mainFrame.setVisible(true);
	}
	public static void main(String[] args)
	{
		GUI g=new GUI();
	}
	class ButtonListener implements ActionListener
	{
		public void actionPerformed(ActionEvent arg0) {
			textArea.append(arg0.getActionCommand());
		}
	}
}
