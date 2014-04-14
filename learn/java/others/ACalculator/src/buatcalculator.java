import javax.swing.*;
import java.io.*;
import java.awt.*;
import java.awt.event.*;
/**
* 
* @author fubin
* 标准计算器
* Download:http://www.bvbsoft.com 
*/
public class buatcalculator extends JFrame implements ActionListener

{

 JPanel txtpanel,btnpanel,southpanel;
 JTextField txtinput;
 JButton b1,b2,b3,b4,b5,b6,b7,b8,b9,b0,bdes,kalibtn,bagibtn,tambahbtn,kurangbtn,clearbtn,equalbtn,aboutbtn;
 GridLayout gl;
 double simpan,hasil;
 String operasi;

 public buatcalculator()
 {
   super("Calculator Cabe");
   txtpanel=new JPanel();
   btnpanel=new JPanel();
   southpanel=new JPanel();
   txtinput=new JTextField(20);
   txtinput.setEditable(false);
   txtinput.setHorizontalAlignment(JTextField.RIGHT);
   txtinput.setText("");
   b1=new JButton("1");
   b2=new JButton("2");
   b3=new JButton("3");
   b4=new JButton("4");
   b5=new JButton("5");
   b6=new JButton("6");
   b7=new JButton("7");
   b8=new JButton("8");
   b9=new JButton("9");
   b0=new JButton("0");
   bdes=new JButton(".");
   kalibtn=new JButton("x");
   kalibtn.setFont(new Font("Gothic",Font.BOLD,20));
   kalibtn.setBackground(Color.black);
   kalibtn.setForeground(Color.blue);
   bagibtn=new JButton(":");
   bagibtn.setFont(new Font("Gothic",Font.BOLD,20));
   bagibtn.setBackground(Color.black);
   bagibtn.setForeground(Color.blue);
   tambahbtn=new JButton("+");
   tambahbtn.setFont(new Font("Gothic",Font.BOLD,20));
   tambahbtn.setBackground(Color.black);
   tambahbtn.setForeground(Color.blue);
   kurangbtn=new JButton("-");
   kurangbtn.setFont(new Font("Gothic",Font.BOLD,20));
   kurangbtn.setBackground(Color.black);
   kurangbtn.setForeground(Color.blue);
   aboutbtn=new JButton("About");
   aboutbtn.setFont(new Font("Arial",Font.ITALIC,12));
   aboutbtn.setBackground(Color.black);
   aboutbtn.setForeground(Color.red);

   aboutbtn.addActionListener(new ActionListener()
   {
     public void actionPerformed(ActionEvent argh)
     {
       btnOKActionPerformed();
     }
   });

   clearbtn=new JButton("C");
   clearbtn.setFont(new Font("Arial",Font.ITALIC,12));
   clearbtn.setBackground(Color.black);
   clearbtn.setForeground(Color.red);
   clearbtn.addActionListener(new ActionListener()
   {
     public void actionPerformed(ActionEvent argh)
     {
       btnCancelActionPerformed();
     }
   });

   equalbtn=new JButton("=");
   equalbtn.setFont(new Font("Arial",Font.ITALIC,20));
   equalbtn.setBackground(Color.black);
   equalbtn.setForeground(Color.blue);

   //putting event to the button
   b1.addActionListener(this);
   b2.addActionListener(this);
   b3.addActionListener(this);
   b4.addActionListener(this);
   b5.addActionListener(this);
   b6.addActionListener(this);
   b7.addActionListener(this);
   b8.addActionListener(this);
   b9.addActionListener(this);
   b0.addActionListener(this);
   bdes.addActionListener(this);
   kalibtn.addActionListener(this);
   bagibtn.addActionListener(this);
   tambahbtn.addActionListener(this);
   kurangbtn.addActionListener(this);
   equalbtn.addActionListener(this);


   getContentPane().add(txtpanel,BorderLayout.NORTH);

   txtpanel.add(txtinput);

   gl=new GridLayout(4,5,5,5);
   btnpanel.setLayout(gl);
   getContentPane().add(btnpanel);

   btnpanel.add(b7);
   btnpanel.add(b8);
   btnpanel.add(b9);
   btnpanel.add(kalibtn);
   btnpanel.add(b4);
   btnpanel.add(b5);
   btnpanel.add(b6);
   btnpanel.add(bagibtn);
   btnpanel.add(b1);
   btnpanel.add(b2);
   btnpanel.add(b3);
   btnpanel.add(tambahbtn);
   btnpanel.add(b0);
   btnpanel.add(bdes);
   btnpanel.add(equalbtn);
   btnpanel.add(kurangbtn);

   getContentPane().add(southpanel,BorderLayout.SOUTH);
   southpanel.add(clearbtn);
   southpanel.add(aboutbtn);

   setSize(250,300);
   setVisible(true);
   setLocation(300,200);
   setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);

 }

 public void btnOKActionPerformed()

 {
   JOptionPane.showMessageDialog(null,"标准计算器"+"\nCreated By Fubin (yonghe169@163.com) Make in china, 海南"+"\n这是我做过所有计算器中最简洁，最实用的一个了！","About",JOptionPane.INFORMATION_MESSAGE);
 }

 public void btnCancelActionPerformed()

 {
   txtinput.setText("");
 }

 //make event when a button clicked
 public void actionPerformed(ActionEvent e)
 {
 try
 {
   Object objkcal=e.getSource();
   if(objkcal==b1)
   txtinput.setText(txtinput.getText()+"1");
   else
   if(objkcal==b2)
   txtinput.setText(txtinput.getText()+"2");
   else
   if(objkcal==b3)
   txtinput.setText(txtinput.getText()+"3");
   else
   if(objkcal==b4)
   txtinput.setText(txtinput.getText()+"4");
   else
   if(objkcal==b5)
   txtinput.setText(txtinput.getText()+"5");
   else
   if(objkcal==b6)
   txtinput.setText(txtinput.getText()+"6");
   else
   if(objkcal==b7)
   txtinput.setText(txtinput.getText()+"7");
   else
   if(objkcal==b8)
   txtinput.setText(txtinput.getText()+"8");
   else
   if(objkcal==b9)
   txtinput.setText(txtinput.getText()+"9");
   else
   if(objkcal==b0)
   txtinput.setText(txtinput.getText()+"0");
   else
   if(objkcal==bdes)
   txtinput.setText(txtinput.getText()+".");
   else
   if(objkcal==tambahbtn)
   {
   //save the first number to the var simpan
   simpan=Double.parseDouble(txtinput.getText());
   operasi="plus";
   txtinput.setText("");
   }
   else
   if(objkcal==kurangbtn)
   {
   //save the first number to the var simpan
   simpan=Double.parseDouble(txtinput.getText());
   operasi="minus";
   txtinput.setText("");
   }
   else
   if(objkcal==bagibtn)
   {
   //save the first number to the var simpan
   simpan=Double.parseDouble(txtinput.getText());
   operasi="bagi";
   txtinput.setText("");
   }
   else
   if(objkcal==kalibtn)
   {
   //save the first number to the var simpan
   simpan=Double.parseDouble(txtinput.getText());
   operasi="kali";
   txtinput.setText("");
   }
   else
   if(objkcal==equalbtn)
   {
     //catching the "plus" operation
     if(operasi=="plus")
     {
       hasil=simpan+Double.parseDouble(txtinput.getText());
       txtinput.setText(Double.toString(hasil));
     }
     else
       //catching the "minus" operation
       if(operasi=="minus")
       {
       hasil=simpan-Double.parseDouble(txtinput.getText());
       txtinput.setText(Double.toString(hasil));
       }
     else
       if(txtinput.equals(txtinput.getText())&&objkcal==kurangbtn)
       {
       hasil=simpan-Double.parseDouble(txtinput.getText());
       txtinput.setText(Double.toString(hasil));
       }
     else
       //catching the "bagi" operation
       if(operasi=="bagi")
       {
       hasil=simpan/Double.parseDouble(txtinput.getText());
       txtinput.setText(Double.toString(hasil));
       }
     else
       //catching the "kali" operation
       if(operasi=="kali")
       {
       hasil=simpan*Double.parseDouble(txtinput.getText());
       txtinput.setText(Double.toString(hasil));
       }
   }


 }
   catch(Exception ouch)
   {
     JOptionPane.showMessageDialog(null,"错误输入","error",JOptionPane.ERROR_MESSAGE);
   }

 }


 public static void main(String args[])
 {

   try

     {
       //使用显示风格
       UIManager.setLookAndFeel ("com.sun.java.swing.plaf.windows.WindowsLookAndFeel");

     }

   catch(Exception e)
   {}

   new buatcalculator();

 }

} 
