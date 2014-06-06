/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package struts2.tag;

import java.util.Comparator;

/**
 *
 * @author Administrator
 */
public class NameComparator implements Comparator
{
public int compare(Object element1, Object element2)
{
   String t1=(String)element1;
    char c1=t1.charAt(0);
    String t2=(String)element2;
    char c2=t2.charAt(0);
    if(Character.toUpperCase(c1)>=Character.toUpperCase(c2))

   return 1;
    else
        return -1;
}
}




