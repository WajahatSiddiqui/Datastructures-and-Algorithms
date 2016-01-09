import java.util.ArrayList;
import java.util.Iterator;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.CopyOnWriteArrayList;


public class FailSafe {
	public static void main(String args[]) {
		// country and capital
		ConcurrentHashMap<String, String> mCity = new ConcurrentHashMap<String, String>();
		mCity.put("India", "New Delhi");
		mCity.put("USA", "New York");
		mCity.put("Australia", "Sydney");
		
		Iterator<String> iterator = mCity.keySet().iterator();
		while (iterator.hasNext()) {
			System.out.println(mCity.get(iterator.next()));
			// Modifying the collection
			mCity.put("Saudi", "Riyadh");
		}
		
		CopyOnWriteArrayList<String> mPhones = new CopyOnWriteArrayList<String>();
		mPhones.add("Samsung");
		mPhones.add("Motorola");
		mPhones.add("Iphone");
		
		Iterator<String> iteratorA = mPhones.iterator();
		
		while(iteratorA.hasNext()) {
			System.out.println(iteratorA.next());
			mPhones.add("Nokia");
		}
	}
}
