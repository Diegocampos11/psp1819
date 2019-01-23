package classes;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.net.Socket;

public class GestionarConexion extends Thread {
	private Socket socket;

	public GestionarConexion(Socket socket) {
		super();
		this.socket = socket;
	}

	@Override
	public void run() {//no se puede lanzar throws por que no esta declarado asi en la clase Thread
		try {
			ObjectInputStream entrada = new ObjectInputStream( socket.getInputStream() );
			Object objetoRecibido = null;
			if ( (objetoRecibido = entrada.readObject()) instanceof Mensaje ) {
				Mensaje msj = (Mensaje) objetoRecibido;//posible error
				System.out.println( msj );
			}
			entrada.close();
			socket.close();
		} catch (IOException | ClassNotFoundException e) {
			System.out.println( "mensaje : " + e.getMessage() );
			e.printStackTrace();
		}
	}
}
