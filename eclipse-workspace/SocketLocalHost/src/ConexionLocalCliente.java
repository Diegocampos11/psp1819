import java.io.DataInputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.net.Socket;
import java.net.SocketAddress;
import java.net.SocketException;

public class ConexionLocalCliente {

	public static void main(String[] args) throws SocketException {
		Socket sock = null;
		//DataInputStream dis = null;
		ObjectInputStream dis = null;
		try {
			sock = new Socket( "192.168.102.112", ConexionLocalServidor.PUERTO );
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		try {//Leer del servidor
			dis = new ObjectInputStream( sock.getInputStream() );
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		//String msg = "";		
		/*while ( ! msg.equals( ConexionLocalServidor.msgFinal ) )
			try {
				msg = dis.readUTF();//string que manda el servidor
				System.out.println( msg );
			} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}*/
		Mensaje msj = new Mensaje("");	
		while ( ! msj.getMsj().equals( ConexionLocalServidor.msgFinal ) ) {
			try {
				msj = (Mensaje) dis.readObject();//string que manda el servidor
				System.out.println( "Cliente"+ msj.getMsj() );
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (ClassNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		try {
			dis.close();
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
	}

}
