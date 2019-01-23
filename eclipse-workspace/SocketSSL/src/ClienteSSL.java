import java.io.DataInputStream;
import java.io.IOException;
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
			System.out.println("Cliente conectado");
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
