using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Net;
using System.Net.Sockets;
using System.Threading;
namespace CommunicationProxy {
    public class Client {
        Socket socket_;
        ProxyServer server_;
        SingleConsumerQueue<byte[]> send_items_ =  new SingleConsumerQueue<byte[]>();
        private bool end_ = false;
        public event EventHandler ClientDisconnectd;
        public event EventHandler ClientConnected;
        
        public void DataArrived(byte[] data) {
            send_items_.Produce(data);
            // todo handle history reading
        }

        private void OnDisconnected() {
            lock(this) {
                if (ClientDisconnectd != null) {
                    ClientDisconnectd(this, new EventArgs());
                }
            }
        }
        private void OnConnect() {
            lock (this) {
                if (ClientConnected != null) {
                    ClientConnected(this, new EventArgs());
                }
            }
        }

        private void Terminate() {
            end_ = true;
            send_items_.Stop();
        }

        void SendRoutine() {
            try {
                byte[] bytes;
                while (send_items_.Consume(out bytes)) {                    
                    while (!end_) {
                        socket_.Poll(1000000, SelectMode.SelectWrite);
                    }
                    socket_.Send(bytes);
                    
                }
            } finally {
                Terminate();
            }
        }

        byte[] ReceiveExactly(int bytes_to_read) {
            byte[] return_value = new byte[0];
            int remaining_count = bytes_to_read;
            while (remaining_count > 0) {
                while (true) {
                    if (socket_.Poll(1000000, SelectMode.SelectRead)) {
                        break;
                    }
                }
                byte[] buffer = new byte[socket_.Available];
                int readed = socket_.Receive(buffer);
                remaining_count -= readed;

            }
            return return_value;
        }

        byte[] ReceiveMessage() {
            byte[] count = ReceiveExactly(4);
            int length = count[3];
            length = length * 255 + count[2];
            length = length * 255 + count[1];
            length = length * 255 + count[0];
            return ReceiveExactly(length);

        }
        void HandleMessage(byte[] message) {
            if (message[0] == 1) {
                OnConnect();
                return;
                // just connect
            }
            string str = Encoding.UTF8.GetString(message);

        }

        void ReceiveRoutine() {
            try {
                while (!end_) {
                    HandleMessage(ReceiveMessage());
                }
            } finally {
                OnDisconnected();
            }
        }

        Thread sending_thread_ = null, receiving_thread_ = null;
        public Client(Socket socket, ProxyServer server) {
            socket_ = socket;
            server_ = server;
            sending_thread_ = new Thread(new ThreadStart(SendRoutine)){IsBackground = true};
            receiving_thread_ = new Thread(new ThreadStart(ReceiveRoutine)){IsBackground = true};
            receiving_thread_.Start();
            sending_thread_.Start();
        }
        

    }
}
