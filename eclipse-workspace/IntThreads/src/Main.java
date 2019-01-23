
public class Main {

	public static void main(String[] args) {
		NumInDes num = new NumInDes(1);
		//while( num.getNum() == 1 ) {
			System.out.println( num.getNum() );
			Thread th1 = new Thread( new Runnable() {			
				@Override
				public void run() {
					for (int i = 0; i < 1000; i++) {
						synchronized (num) {
							num.setNum( num.getNum() + 1 );
						}
					}
				}
			} );
			th1.start();
			Thread th2 = new Thread( new Runnable() {			
				@Override
				public void run() {
					for (int i = 0; i < 1000; i++) {
						synchronized (num) {
							num.setNum( num.getNum() - 1 );
						}
					}
				}
			} );
			th2.start();
			//System.out.println( num.getNum() );
			try {
				Thread.sleep(500);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		//}
		System.out.println( "foin"+num.getNum() );
	}

}
