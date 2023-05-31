import java.net.*;

public class Server
{
    public static void main(String[] args) throws Exception {
        ServerSocket skt=new ServerSocket(6789);
        System.out.println("Server Running");
        while(true)
        {
            Socket conn=skt.accept();
            ServerThread1 t1=new ServerThread1(conn);
            ServerThread2 t2=new ServerThread2(conn);
            t1.start();
            t2.start();
        }
    }
}
