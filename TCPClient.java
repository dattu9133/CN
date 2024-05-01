import java.io.*;
import java.net.*;
import java.util.Scanner;

public class TCPClient {
  public static void main(String[] args) {
    try {
      Socket s = new Socket("localhost", 6666);
      DataOutputStream dout = new DataOutputStream(s.getOutputStream());
      dout.writeUTF("Server & Client");
      Scanner scanner = new Scanner(System.in);
      System.out.print("Enter your section: ");
      String userMessage = scanner.nextLine();
      dout.writeUTF(userMessage);
      dout.flush();
      String additionalData = "Hi from " + userMessage;
      dout.writeUTF(additionalData);
      dout.flush();
      dout.close();
      scanner.close();
    } catch (Exception e) {
      System.out.println(e);
    }
  }
}
