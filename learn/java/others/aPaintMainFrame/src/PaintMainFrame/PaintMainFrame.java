/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package PaintMainFrame;

/**
 *
 * @author Chaos
 */
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class PaintMainFrame extends JFrame {
	JPanel commandPanel = new JPanel();
	JPanel colorPanel = new JPanel();
	JPanel mainPanel = new JPanel();
	
	JButton btnRed = new JButton("红色");
	JButton btnGreen = new JButton("绿色");
	JButton btnBlue = new JButton("蓝色");
	
        JButton btnComposite = new JButton("组合");
	JButton btnLine = new JButton("直线");
	JButton btnRectangle = new JButton("矩形");
	//JButton btnCircle = new JButton("�?);
	JButton btnExit = new JButton("关闭");
	
	PaintBoard paintBoard = new PaintBoard();
	
	public PaintMainFrame() {
		this.getContentPane().setLayout(new BorderLayout());
                
                btnComposite.addActionListener(new ActionListener() {
                        public void actionPerformed(ActionEvent e) {
                            btnComposite_actionPerformed(e);
                        }
                });
		
		btnLine.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				btnLine_actionPerformed(e);
			}
		});
		
		btnRectangle.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				btnRectangle_actionPerformed(e);
			}
		});
		
//		btnCircle.addActionListener(new ActionListener() {
//			public void actionPerformed(ActionEvent e) {
//				btnCircle_actionPerformed(e);
//			}
//		});
		
		btnExit.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				btnExit_actionPerformed(e);
			}
		});
		
		
		commandPanel.setLayout(new FlowLayout());
		commandPanel.add(btnLine);
		commandPanel.add(btnRectangle);
		//commandPanel.add(btnCircle);
                commandPanel.add(btnComposite);
		commandPanel.add(btnExit);
		
		btnRed.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				btnRed_actionPerformed(e);
			}
		});
		
		btnGreen.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				btnGreen_actionPerformed(e);
			}
		});
		
		btnBlue.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				btnBlue_actionPerformed(e);
			}
		});
		
		colorPanel.setLayout(new FlowLayout());
		colorPanel.add(btnRed, null);
		colorPanel.add(btnGreen, null);
		colorPanel.add(btnBlue, null);
		
		mainPanel.setLayout(new BorderLayout());
		mainPanel.add(commandPanel, BorderLayout.NORTH);
		mainPanel.add(colorPanel, BorderLayout.CENTER);
		
		this.getContentPane().add(mainPanel, BorderLayout.SOUTH);
		this.getContentPane().add(paintBoard, BorderLayout.CENTER);
		
		btnLine.setForeground(Color.red);
		paintBoard.setCommand(Command.LINE);
		
		btnRed.setForeground(Color.red);
		paintBoard.setColor(Color.red);
	}
        
        void btnComposite_actionPerformed(ActionEvent e) {
            btnComposite.setForeground(Color.red);
            btnLine.setForeground(Color.black);
            btnRectangle.setForeground(Color.black);
            //btnCircle.setForeground(Color.black);
            paintBoard.setCommand(0);
        }
	
	void btnExit_actionPerformed(ActionEvent e) {
		System.exit(0);
	}
	
	
	void btnLine_actionPerformed(ActionEvent e) {
		btnLine.setForeground(Color.red);
		btnRectangle.setForeground(Color.black);
		//btnCircle.setForeground(Color.black);
                btnComposite.setForeground(Color.black);
		paintBoard.setCommand(Command.LINE);
	}
	
	void btnRectangle_actionPerformed(ActionEvent e) {
		btnLine.setForeground(Color.black);
		btnRectangle.setForeground(Color.red);
		//btnCircle.setForeground(Color.black);
                btnComposite.setForeground(Color.black);
		paintBoard.setCommand(Command.RECTANGLE);
	}
	
	void btnCircle_actionPerformed(ActionEvent e) {
		btnLine.setForeground(Color.black);
		btnRectangle.setForeground(Color.black);
		//btnCircle.setForeground(Color.red);
                btnComposite.setForeground(Color.black);
		paintBoard.setCommand(Command.CIRCLE);
	}
	
	void btnRed_actionPerformed(ActionEvent e) {
		btnRed.setForeground(Color.red);
		btnGreen.setForeground(Color.black);
		btnBlue.setForeground(Color.black);
		paintBoard.setColor(Color.red);
	}
	
	void btnGreen_actionPerformed(ActionEvent e) {
		btnRed.setForeground(Color.black);
		btnGreen.setForeground(Color.red);
		btnBlue.setForeground(Color.black);
		paintBoard.setColor(Color.green);
                paintBoard.setColorCommand(100);
                
	}
	
	void btnBlue_actionPerformed(ActionEvent e) {
		btnRed.setForeground(Color.black);
		btnGreen.setForeground(Color.black);
		btnBlue.setForeground(Color.red);
		paintBoard.setColor(Color.blue);
                paintBoard.setColorCommand(200);
	}
	
	public static void main (String[] args) {
		PaintMainFrame paintApp = new PaintMainFrame();
		paintApp.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		paintApp.setSize(600, 500);
		paintApp.setTitle("Painter");
		paintApp.setVisible(true);
	}
}
