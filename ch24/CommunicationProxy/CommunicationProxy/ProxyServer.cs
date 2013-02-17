using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Net.Sockets;
using System.Net;
using System.Threading;
namespace CommunicationProxy {
    public class ProxyServer {
        int ListenPort {
            get;
            set;
        }
        Socket server_socket_;
        public ProxyServer() {
            server_socket_ = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
        }
        Thread accept_thread_;
        void AcceptLoop() {
            while (true) {
                Socket socket = server_socket_.Accept();

            }
        }
        public void StartListenning() {
            // bind the listening socket to the port
            //IPAddress hostIP = (Dns.Resolve(IPAddress.Any.ToString())).AddressList[0];
            IPEndPoint ep = new IPEndPoint(IPAddress.Any, ListenPort);
            server_socket_.Bind(ep); 
            server_socket_.Listen(10);
            accept_thread_ = new Thread(new ThreadStart(AcceptLoop)) { IsBackground = true };
            accept_thread_.Start();


            
        }
    }
}
