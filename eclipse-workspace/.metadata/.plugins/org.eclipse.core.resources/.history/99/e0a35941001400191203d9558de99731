import java.net.InetAddress;
import java.net.UnknownHostException;

public class Programa {
	public static void main( String[] args ) {
		try {
			InetAddress direccion = InetAddress.getLocalHost();
			InetAddress profesor = InetAddress.getByName("MV-Mint-Profesor.local");
			InetAddress face = InetAddress.getByName("www.facebook.com");
			InetAddress router = InetAddress.getByName("31.13.83.36");
			
			System.out.println(direccion);
			System.out.println(profesor);
			//System.out.println(face);
			System.out.println(router.getHostName());
			//System.out.println( face.getHostAddress() );
		} catch (UnknownHostException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
