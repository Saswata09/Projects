import java.net.*;
import java.io.*;
import java.util.*;

public class ServerThread1 extends Thread
{
    Socket sct;
    ServerThread1(Socket sk)
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
                DataOutputStream out=new DataOutputStream(sct.getOutputStream());
                String s=sc.nextLine();
                System.out.println("Server : "+s);
                out.writeBytes(s+"\n");
            }
        }catch(Exception e){}
    }
}
