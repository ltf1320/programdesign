package dr;

import java.awt.Shape;
import java.util.ArrayList;

import javax.swing.text.html.HTMLDocument.Iterator;

public class ConcreteAggregate {
	public ArrayList <Shape> shapes;//private
	public ConcreteAggregate(){
		shapes = new ArrayList<Shape>();
	}
	public  ConcreteIterator CreateIterator()
    {
        return new ConcreteIterator(this);
    }
	 public int Count()
     {
        return shapes.size(); 
     }
	 public Shape get(int index){
		return shapes.get(index);
	 }
	 public void set(Object obj){
		shapes.add((Shape) obj);
	 }
	 public void clear(){
		 shapes=null;
	 }
}


