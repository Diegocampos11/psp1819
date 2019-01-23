package example;

import java.util.ArrayList;

public class Recursos {
	private ArrayList<Object> listaRecursos;
	
	public synchronized Object obtenerRecurso(){
		System.out.println("Quedan " + listaRecursos.size());
		if ( listaRecursos.isEmpty() ) {
			System.out.println("Esperando a que haya recursos disponibles...");
			try {
				wait();
			} catch (InterruptedException e) {
				e.printStackTrace();
				System.out.println("obtenerRecurso: Proceso interrumpido mientras esperaba");
			}//el wait puede salir con una interrupción
		}
		System.out.println("He obtenido recurso");
		Object recurso = listaRecursos.get(0);
		listaRecursos.remove(0);
		return recurso;
	}
	
	public Recursos() {
		super();
		this.listaRecursos = new ArrayList<Object>();
	}

	public synchronized void anadirRecurso( Object o) {
		System.out.println("Recursos añadidos!");
		listaRecursos.add( o );
		/*listaRecursos.*/notify();
	}
}
