package org.model;


import java.util.List;
import org.hibernate.Query;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.Transaction;
import org.hibernate.cfg.Configuration;

import org.model.*;


public class TbHibernateDao {
	   
	   public List selectManager() {
		   Configuration config = new Configuration().configure();
		   SessionFactory sessionFactory = config.buildSessionFactory();
           Session session = sessionFactory.openSession();
           Transaction tx = session.beginTransaction();
           
//           TbUser tu  = new TbUser();
//           tu.setName("zhangsan3");          
//           tu.setProfession("student"); 
//   		   try{
//   			  session.save(tu);   			 			
//   		   }catch(Exception ex){
//   			  ex.printStackTrace();
//   		   }           
           
            String hql = "from TbUser b where b is not null";
		    List list = null;
		    try {
		       Query query = session.createQuery(hql);
		       list = query.list();
		    } catch (Exception e) {
		       System.out.println(e.getMessage());
		    }
		    tx.commit();
		    session.close();
		    return list;
		}

	

}
