<%@ page language="java" 
       pageEncoding="gb2312"%>
<html>
  <body>
     <form method="post" action="login_session.jsp">
        ÐÕÃû<input type="text" name="UserName">   
        
        <%=session.getId() %>    
      <input type="submit"  value="Ìá½»">
    </form>
  </body>
</html>
