/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package struts2.tag;

import com.opensymphony.xwork2.ActionSupport;

/**
 *
 * @author Administrator
 */
public class ActionTest extends ActionSupport {
    private String Owner;

    /**
     * @return the Owner
     */
    public String getOwner() {
        return Owner;
    }

    /**
     * @param Owner the Owner to set
     */
    public void setOwner(String Owner) {
        this.Owner = Owner;
    }
    @Override
     public String execute() throws Exception {
         return SUCCESS;
     }
}

