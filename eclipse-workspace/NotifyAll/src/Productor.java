import java.util.LinkedList;

public class Productor extends Thread {
	private LinkedList<String> palabras;
	private boolean finalizado;

	public boolean isFinalizado() {
		return finalizado;
	}

	public void setFinalizado(boolean finalizado) {
		this.finalizado = finalizado;
	}

	public Productor(LinkedList<String> palabras) {
		super();
		this.palabras = palabras;
		setFinalizado( false );
	}

	@Override
	public void run() {
		super.run();
		while( ! isFinalizado() ) {
			try {
				Thread.sleep( 1000 );
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			synchronized( palabras ) {
				int pos = (int) Math.floor( Math.random() * Programa.PRE.length );
				palabras.add( Programa.PRE[ pos ] );
				System.out.println( "He añadido " + Programa.PRE[ pos ] );
				palabras.notify();
			}
		}
	}
}
