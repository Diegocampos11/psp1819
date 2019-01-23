import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.GregorianCalendar;

public class ServidorHora {
	public final static int PUERTO = 4321;
	public final static int HORA = 1;
	public final static int FECHA = 2;
	public final static int FECHA_HORA = 3;
	
	private static String obtenerHora( int tipo ) {
		String formato = "";
		switch( tipo ) {
			case HORA:
				formato = "HH:mm:ss";
				break;
			case FECHA:
				formato = "dd:MM:yyyy";
				break;
			case FECHA_HORA:
				formato = "dd:MM:yyyy - HH:mm:ss";
				break;
			default:
				System.out.println("no");
				break;
		}
		return ( new SimpleDateFormat( formato ).format( Calendar.getInstance().getTime() ) ) ;
	}

	public static void main(String[] args) {
		try {
			ServerSocket servSock = new ServerSocket( PUERTO );
			while ( true ) {
				System.out.println("Esperando clietne...");
				Socket socket = servSock.accept();//aceptamos la conexion, devuelve los nuevos puertos
				System.out.println("Cliente conectado");
				DataOutputStream salida = new DataOutputStream( socket.getOutputStream() );
				//Recibo que servicio quiere.
				DataInputStream entrada = new DataInputStream( socket.getInputStream() );				
				salida.writeUTF( obtenerHora( entrada.readInt() ) );
				System.out.println("Hora enviada...");
				entrada.close();
				salida.close();
				socket.close();
			}
			//servSock.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}

}
