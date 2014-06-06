package connect;

/**
 * AbstractGoods entity provides the base persistence definition of the Goods
 * entity. @author MyEclipse Persistence Tools
 */

public abstract class AbstractGoods implements java.io.Serializable {

	// Fields

	private Integer id;
	private String name;
	private String type;
	private Double price;
	private Integer stock;

	// Constructors

	/** default constructor */
	public AbstractGoods() {
	}

	/** minimal constructor */
	public AbstractGoods(String name) {
		this.name = name;
	}

	/** full constructor */
	public AbstractGoods(String name, String type, Double price, Integer stock) {
		this.name = name;
		this.type = type;
		this.price = price;
		this.stock = stock;
	}

	// Property accessors

	public Integer getId() {
		return this.id;
	}

	public void setId(Integer id) {
		this.id = id;
	}

	public String getName() {
		return this.name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getType() {
		return this.type;
	}

	public void setType(String type) {
		this.type = type;
	}

	public Double getPrice() {
		return this.price;
	}

	public void setPrice(Double price) {
		this.price = price;
	}

	public Integer getStock() {
		return this.stock;
	}

	public void setStock(Integer stock) {
		this.stock = stock;
	}

}