
import com.opensymphony.xwork2.ActionContext;
import com.opensymphony.xwork2.ActionSupport;

public class SubAction extends ActionSupport {
	private static final long serialVersionUID=2L;
	private String name;
	private String id;
	private String pro;
	private String clas;
	private String time;
	public String getPro() {
		return pro;
	}

	public void setPro(String pro) {
		this.pro = pro;
	}

	public String getId() {
		return id;
	}

	public void setId(String id) {
		this.id = id;
	}
	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getClas() {
		return clas;
	}

	public void setClas(String clas) {
		this.clas = clas;
	}

	public String getTime() {
		return time;
	}

	public void setTime(String time) {
		this.time = time;
	}

	@Override
	public String execute() throws Exception
	{
		if(!name.equals("ltf"))
		{
			ActionContext.getContext().getSession().put("error","name is not correct!");
			return ERROR;
		}
		return SUCCESS;
	}
}
