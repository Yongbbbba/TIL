using System;
using System.Net.Sockets;
using System.Text;

namespace ClientSocket
{
    class Program
    {
        static void Main(string[] args)
        {
            Socket socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            socket.Connect("127.0.0.1", 9999);   // 서버와 연결

            if (socket.Connected)
            {
                Console.WriteLine("서버에 연결 되었습니다.");
            }

            string message = string.Empty;
            
            while ((message = Console.ReadLine()) != "x")
            {
                byte[] buff = Encoding.UTF8.GetBytes(message);  // 입력으로 받은 메시지를 UTF8으로 인코딩(바이트값으로)
                socket.Send(buff);  // 송신버퍼를 소켓에 보내게 된다. 그런 다음 소켓에서 서버로 보냄.

            }
        }
    }
}
