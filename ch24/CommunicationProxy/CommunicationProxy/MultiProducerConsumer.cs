using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;

namespace CommunicationProxy {
    public class MultiProducerConsumer<T> {
        Queue<T> queue_;
        public T Consume() {
            lock (queue_) {
                // If the queue is empty, wait for an item to be added
                // Note that this is a while loop, as we may be pulsed
                // but not wake up before another thread has come in and
                // consumed the newly added object. In that case, we'll
                // have to wait for another pulse.
                while (queue_.Count == 0) {
                    // This releases queue_, only reacquiring it
                    // after being woken up by a call to Pulse
                    Monitor.Wait(queue_);
                }
                return queue_.Dequeue();
            }
        }
        public void Produce(T t) {
            lock (queue_) {
                queue_.Enqueue(t);

                // We always need to pulse, even if the queue wasn't
                // empty before. Otherwise, if we add several items
                // in quick succession, we may only pulse once, waking
                // a single thread up, even if there are multiple threads
                // waiting for items.            
                Monitor.Pulse(queue_);
            }
        }
        
    }
}
