package dr;

import java.awt.Graphics;
import java.awt.Point;

public class concreteFactory {
	public shap drawline(){
		return new shapeline(null, null);
	}
	public shap drawoval(){
		return new shapoval(null, null);
	}
	public shap drawrec(){
		return new shaprec(null, null);
	}
	public shap drawshap(){
		return new zhushap();
	}
}
