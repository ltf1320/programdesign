/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package com.struts2.validation;

import com.opensymphony.xwork2.ActionSupport;
import java.util.Date;

/**
 *
 * @author Administrator
 */
public class RegisterAction extends ActionSupport {

    private String username;

    private String password;

    private String repassword;
 private String cardid;
    private double height;
    private String myemail;
    private String blogurl;
    private Date birthday;


    /**
     * @return the username
     */
    public String getUsername() {
        return username;
    }

    /**
     * @param username the username to set
     */
    public void setUsername(String username) {
        this.username = username;
    }

    /**
     * @return the password
     */
    public String getPassword() {
        return password;
    }

    /**
     * @param password the password to set
     */
    public void setPassword(String password) {
        this.password = password;
    }

    /**
     * @return the repassword
     */
    public String getRepassword() {
        return repassword;
    }

    /**
     * @param repassword the repassword to set
     */
    public void setRepassword(String repassword) {
        this.repassword = repassword;
    }

    /**
     * @return the height
     */
    public double getHeight() {
        return height;
    }

    /**
     * @param height the height to set
     */
    public void setHeight(double height) {
        this.height = height;
    }

    /**
     * @return the myemail
     */
    public String getMyemail() {
        return myemail;
    }

    /**
     * @param myemail the myemail to set
     */
    public void setMyemail(String myemail) {
        this.myemail = myemail;
    }

    /**
     * @return the blogurl
     */
    public String getBlogurl() {
        return blogurl;
    }

    /**
     * @param blogurl the blogurl to set
     */
    public void setBlogurl(String blogurl) {
        this.blogurl = blogurl;
    }

    /**
     * @return the birthday
     */
    public Date getBirthday() {
        return birthday;
    }

    /**
     * @param birthday the birthday to set
     */
    public void setBirthday(Date birthday) {
        this.birthday = birthday;
    }

    /**
     * @return the cardid
     */
    public String getCardid() {
        return cardid;
    }

    /**
     * @param cardid the cardid to set
     */
    public void setCardid(String cardid) {
        this.cardid = cardid;
    }
    
    ////////////
    public String reg() {
		return SUCCESS;
	}

}
