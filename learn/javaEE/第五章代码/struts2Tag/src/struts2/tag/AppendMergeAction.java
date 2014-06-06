/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package struts2.tag;

import com.opensymphony.xwork2.ActionSupport;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author Administrator
 */
public class AppendMergeAction extends ActionSupport {
  private List<String> myList1;
  private List<String> myList2;
  private List<String> myList3;
  
   @SuppressWarnings("unchecked")
public String execute() throws Exception {      
	   
	  myList1 = new ArrayList();
      myList1.add("1");
      myList1.add("2");
      myList1.add("3");

      myList2 = new ArrayList();
      myList2.add("a");
      myList2.add("b");
      myList2.add("c");

      myList3 = new ArrayList();
      myList3.add("A");
      myList3.add("B");
      myList3.add("C");

      return SUCCESS;
  }

   public List<String> getMyList1() { return myList1; }
   public List<String> getMyList2() { return myList2; }
   public List<String> getMyList3() { return myList3; }

}


