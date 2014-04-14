package CalGUI;

import javax.swing.JOptionPane;

public class Calculator {
	static OnlyStringGUI strGUI;
	static BoardGUI bGUI;
	static final int strType=1;
	static final int bType=2;
	static int type;  
	public static void main(String[] args)
	{
		strGUI=new OnlyStringGUI();
		bGUI=new BoardGUI();
		type=1;
		strGUI.setVisible(true);
	}
	public static void changeType(int t)
	{
		if(bGUI==null || strGUI==null)
		{
			JOptionPane.showMessageDialog(null, "Error:the GUI is not established","Error",JOptionPane.WARNING_MESSAGE);
			return;
		}
		switch(t)
		{
		case 1:
			bGUI.setVisible(false);
			strGUI.setVisible(true);
			break;
		case 2:
			strGUI.setVisible(false);
			bGUI.setVisible(true);
			break;
		default:
		}
		type=t;
	}
}
//by ltf 2011-6-17
