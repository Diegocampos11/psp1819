package classes;

import java.io.IOException;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.net.UnknownHostException;

public class Cliente {

	public static void main(String[] args) {
		try {
			Socket socket = new Socket( "localhost", Servidor.PUERTO );
			Mensaje m = new Mensaje( 123, "Mensaje 123" );
			ObjectOutputStream salida = new ObjectOutputStream( socket.getOutputStream() );
			salida.writeObject( m );
			System.out.println( "Mensaje enviado ='D" );
			salida.close();
			socket.close();
		} catch (UnknownHostException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
