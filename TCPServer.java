import java.io.*;
import java.net.*;

public class TCPServer {
  public static void main(String[] args) {
    try {
      ServerSocket ss = new ServerSocket(6666);
      System.out.println("Server is waiting for a connection...");
      Socket s = ss.accept();
      System.out.println("Client connected!");
      DataInputStream dis = new DataInputStream(s.getInputStream());
      String clientMessage = dis.readUTF();
      System.out.println("Program Name: " + clientMessage);
      String clientMessage1 = dis.readUTF();
      System.out.println("Section: " + clientMessage1);
      String additionalData = dis.readUTF();
      System.out.println("Message Recived: " + additionalData);
      dis.close();
      s.close();
      ss.close();
    } catch (Exception e) {
      System.out.println(e);
    }
  }
}