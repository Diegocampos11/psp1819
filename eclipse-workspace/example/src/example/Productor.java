package example;

public class Productor extends Thread {
	private Recursos recursos;
	private boolean finalizado;

	public Productor(Recursos recursos) {
		super();
		this.recursos = recursos;
	}
	
	public void producir( /*int n */) {
		//for ( int i = 0; i < n; i++ ) {
			Object rec = new Object();
			recursos.anadirRecurso(rec);
		//}
	}
	
	public void finalizar() {
		finalizado = true;
	}

	@Override
	public void run() {
		finalizado = false;
		while ( ! finalizado ) {
			this.producir( );
			try {
				Thread.sleep(500);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
}
