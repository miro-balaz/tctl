using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
namespace CommunicationProxy {
    class SingleConsumerQueue<T> {
        Queue<T> queue_ = new Queue<T>();
        ManualResetEvent event_ = new ManualResetEvent(false);
        ManualResetEvent terminate_event_ = new ManualResetEvent(false);
        ManualResetEvent[] events_;
        /// <summary>
        /// Cancels processing of events, further calls to Consube will return null, and will not block
        /// no item will be added to queue and it will be cleared
        /// 
        /// </summary>
        public void Stop() {
            terminate_event_.Set();
            lock (queue_) {
                queue_.Clear();
            }
        }
        public SingleConsumerQueue() {
            events_= new ManualResetEvent[]{event_, terminate_event_};
        }
        // returns false if queue, is shuted down
        public bool Consume(out T t) {
            System.Threading.WaitHandle.WaitAny(events_);
            if (terminate_event_.WaitOne(0)) {
                t=default(T);
                return false;
            }
            T return_value;
            lock (queue_) {
                return_value = queue_.Dequeue();
                if (queue_.Count == 0) {
                    event_.Reset();
                }
            }
            t = return_value;
            return true;
            
        }
        public void Produce(T t) {
            lock (queue_) {
                if (!terminate_event_.WaitOne(0)) {
                    queue_.Enqueue(t);
                    event_.Set();
                }
            }

        }
    }
}
