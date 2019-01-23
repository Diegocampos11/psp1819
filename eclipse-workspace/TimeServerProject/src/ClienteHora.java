import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Scanner;

public class ClienteHora {

	public static void main(String[] args) {
		try {
			Socket socket = new Socket( "localhost", ServidorHora.PUERTO );
			System.out.println("Conexion establecida...");
			System.out.println("Conectado con:  " + socket.getRemoteSocketAddress() );
			DataOutputStream salida = new DataOutputStream( socket.getOutputStream() );
			imprimirMenu();
			int opcion = new Scanner( System.in ).nextInt();
			while ( opcion < ServidorHora.HORA || opcion > ServidorHora.FECHA_HORA ) {
				System.out.println("Opción incorrecta! \n\n" + imprimirMenu() );
				imprimirMenu();
				opcion = new Scanner( System.in ).nextInt();
			}
			salida.writeInt( opcion );
			DataInputStream entrada = new DataInputStream( socket.getInputStream() );
			System.out.println("Hora recibida...");
			
			System.out.println( entrada.readUTF() );
			entrada.close();
			socket.close();
		} catch (UnknownHostException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	private static String imprimirMenu() {
		System.out.println("Seleccione una opción:\t");
		System.out.println("\t" + ServidorHora.HORA + "-Hora.");
		System.out.println("\t" + ServidorHora.FECHA + "-Fecha.");
		System.out.println("\t" + ServidorHora.FECHA_HORA + "-Fecha y Hora.");
		return null;
	}

}
