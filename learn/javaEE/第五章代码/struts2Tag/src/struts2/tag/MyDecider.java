/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package struts2.tag;

import org.apache.struts2.util.SubsetIteratorFilter;

/**
 *
 * @author Administrator
 */
public class MyDecider implements SubsetIteratorFilter.Decider
{
public boolean decide(Object element) throws Exception
{
   String str = (String)element;
   return str.indexOf("ǹ")< 0;
}
}

