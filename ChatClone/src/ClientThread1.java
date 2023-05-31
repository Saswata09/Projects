import java.net.*;
import java.io.*;
import java.util.*;

public class ClientThread1 extends Thread
{
    Socket sct;
    ClientThread1(Socket sk)
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
                System.out.println("Client : "+s);
                out.writeBytes(s+"\n");
            }
        }catch(Exception e){}
    }
}
