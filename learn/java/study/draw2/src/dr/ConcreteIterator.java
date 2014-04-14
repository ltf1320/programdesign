package dr;

public class ConcreteIterator {
	private ConcreteAggregate aggregate;
    private int current;

    // Constructor
    public ConcreteIterator(ConcreteAggregate aggregate)
    {
        this.aggregate = aggregate;
        this.current=0;
    }

    // Gets first iteration item
    public Object First()
    {
        return aggregate.get(0);
    }

    // Gets next iteration item
    public void Next()
    {
        current++;
    }

    // Gets current iteration item
    public Object CurrentItem()
    {
        return aggregate.get(current);
    }

    // Gets whether iterations are complete
    public Boolean IsDone()
    {
    	if(current >= aggregate.Count())
  
    		return true;
    	
    	else
    		return false;
    }
    public void setCurrentItem(Object obj){
    	aggregate.set(obj);
    }
    public void clearaggregate(){
    	aggregate.clear();
    }
    public void initcurrent(int i){
    	current=i;
    }

}

