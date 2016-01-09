import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;


public class FailFast {
	public static void main(String args[]) {
		// country and capital
		HashMap<String, String> mCity = new HashMap<String, String>();
		mCity.put("India", "New Delhi");
		mCity.put("USA", "New York");
		mCity.put("Australia", "Sydney");
		
		Iterator<String> iterator = mCity.keySet().iterator();
		while (iterator.hasNext()) {
			System.out.println(mCity.get(iterator.next()));
			// Modifying the collection
			//mCity.put("Saudi", "Riyadh");
		}
		
		ArrayList<String> mPhones = new ArrayList<String>();
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
