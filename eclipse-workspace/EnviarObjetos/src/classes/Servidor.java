package classes;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.net.ServerSocket;
import java.net.Socket;

public class Servidor {
	
	public static final int PUERTO = 4065;

	public static void main(String[] args) {
		try {
			ServerSocket servSock = new ServerSocket( PUERTO );
			System.out.println("Esperando cliente!!");
			while ( true ) {
				Socket socket = servSock.accept();
				GestionarConexion myt = new GestionarConexion( socket );
				myt.start();
			}
			/*{
				
				ObjectInputStream entrada = new ObjectInputStream( socket.getInputStream() );
				Object objetoRecibido = null;
				if ( (objetoRecibido = entrada.readObject()) instanceof Mensaje ) {
					Mensaje msj = (Mensaje) objetoRecibido;//posible error
					System.out.println( msj );
				}
				entrada.close();
			}*/
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
