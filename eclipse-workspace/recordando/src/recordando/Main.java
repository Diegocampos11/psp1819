package recordando;
import recordando.*;

public class Main {

	public static void main(String[] args) {
		Saludo saludo = new Saludo( "XHola" );		
		HiloRun HiloRun = new HiloRun( saludo );//no se sabe el nombre
		Thread th = new Thread(/* HiloRun or...*/new Runnable()/*NOMBRE DE LA INTERFAAAAZZZZZZZ*/ {//Aqui si se puede saber el nombre del thread :D			
			@Override
			public void run() {
				System.out.println("hola amigo soy anonimo :D" + saludo);
				System.out.println("Ahora cambio el saludo desde runnable!! :D");
				saludo.setSaludo( "hola" );
				/*try {
					//Thread.sleep( 5000 );
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}*/
			}
		});
		th.start();
		ThreadExtends te = new ThreadExtends( saludo );
		te.start();
		while( saludo.getI() < 2 ) {System.out.println();}
		System.out.println("el valor ahora es 2!!!!!!!1");
		System.out.println("el valor ahora es 2!!!!!!!1");
		System.out.println("el valor ahora es 2!!!!!!!1");
	}

}
