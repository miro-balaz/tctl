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
        List<Client> clients_= new List<Client>();
        List<Client> connected_clients_ = new List<Client>();
        void AcceptLoop() {
            while (true) {
                Socket socket = server_socket_.Accept();
                Client client = new Client(sockt, this);
                client.ClientConnected += new ClientConnectedHandler(client_ClientConnected);
                client.ClientDisconnectd += new EventHandler(client_ClientDisconnectd);
                lock (clients_) {
                    clients_.Add(client_);
                }


            }
        }

        void client_ClientConnected(object sender, ClientConnectedEventArgs e) {
            lock (clients_){
                clients_.Add((Client)sender);
            }
        }

        void client_ClientDisconnectd(object sender, EventArgs e) {
            lock (clients_) {
                clients_.Remove((Client)sender);
            }
            lock (connected_clients_) {
                connected_clients_.Remove((Client)sender);
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
        public void Start(IPortListener listener) {
            listener.DataArrived += new DataArrivedEventHandler(listener_DataArrived);

        }

        void listener_DataArrived(object sender, DataArrivedEventArgs e) {
            lock (connected_clients_) {
                foreach (Client client in connected_clients_) {
                    client.DataArrived(e.Data);  
                }
            }
        }
    }
}
