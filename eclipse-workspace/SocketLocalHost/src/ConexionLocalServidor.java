import java.io.DataOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

public class ConexionLocalServidor {

	public static final int PUERTO = 4321;//por encima del 1024, estan reservados para servicios concretos
	//SI NO SE PONE NADA ES VISIBLE PARA TODO EL PAQUETE
	public static final String msgFinal = "FIN";
	
	public static void main(String[] args) {
		ServerSocket servSock = null;
		Socket sock = null;
		ObjectOutputStream dos = null;//It was datainput
		try {
			servSock = new ServerSocket( PUERTO );
		} catch (IOException e) {//por exclusividad puede estar ocupado
			e.printStackTrace();
			System.out.println("No se ha podido abrir el puerto");
		}
		try {
			sock = servSock.accept();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		try {
			dos = new ObjectOutputStream( sock.getOutputStream() );
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		System.out.println("Cliente conectado! " + sock.getInetAddress() );//direccion ip del ciente
		/*String input = "";
		while( ! input.equals( msgFinal ) ) {
			try {
				Scanner s = new Scanner( System.in );
				input = s.nextLine();
				dos.writeUTF( input );
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}*/
		Mensaje msj = new Mensaje("");
		while( ! msj.getMsj().equals( msgFinal ) ) {
			try {
				Scanner s = new Scanner( System.in );
				msj.setMsj( s.nextLine() );
				dos.writeObject( msj );
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		try {
			dos.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		try {
			sock.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		try {
			servSock.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
