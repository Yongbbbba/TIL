using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

namespace ServerSocket
{
    class Program
    {
        static void Main(string[] args)
        {
            // stream - TCP, datagram - UDP
            Socket socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            IPEndPoint ep = new IPEndPoint(IPAddress.Parse("127.0.0.1"), 9999);  // 엔드포인트 만들어주고
            socket.Bind(ep);  // 소켓에 포트 바인딩해주기

            socket.Listen(10);  // 최대 10개의 연결을 받을 수 있게 지정

            // 클라이언트 소켓의 메시지를 서버 소켓에서 받아서 출력해줄 것임
            Socket clientSocket = socket.Accept();  // 클라이언트 쪽에서 서버 쪽의 연결 요청을 받으면 클라이언트 소켓을 만들어주기
            if (clientSocket.Connected)
                Console.WriteLine("클라이언트가 서버에 접속하였습니다.");

            // 지속적으로 클라이언트로부터 데이터를 받기 위하여 while문
            while (!Console.KeyAvailable)  // 콘솔에 키가 눌렸을 때 종료 
            {
                byte[] buff = new byte[2048];
                int n = clientSocket.Receive(buff);  // 클라이언트로부터 전송된 데이터를 받는다. 수신 버퍼에. 버퍼의 길이를 확인하기 위하여 n에 저장. 반환값이 바이트의 수임
                string result = Encoding.UTF8.GetString(buff, 0, n);  // 0번 인덱스부터 수신받은 데이터의 길이만큼 string을 출력해서 result에 넣어줌

                Console.WriteLine(result);
            }
        }
    }
}
