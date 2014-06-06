package com.method;


import java.sql.ResultSet;
import java.util.ArrayList;

import com.entity.Author;
import common.Conn;


public class AuthorMethod {
	ResultSet rs = null;

	// ��ѯ������Ϣ
	public ArrayList findAuthor(String ath) {
		Conn conn = new Conn();
		ArrayList<Author> list = new ArrayList<Author>();
		try {

			String sql = "select * from authors";
			if(!ath.equals("")) sql=sql+" where au_lname='"+ath+"'";
			rs = conn.executeQuery(sql);
			while (rs.next()) {				
				Author au = new Author();
				au.setAu_lname(rs.getString("au_lname"));
				au.setAddress(rs.getString("address"));
				au.setCity(rs.getString("city"));				
				list.add(au);
			}
		} catch (Exception e) {
			e.printStackTrace();
		} finally { // �رս���������ӳ�
			try {
				if (rs != null)
					rs.close();
				conn.close();
			} catch (Exception e) {
			}
		}

		return list;

	}

	

}
