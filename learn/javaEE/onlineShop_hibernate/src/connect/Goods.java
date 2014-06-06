package connect;

/**
 * Goods entity. @author MyEclipse Persistence Tools
 */
public class Goods extends AbstractGoods implements java.io.Serializable {

	// Constructors

	/** default constructor */
	public Goods() {
	}

	/** minimal constructor */
	public Goods(String name) {
		super(name);
	}

	/** full constructor */
	public Goods(String name, String type, Double price, Integer stock) {
		super(name, type, price, stock);
	}

}
