
public class hiloRunnable implements Runnable{
	
	private int num;
	
	public hiloRunnable( int num ) {
		this.num = num;
	}

	@Override
	public void run() {
		for (int i = 0; i < 100; i++) {
			num++;
		} 
		System.out.print("Runnable hecho");
		System.out.println( "R Ahora vale " + num );
	}	
}
