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
		<%//�ѹ�ʱ��replaced by Calendar.get(Calendar.YEAR) - 1900.%>
		<%=today.getMonth()%><br>
		<%///���ص��������¼�1�� %>
		
		<%=today.getDay() %><br>
		<%///�������ڼ� ���� JDK 1.1 ��ʼ���� Calendar.get(Calendar.DAY_OF_WEEK) ȡ��%>
		
		<%=today.getDate() %><br>
		<%///���ص��ǽ����Ǽ��� %>
		
		<%
        //Calendar �� Date ��ת���ǳ��򵥣�

        Calendar calendar = Calendar.getInstance();
        // ��һ�� Calendar �����л�ȡ Date ����
        Date date = calendar.getTime();
        // �� Date ����Ӧ��һ�� Calendar �����У�
        // Calendar/GregorianCalendar û�й��캯�����Խ��� Date ����
        // �������Ǳ����Ȼ��һ��ʵ����Ȼ������ Date ����
         calendar.setTime(date);    
           
           //�� 
           System.out.print(calendar.get(calendar.YEAR)); 
           //�� 
           System.out.print(calendar.get(calendar.MONTH)+1); 
           //�� 
           System.out.print(calendar.get(calendar.DATE));      
      %>
		
		<%   
           //java.util.Date cDate=new java.util.Date(); 
           //java.util.GregorianCalendar gcalendar=new java.util.GregorianCalendar(); 
           //gcalendar.setTime(cDate); 
           //java.text.SimpleDateFormat df = new java.text.SimpleDateFormat("yyyy��MM��dd�� "); 
           //System.out.print(df.format(gcalendar.getTime())); 
           //�� 
           //System.out.print(gcalendar.get(gcalendar.YEAR)); 
           //�� 
           //System.out.print(gcalendar.get(gcalendar.MONTH)+1); 
           //�� 
           //System.out.print(gcalendar.get(gcalendar.DATE));
     %>
      
	</body>
</html>
