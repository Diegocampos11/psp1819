
public class TThread extends Thread{
	
	private int num;
	
	public TThread( int num ) {
		super();
		this.num = num;
	}

	@Override
	public void run() {
		for (int i = 0; i < 100; i++) {
			num--;
		} 
		System.out.println("Hilo normal hecho");
		System.out.println( "hn Ahora vale " + num );
	}
	
}
