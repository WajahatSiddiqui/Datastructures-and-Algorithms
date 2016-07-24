import java.util.LinkedHashMap;
import java.util.Map;


public class RunLengthEncoding {
	public static String encode(String str) {
		LinkedHashMap<Character, Integer> treemap = new LinkedHashMap<>();
		int len = str.length();
		char c;
		for (int i = 0; i < len; i++) {
			c = str.charAt(i);
			if (!treemap.containsKey(c)) {
				treemap.put(c, 1);
			} else {
				treemap.put(c,  treemap.get(c)+1);
			}
		}
		String encode = "";
		
		for (Map.Entry<Character, Integer> e : treemap.entrySet()) {
			encode = encode+e.getKey().toString()+e.getValue().toString();
		}
		return encode;
	}
	public static void main(String args[]) {
		System.out.println(encode("zwwwwccccbbbbaaaeee"));
	}
}
