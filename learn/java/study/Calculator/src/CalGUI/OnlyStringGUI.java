package CalGUI;
import java.awt.*;
import java.awt.event.*;
import java.math.BigDecimal;

import StringCal.*;

import javax.swing.*;

public class OnlyStringGUI extends JFrame {
	private static final long serialVersionUID = 3390510380017245887L;
	JTextArea input;
	JTextArea output;
	Button quit;
	Button cls;
	Button cal;
	public OnlyStringGUI()
	{
		setDefaultCloseOperation(DO_NOTHING_ON_CLOSE);
		GridBagLayout gridbag=new GridBagLayout();
		GridBagConstraints c=new GridBagConstraints();
		setLayout(gridbag);
		JLabel label=null;
		label=new JLabel("请输入一个算式：");
		c.fill=GridBagConstraints.BOTH;
		c.gridwidth=GridBagConstraints.REMAINDER;
		gridbag.setConstraints(label, c);
		add(label);
		
		c.weighty=0.0;
		input=new JTextArea(5,10);
		input.addKeyListener(new TextTypeListener());
		gridbag.setConstraints(input, c);
		add(input);
		
		label=new JLabel("结果：");
		c.weighty=0.0;
		gridbag.setConstraints(label, c);
		add(label);
		
		output=new JTextArea();
		output.setEditable(false);
		c.weightx=1.0;
		c.weighty=1.0;
		gridbag.setConstraints(output, c);
		add(output);
		
		cal=new Button("Cal");
		c.weightx=1.0;
		c.weighty=0.0;
		c.gridwidth=1;
		c.insets=new Insets(10,10,0,10);
		cal.addActionListener(new ButtonListenerToCal());
		gridbag.setConstraints(cal, c);
		add(cal);
		
		cls=new Button("cls");
		c.gridwidth=GridBagConstraints.REMAINDER;
		cls.addActionListener(new ButtonListenerToCls());
		gridbag.setConstraints(cls, c);
		add(cls);
		
		//澶勭悊绐楀彛鍏抽棴淇℃伅
		addWindowListener(new WindowAdapter()
		{
			public void windowClosing(WindowEvent e)
			{
				Object[] options={"Yes","Change the type","Cancel"};
				int re=JOptionPane.showOptionDialog(null, "Are you sure to quit?","waring",JOptionPane.YES_NO_CANCEL_OPTION,JOptionPane.QUESTION_MESSAGE,null,options,options[2]);
				if(re==JOptionPane.YES_OPTION){
					System.exit(0);
				}
				else if(re==JOptionPane.NO_OPTION)
				{
					Calculator.changeType(Calculator.bType);
				}
				else ;
			}
		});
		setSize(600,400);
		setLocation(300,100);
//		setVisible(true);
	}
	
	public class ButtonListenerToCal implements ActionListener
	{
		public void actionPerformed(ActionEvent arg0) {
			calInput();
		}
	}
	
	public class ButtonListenerToCls implements ActionListener
	{
		public void actionPerformed(ActionEvent arg0) {
			output.setText("");
			input.setText("");
		}
	}
	public class TextTypeListener implements KeyListener
	{
		public void keyPressed(KeyEvent e) {}
		public void keyReleased(KeyEvent e) {
			input.setText(input.getText().replaceAll("[^0-9|\\.|\\(|\\)|\\*|\\/|\\^|\\+|\\-)]", ""));
			if(e.getKeyChar()=='\n')
				calInput();
		}
		public void keyTyped(KeyEvent e) {
/*			if(e.getKeyChar()>='0'||e.getKeyChar()<='9'){
				input.append(""+e.getKeyChar());
				return;
			}
			switch(e.getKeyChar())
			{
			case '+':
			case '-':
			case '*':
			case '/':
			case '(':
			case ')':
			case '^':
			case '.':
				input.append(""+e.getKeyChar());
				break;
			case '\n':
				calInput();
				break;
			default:
			}
*/			
		}
		
	}
	
	public void calInput()
	{
		String s=input.getText();
		if(s.equals("")) return;
		BigDecimal res=null;
		try {
			res=StringCal.calculate(s);
		} catch (StringCalException e) {
			JOptionPane.showMessageDialog(null, e.getReason(),"Error",JOptionPane.WARNING_MESSAGE);
			output.append(s+"\n");
			return;
		}
		output.append(s);
		output.append("= "+res.toString()+"\n");
		input.setText("");
	}
	
	public static void main(String args[])
	{
		OnlyStringGUI s=new OnlyStringGUI();
		s.setVisible(true);
	}
}




