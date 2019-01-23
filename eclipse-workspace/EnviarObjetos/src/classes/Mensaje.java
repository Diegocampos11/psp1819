package classes;

import java.io.Serializable;

public class Mensaje implements Serializable{
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;//tienen que tener el mismo numero de ID si quieres que se comunique en otro lado
	int id;
	String texto;
	
	@Override
	public String toString() {
		return "Mensaje [id=" + id + ",\n\t texto=" + texto + "]";
	}

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public String getTexto() {
		return texto;
	}

	public void setTexto(String texto) {
		this.texto = texto;
	}

	public Mensaje(int id, String texto) {
		super();
		this.id = id;
		this.texto = texto;
	}
}
