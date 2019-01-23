package example;

public class Main {

	public static void main(String[] args) {
		Recursos recursos = new Recursos();
		Productor p = new Productor( recursos );
		Consumidor c = new Consumidor( recursos );
		//lanzo el recogedor de recursos y el que los consume
		p.start();
		c.start();
		try {
			Thread.sleep(20000);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		p.finalizar();
		c.finalizar();
		c.interrupt();//interrumpo un hilo regardless of the wait
	}

}
