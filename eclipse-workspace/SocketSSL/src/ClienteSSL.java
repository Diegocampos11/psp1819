import java.io.DataInputStream;
import java.io.IOException;
<<<<<<< HEAD
=======

import javax.net.ssl.SSLSession;
>>>>>>> 16ea37e2ee9d5a01c9c1d704af5a5fdddd9c272a
import javax.net.ssl.SSLSocket;
import javax.net.ssl.SSLSocketFactory;

public class ClienteSSL {

	public static void main(String[] args) {
		System.setProperty( "javax.net.ssl.trustStore", "/home/usuario/certificados/AlmacenCliente" );
		System.setProperty( "javax.net.ssl.trustStorePassword" , "987456");
		
		SSLSocketFactory fabricaSSLSocket = ( SSLSocketFactory ) SSLSocketFactory.getDefault(); 
		try {
			SSLSocket sock = (SSLSocket) fabricaSSLSocket.createSocket( "127.0.0.1", ServidorSSL.PUERTO );
			//cliente conectado
<<<<<<< HEAD
			System.out.println("Cliente conectado");
=======
			System.out.println("Me he conectado");
			
			SSLSession sesionSSL = sock.getSession();
			System.out.println( "Host"+ sesionSSL.getPeerHost() );
			System.out.println( "Cifrado"+ sesionSSL.getCipherSuite() );
			System.out.println( "Protocolo"+ sesionSSL.getProtocol() );
			System.out.println( "Id sesion"+ sesionSSL.getId() );
			System.out.println( "hora Sesion"+ sesionSSL.getCreationTime() );
>>>>>>> 16ea37e2ee9d5a01c9c1d704af5a5fdddd9c272a
			DataInputStream entrada = new DataInputStream( sock.getInputStream() );
			String saludo = entrada.readUTF();
			System.out.println( saludo );
			entrada.close();
			sock.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
