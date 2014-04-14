import java.util.Random;
import javax.swing.ImageIcon;

public class LLKData {
	int maxn,maxm;
	int difLever;
	static ImageIcon[] Icons;
	LLKButton[][] BTs;
	LLKData()
	{
		Icons=new 
		difLever=1;
		maxn=5;
		maxm=10;
	}
	void newRamdonData()
	{
		BTs=new LLKButton[maxn][maxm];
		Random rd=new Random();
		int m=maxn*maxm/2;
		for(int i=0;i<m;++i)
		{
			if(BTs[i/maxn][i%maxn]!=null)
			{
				i++;m++;continue;
			}
			else 
			{
				int id=(int) (rd.nextDouble()*difLever*10);
				BTs[i/maxn][i%maxn]=new LLKButton(id);
				
			}
		}
	}
}
