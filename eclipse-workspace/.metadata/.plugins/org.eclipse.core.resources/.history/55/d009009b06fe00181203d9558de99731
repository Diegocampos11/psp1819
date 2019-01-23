package example;

public class Consumidor extends Thread {
	private Recursos recursos;
	private boolean finalizado;
	
	public void consumir ( /*int n*/ ) {
		//for( int i = 0; i < n; i++ ) {
			recursos.obtenerRecurso();
		//}
	}

	public Consumidor(Recursos recursos) {
		super();
		this.recursos = recursos;
	}
	
	public void finalizar() {
		finalizado = true;
	}

	@Override
	public void run() {
		finalizado = false;
		while ( ! finalizado ) {
			this.consumir( );
			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
}
