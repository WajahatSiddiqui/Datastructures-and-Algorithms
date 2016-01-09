import java.util.HashMap;
import java.util.Scanner;

/**
 * Finds first non repeating character
 * eg: stress o/p: t
 * @author mohammed
 *
 */
public class FirstNonRepeatingCharacter {
	public static void main(String args[]) {
		System.out.print("Enter the word: ");
		Scanner scanner = new Scanner(System.in);
		String str = scanner.nextLine();
		System.out.println("The first non repeating character is: " +
		getNonRepeatingCharacter(str));
	}

	private static Character getNonRepeatingCharacter(String str) {
		HashMap<Character, Integer> hashMap = new HashMap<Character, Integer>();
		Character c;
		for (int i = 0; i < str.length(); i++) {
			c = str.charAt(i);
			if (hashMap.containsKey(c))
				hashMap.put(c, hashMap.get(c)+1);
			else
				hashMap.put(c, 1);
		}
		for (int i  = 0; i < hashMap.size(); i++) {
			c = str.charAt(i);
			if (hashMap.get(c) == 1) return c; 
		}
		return null;
	}
}
