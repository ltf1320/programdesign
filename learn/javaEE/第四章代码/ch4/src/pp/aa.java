package pp;

public class aa {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		 int a = testreturn();
	     System.out.println(a);

	}
	
    public static int testreturn()
    {
        try
        {
        	System.out.println("ִ��try�Ӿ�!");
            return 1;        
            //throw (new ArgumentNullException()); // �����쳣
        }
        catch (Exception e)
        {
        	System.out.println(e.toString());
            return 2;
        }
        finally
        {
        	System.out.println("ִ��finally�Ӿ�!");
            //return 3;
        }

    }

}
