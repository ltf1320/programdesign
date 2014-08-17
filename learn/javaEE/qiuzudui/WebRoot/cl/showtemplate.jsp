<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<%@ taglib uri="/struts-tags" prefix="s" %>
  				<s:iterator value="#request.msgli" >
  				<div style="border:1px solid #96c2f1;background:#eff7ff;width:30%;float:left;margin-left:1%;height:130px;margin-top:2px;">
  				<div>
  					<label><s:property value="title"/></label>
  					</div><div>
  					<label><s:property value="createTime"/></label>
  					<a href="<%=basePath %>showUser.jsp?userName=<s:property value='users.userName'/>"><s:property value="users.userName"/></a>
  				</div>
  				<div>
  					时间：<s:property value="time"/>
  				</div>
  				<div>
  					<s:property value="text"/>
  				</div>
  				<div>
  					<BR>
  					<s:property value="opt1"/>&nbsp;
  					<s:property value="opt2"/>&nbsp;
  					<s:property value="opt3"/>&nbsp;
  				</div>
  				</div>
  				</s:iterator>