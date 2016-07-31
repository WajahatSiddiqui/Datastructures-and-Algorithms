import java.util.Scanner;


public class ValidatingIPV4 {
	public static boolean isValidate(String ip) {
		if (ip == null || ip.isEmpty()) return false;
		String tokenize[] = ip.split("\\.");
		// verify 4 dots
		if (tokenize.length < 4) return false;
		
		String tokens;
		int number;
		for (int i = 0; i < tokenize.length; i++) {
			tokens = tokenize[i];
			// verify each token is a number
			try {
				number = Integer.parseInt(tokens);
			} catch (NumberFormatException e) {
				return false;
			}
			
			// number should be in the range of 0-255
			if (number < 0 || number > 255) return false;
		}
		return true;		
	}
	public static void main(String args[]) {	
		//String ip1 = "127.0.0.1";
		Scanner scanner = new Scanner(System.in);
		String ip1 = scanner.next();
		if (isValidate(ip1)) {
			System.out.println(ip1+ " is Valid");
		} else {
			System.out.println(ip1+ " is InValid");
		}
		scanner.close();
	}
}
