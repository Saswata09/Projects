import java.net.*;
import java.io.*;
import java.util.*;

public class ClientThread2 extends Thread
{
    Socket sct;
    ClientThread2(Socket sk)
    {
        sct=sk;
    }
    public void run()
    {
        Scanner sc=new Scanner(System.in);
        try
        {
            while(true)
            {
                BufferedReader br=new BufferedReader(new InputStreamReader(sct.getInputStream()));
                System.out.println("Server : "+br.readLine());
            }
        }catch(Exception e){}
    }
}
