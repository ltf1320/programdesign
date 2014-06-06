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
public class CheckBoxAction  extends ActionSupport {
    private boolean apple;
    private boolean orange;
    private boolean peach;

    /**
     * @return the apple
     */
    public boolean isApple() {
        return apple;
    }

    /**
     * @param apple the apple to set
     */
    public void setApple(boolean apple) {
        this.apple = apple;
    }

    /**
     * @return the orange
     */
    public boolean isOrange() {
        return orange;
    }

    /**
     * @param orange the orange to set
     */
    public void setOrange(boolean orange) {
        this.orange = orange;
    }

    /**
     * @return the peach
     */
    public boolean isPeach() {
        return peach;
    }

    /**
     * @param peach the peach to set
     */
    public void setPeach(boolean peach) {
        this.peach = peach;
    }
    
}
