<%@ page language="java" import="java.util.*,java.text.SimpleDateFormat"
	pageEncoding="GB18030"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
	<head>
		<base href="<%=basePath%>">

		<title>My JSP 'dateGetYear.jsp' starting page</title>

		<meta http-equiv="pragma" content="no-cache">
		<meta http-equiv="cache-control" content="no-cache">
		<meta http-equiv="expires" content="0">
		<meta http-equiv="keywords" content="keyword1,keyword2,keyword3">
		<meta http-equiv="description" content="This is my page">
	

	</head>

	<body>
		<%Date today=new Date(); %>
		<%=today %><br>
		<%=today.getYear()+1900 %><br>		
		<%//已过时，replaced by Calendar.get(Calendar.YEAR) - 1900.%>
		<%=today.getMonth()%><br>
		<%///返回的是正常月减1了 %>
		
		<%=today.getDay() %><br>
		<%///返回星期几 ，从 JDK 1.1 开始，由 Calendar.get(Calendar.DAY_OF_WEEK) 取代%>
		
		<%=today.getDate() %><br>
		<%///返回的是今天是几号 %>
		
		<%
        //Calendar 与 Date 的转换非常简单：

        Calendar calendar = Calendar.getInstance();
        // 从一个 Calendar 对象中获取 Date 对象
        Date date = calendar.getTime();
        // 将 Date 对象反应到一个 Calendar 对象中，
        // Calendar/GregorianCalendar 没有构造函数可以接受 Date 对象
        // 所以我们必需先获得一个实例，然后设置 Date 对象
         calendar.setTime(date);    
           
           //年 
           System.out.print(calendar.get(calendar.YEAR)); 
           //月 
           System.out.print(calendar.get(calendar.MONTH)+1); 
           //日 
           System.out.print(calendar.get(calendar.DATE));      
      %>
		
		<%   
           //java.util.Date cDate=new java.util.Date(); 
           //java.util.GregorianCalendar gcalendar=new java.util.GregorianCalendar(); 
           //gcalendar.setTime(cDate); 
           //java.text.SimpleDateFormat df = new java.text.SimpleDateFormat("yyyy年MM月dd日 "); 
           //System.out.print(df.format(gcalendar.getTime())); 
           //年 
           //System.out.print(gcalendar.get(gcalendar.YEAR)); 
           //月 
           //System.out.print(gcalendar.get(gcalendar.MONTH)+1); 
           //日 
           //System.out.print(gcalendar.get(gcalendar.DATE));
     %>
      
	</body>
</html>
