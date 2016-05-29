import java.util.Iterator;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.ConcurrentLinkedQueue;

public class ConcurrentLRUCache<Key, Value> {

         private final int N; // Max. size of cache
         private ConcurrentHashMap<Key, Value> mHashMap;
         private ConcurrentLinkedQueue<Key> mQueue;


        public ConcurrentLRUCache(int size) {
                N = size;
                mHashMap = new ConcurrentHashMap<>(N);
                mQueue = new ConcurrentLinkedQueue<>();
        }

        public Value get(Key k) {
               return k != null ? mHashMap.get(k) : null;
        }

        public void put(Key k, Value v) {
               if (mHashMap.containsKey(k)) {
                      mQueue.remove(k);
               }

               if (mQueue.size() >= N) {
                    Key lruKey = mQueue.poll();
                    if (lruKey != null) mHashMap.remove(lruKey);
               }

              mHashMap.put(k, v);
              mQueue.add(k);
     }

    public void printQueue() {
             Iterator<Key> iterator  = mQueue.iterator();
             while (iterator.hasNext()) {
                    System.out.println(iterator.next());
             }
     }

     public void printHashMap() {
          for (Map.Entry<Key, Value> m : mHashMap.entrySet()) {
                System.out.println("Key = "+m.getKey()+" "+"Value = "+m.getValue());
           }
    }

    public void destroy() {
           mHashMap.clear();
           mQueue.clear();
           mHashMap = null;
           mQueue = null;
   }
}