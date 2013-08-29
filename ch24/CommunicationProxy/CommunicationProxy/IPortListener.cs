using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CommunicationProxy {
    public class DataArrivedEventArgs{
        public long Offset{get;set;}
        public byte[] Data{get;set;} 
    }
    public delegate void DataArrivedEventHandler(object sender, DataArrivedEventArgs e);
    public interface IPortListener {
        event DataArrivedEventHandler DataArrived;        
    }
}
