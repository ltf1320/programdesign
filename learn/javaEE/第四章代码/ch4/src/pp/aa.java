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
        	System.out.println("执行try子句!");
            return 1;        
            //throw (new ArgumentNullException()); // 引发异常
        }
        catch (Exception e)
        {
        	System.out.println(e.toString());
            return 2;
        }
        finally
        {
        	System.out.println("执行finally子句!");
            //return 3;
        }

    }

}
