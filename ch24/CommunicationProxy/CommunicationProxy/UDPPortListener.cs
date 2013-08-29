using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Net.Sockets;
using System.Net;
using System.Threading;
   

namespace CommunicationProxy {
    /// <summary>
    /// saves entire incoming and outcoming communication to file (with additional debug info)
    /// on file raw, second debug
    /// </summary>
    public class UDPPortListener:IPortListener {

        #region IPortListener Members

        public event DataArrivedEventHandler DataArrived;

        #endregion
        private void OndataArrived(byte[] data) {
            if (DataArrived != null) DataArrived(this, new DataArrivedEventArgs() { Data = data });
        }
        public Start() {
        }
    }
}
