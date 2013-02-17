using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CommunicationProxy {
    public class DataArrivedEventArgs{
        long Offset{get;set;}
        byte[] Data{get;set;} 
    }
    public delegate void DataArrivedEventHandler(object sender, DataArrivedEventArgs e);
    public interface IPortListener {
        event DataArrivedEventHandler DataArrived;
        
    }
}
