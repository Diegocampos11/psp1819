
public class FirstThread {

	public static void main(String[] args) {
		int num = 300;
		TThread ht = new TThread( num );
		ht.start();
		hiloRunnable hr = new hiloRunnable( num );
		Thread hrunnable = new Thread( hr );
		hrunnable.start();
		System.out.println("hola principal");
		System.out.println( num );
	}

}
