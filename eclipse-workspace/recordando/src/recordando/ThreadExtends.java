package recordando;

public class ThreadExtends extends Thread{
	private Saludo saludo;

	public ThreadExtends(Saludo saludo) {
		super();
		this.saludo = saludo;
	}

	@Override
	public void run() {
		System.out.println("Imprime desde thread extends :D " + saludo + " nombre:" + this.getName());
		System.out.println("Ahora cambio el saludo desde threadth extends!! :D");
		saludo.setSaludo("threadthread");
		super.run();
	}
	
}
