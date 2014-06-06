<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@ taglib prefix="s" uri="/struts-tags" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
"http://www.w3.org/TR/html4/loose.dtd">

<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>演示Append和Merge标签</title>
    </head>
    <body>
    
    <s:debug/>
    
    <s:iterator value="myList1" id="zz">
       <s:property value="zz"/>
    </s:iterator>
    
    
        <s:append id="myAppendIterator">
            <s:param value="myList1" />
            <s:param value="myList2" />
            <s:param value="myList3" />
        </s:append>
        <h1>Append的执行结果</h1>
        <s:iterator value="myAppendIterator" id="app">
            <s:property value="app"/>
        </s:iterator>
        
       <s:merge id="mymergeIterator">
            <s:param value="myList1" />
            <s:param value="myList2" />
            <s:param value="myList3" />
        </s:merge>
        <h1>Merge的执行结果</h1>
        <s:iterator value="mymergeIterator">
            <s:property />
        </s:iterator>
        
    </body>
</html>
