import java.util.LinkedList;

public class Programa {
	public static final int MAX = 10;
	public static final String PRE[] = {"oro", "plata", "bronce", "madera", "hierro", "diamantes"};
	
	public static void main(String[] args) {
		LinkedList<String> palabras = new LinkedList<String>();
		Productor p1 = new Productor( palabras );
		Productor p2 = new Productor( palabras );
		Consumidor c1 = new Consumidor( palabras );
		Consumidor c2 = new Consumidor( palabras );
		Consumidor c3 = new Consumidor( palabras );
		p1.start();
		c1.start();
		c2.start();
		c3.start();
		//dormir
		try {
			Thread.sleep( 10000 );
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		p1.setFinalizado(true);
		c2.setFinalizado(true);
		c1.setFinalizado(true);
		c3.setFinalizado(true);
		
	}

}
