import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.net.UnknownHostException;

public class ParteB {
	public static void main(String[] args) throws UnknownHostException, IOException {
		Socket sock = new Socket( "localhost", 4567);
		System.out.println("HOla mundo desde cliente, I succeeded in connecting with you");
		DataInputStream entrada = new DataInputStream( sock.getInputStream() );//obtengo datos enviados 
		System.out.println(entrada.readUTF());//hago un read en un in y 
		System.out.println( "Local" +  sock.getLocalSocketAddress() );
		System.out.println( "Remoto" + sock.getRemoteSocketAddress() );
		sock.close();
	}
}
