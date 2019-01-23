import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class ParteA {

	public static void main(String[] args) throws IOException {
		ServerSocket servSock = new ServerSocket( 4567 );
		System.out.println("Esperando");
		Socket sock = servSock.accept();//Esperar una conexcion entrante
		servSock.close();//una vez ya hecho el accept puedo cerrar el serversock
		DataOutputStream salida = new DataOutputStream( sock.getOutputStream() );//de A a B
		salida.writeUTF("Saludo Diego Campos desde parte A");//en el out haces un write, salida de mi programa
		System.out.println( "Local " +  sock.getLocalSocketAddress() );
		System.out.println( "Remoto" + sock.getRemoteSocketAddress() );
		sock.close();
	}

}
