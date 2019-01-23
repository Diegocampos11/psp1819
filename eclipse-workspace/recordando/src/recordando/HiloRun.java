package recordando;

public class HiloRun implements Runnable{
	private Saludo saludo;

	public HiloRun(Saludo saludo) {
		super();
		this.saludo = saludo;
	}

	@Override
	public void run() {
		System.out.println("Hola mundo desde Hilorun");
		
	}

}
