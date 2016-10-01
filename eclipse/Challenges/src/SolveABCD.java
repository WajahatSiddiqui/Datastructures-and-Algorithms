import java.util.HashMap;

// find a^3 + b^3 == c^3 + d^3
public class SolveABCD {
	private static class Pair {
		int a, b;
		public Pair(int a, int b) {
			this.a = a;
			this.b = b;
		}
		public String toString() {
			return (a + " " + b);
		}
		
		@Override
		public boolean equals(Object obj) {
			Pair p = (Pair) obj;
			return (p.a == a || p.a == b)
				&& (p.b == a || p.b == b);
		}
		public boolean equals(int pa, int pb) {
			return (pa == a || pa == b)
				&& (pb == a || pb == b);
		}

	}
	public static int cube(int a) {
		return a*a*a;
	}
	public static void findPairs(int [] A) {
		HashMap<Integer, Pair> hashMap = new HashMap<>(A.length);
		int sum = 0;
		for (int i = 0; i < A.length; i++) {
			for (int j = i+1; j < A.length; j++) {
				sum = cube(A[i]) + cube(A[j]);
				if (!hashMap.containsKey(sum))
					hashMap.put(sum, new Pair(A[i], A[j]));
				else {
					Pair p = hashMap.get(sum);
					if (!p.equals(A[i], A[j]))
					System.out.println(A[i] + " " + A[j] + " " + hashMap.get(sum).toString());
				}
			}
		}
	}
	public static void main(String args[]) {
		int [] A = {1, 9, 12, 10, 2, 16, 9, 15, 3, 36, 27, 30};
		findPairs(A);
	}
}
