package equaloperator;

public class main {

	public static void main(String args[]) {
		String a = new String("a");
		String b = new String("a");
		System.out.println(a==b); // false
		System.out.println(a.equals(b)); //true
		
		Integer i1 = new Integer(10);
		Integer i2 = i1;
		
		System.out.println(i1 == i2); //true
		System.out.println(i1.equals(i2)); //true
		
		Integer i3 = new Integer(10);
		System.out.println(i2 == i3); //false
		System.out.println(i3.equals(i2)); //true
		
	}
}
