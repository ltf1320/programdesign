package CalGUI;
import StringCal.*;
import javax.swing.*;

import java.awt.*;
import java.awt.event.*;
import java.math.BigDecimal;

public class BoardGUI extends JFrame{
	private static final long serialVersionUID = 1L;
	JTextArea output;
	JPanel numPanel;
	JPanel symPanel;
	boolean calculated=true;
	public BoardGUI()
	{
		setDefaultCloseOperation(DO_NOTHING_ON_CLOSE);
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
					Calculator.changeType(1);
				}
				else ;
			}
		});
		
		
		GridBagLayout gridbag=new GridBagLayout();
		GridBagConstraints c=new GridBagConstraints();
		setLayout(gridbag);
		c.fill=GridBagConstraints.BOTH;
		c.weightx=0.5;
		c.weighty=0.0;
		c.gridwidth=GridBagConstraints.REMAINDER;
		output=new JTextArea(5,10);
		output.setEditable(false);
		gridbag.setConstraints(output, c);
		add(output);
		
		numPanel=new JPanel();
		numPanel.setLayout(new GridLayout(4,3,1,1));
		JButton button=null;
		for(Integer i=1;i<10;++i)
		{
			button=new JButton(i.toString());
			button.addActionListener(new ButtonPressListener());
			numPanel.add(button);
		}
		button=new JButton("Backspace");
		button.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e) {
				output.setText(output.getText().substring(0,output.getText().length()-1));
			}
			
		});
		numPanel.add(button);
		button=new JButton("0");
		button.addActionListener(new ButtonPressListener());
		numPanel.add(button);
		button=new JButton(".");
		button.addActionListener(new ButtonPressListener());
		numPanel.add(button);
		c.weightx=0.8;
		c.weighty=0.2;
		c.insets=new Insets(10,0,0,10);
		c.gridwidth=1;
		gridbag.setConstraints(numPanel, c);
		add(numPanel);
		
		
		char[] syms={'-','+','/','*',' ',' ','^'};
		symPanel=new JPanel();
		symPanel.setLayout(new GridLayout(4,2,1,1));
		for(int i=0;i<7;++i)
		{
			button=new JButton(""+syms[i]);
			button.addActionListener(new ButtonPressListener());
			symPanel.add(button);
		}
		button=new JButton("=");
		button.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e) {
				if(calculated)
					output.setText("");
				calInput();
			}
		});
		symPanel.add(button);
		
		
		c.insets=new Insets(10,0,0,0);
		c.weightx=1.0;
		c.weighty=1.0;
		c.gridwidth=GridBagConstraints.REMAINDER;
		gridbag.setConstraints(symPanel, c);
		add(symPanel);
		
		setSize(550,450);
		setLocation(300,100);
		
	}
	public class ButtonPressListener implements ActionListener
	{
		public void actionPerformed(ActionEvent e) {
			if(calculated){
				output.setText("");
				calculated=false;
			}
			output.append(e.getActionCommand());
		}
		
	}
	public void calInput()
	{
		String s=output.getText();
		if(s.equals("")) return;
		BigDecimal res=null;
		try {
			res=StringCal.calculate(s);
		} catch (StringCalException e) {
			JOptionPane.showMessageDialog(null, e.getReason(),"Error",JOptionPane.WARNING_MESSAGE);
		}
		output.append("\n= "+res.toString()+"\n");
		calculated=true;
	}
	
	public static void main(String[] args)
	{
		BoardGUI s=new BoardGUI();
		s.setVisible(true);
	}
}