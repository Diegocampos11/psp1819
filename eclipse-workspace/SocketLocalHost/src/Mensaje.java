import java.io.Serializable;

public class Mensaje implements Serializable{
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	
	private String msj;

	public Mensaje(String msj) {
		super();
		this.msj = msj;
	}

	public String getMsj() {
		return msj;
	}

	public void setMsj(String msj) {
		this.msj = msj;
	}
}
