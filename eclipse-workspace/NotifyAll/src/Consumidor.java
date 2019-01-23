import java.util.LinkedList;
import java.util.Random;

public class Consumidor extends Thread {
	private LinkedList<String> palabras;
	private boolean finalizado;

	public boolean isFinalizado() {
		return finalizado;
	}

	public void setFinalizado(boolean finalizado) {
		this.finalizado = finalizado;
	}

	public Consumidor(LinkedList<String> palabras) {
		super();
		this.palabras = palabras;
		setFinalizado( false );
	}

	@Override
	public void run() {
		super.run();
		while( !isFinalizado() ) {
			try {
				Thread.sleep( 1000 );//consumimos cada 1000
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			synchronized(palabras) {
				if ( palabras.size() == 0 ) {//No tenemos palabras esperamos a que el productor nos de palabras 				
					try {
						System.out.println("Esperando...");
						palabras.wait();
					} catch (InterruptedException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
				}
				int pos = ( new Random().nextInt() ) % palabras.size();//da la vuelta al ejecutar el modulo del tamaño del vector
				String elegido = palabras.get(pos);//palabras.get( (int) Math.floor( Math.random() * palabras.size() ) );//se coje un entero al azar entre 0 y el numero de palabras que estan
				palabras.remove( pos );
				System.out.println("He consumido " + elegido);
			}			
		}
	}
	
	
}
