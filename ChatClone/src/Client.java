import java.io.*;
import java.net.*;
import java.util.Scanner;

public class Client
{
    public static void main(String[] args) throws Exception{
        Socket clientSocket=new Socket("localhost",6789);
        ClientThread1 t1=new ClientThread1(clientSocket);
        ClientThread2 t2=new ClientThread2(clientSocket);
        t1.start();
        t2.start();
    }
}
