
public class TestConcurrentLRUCache {
	
	public static void main(String args[]) {
		ConcurrentLRUCache<Integer, String> cache = new ConcurrentLRUCache<>(4);
		cache.put(1, "a");
		cache.put(2, "b");
		cache.put(3, "c");
		cache.put(1, "a");
		cache.put(4, "d");
		cache.put(5, "e");
		
		cache.printQueue();
		cache.printHashMap();
		cache.destroy();

	}

}
