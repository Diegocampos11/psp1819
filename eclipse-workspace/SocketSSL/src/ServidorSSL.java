import java.io.DataOutputStream;
import java.io.IOException;

import javax.net.ssl.SSLServerSocket;
import javax.net.ssl.SSLServerSocketFactory;
import javax.net.ssl.SSLSocket;

public class ServidorSSL {
	
	public static final int PUERTO = 4321;

	public static void main(String[] args) {
		System.setProperty( "javax.net.ssl.keyStore", "/home/usuario/certificados/AlmacenServidor" );
		System.setProperty( "javax.net.ssl.keyStorePassword" , "123456");

		System.out.println("Servidor iniciando...");
		SSLServerSocketFactory fabricaServSocket = ( SSLServerSocketFactory ) SSLServerSocketFactory.getDefault(); 
		try {
			SSLServerSocket servSock = (SSLServerSocket) fabricaServSocket.createServerSocket( PUERTO );
			SSLSocket sock = (SSLSocket) servSock.accept();
			//cliente conectado
			System.out.println("Cliente conectado");
			DataOutputStream salida = new DataOutputStream( sock.getOutputStream() );
			salida.writeUTF("hola Clietne, conectado de manera segura :D");
			salida.close();
			sock.close();
			servSock.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
